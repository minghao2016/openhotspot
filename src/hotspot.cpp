/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.3
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "hotspot.h"
#include "hs_reformat.h"
#include "hs_model.h"
#include "hs_export.h"

#include "http/hs_client.h"

#include "version.h"

namespace hotspot {

std::istream& operator>>(std::istream& file, Reformat& reformat)
{
   reformat.getColumn(file);
   return file;
}

void HotSpot::reformatCSVFile(const std::string& csv_file, unsigned int crime_column,
                              unsigned int date_column, unsigned int lat_column,
                              unsigned int long_column)
{
   Reformat reformat;
   std::ifstream if_csv(csv_file);
   if (!if_csv.is_open()){
      std::cout << "Error: Could not open CSV file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
      while (if_csv >> reformat){
         std::string crime_c = reformat[crime_column];
         std::string date_c = reformat[date_column];
         std::string lat_c = reformat[lat_column];
         std::string long_c = reformat[long_column];
         if (crime_c.empty() || date_c.empty() || lat_c.empty() || long_c.empty()){
            std::cout << "Error: One or more columns are empty." << std::endl;
         }
         std::ofstream exported_crimes(CRIMES_FILE, std::ofstream::out | std::ofstream::app);
         if (!exported_crimes.is_open()){
            std::cout << "Error: Could not write crimes file." << std::endl;
            exit(EXIT_FAILURE);
         } else {
            exported_crimes << crime_c << std::endl;
         }
         std::ofstream exported_dates(DATES_FILE, std::ofstream::out | std::ofstream::app);
         if (!exported_dates.is_open()){
            std::cout << "Error: Could not write dates file." << std::endl;
            exit(EXIT_FAILURE);
         } else {
            exported_dates << date_c << std::endl;
         }
         std::ofstream exported_lat(LATITUDES_FILE, std::ofstream::out | std::ofstream::app);
         if (!exported_lat.is_open()){
            std::cout << "Error: Could not write latitudes file." << std::endl;
            exit(EXIT_FAILURE);
         } else {
            exported_lat << lat_c << std::endl;
         }
         std::ofstream exported_long(LONGITUDES_FILE, std::ofstream::out | std::ofstream::app);
         if (!exported_long.is_open()){
            std::cout << "Error: Could not write longitudes file." << std::endl;
            exit(EXIT_FAILURE);
         } else {
            exported_long << long_c << std::endl;
         }
      }
   }
}

void HotSpot::crimeRate(const std::string& crime_file)
{
   std::ifstream if_crime(crime_file);
   if (!if_crime.is_open()){
      std::cout << "Error: Could not open crime file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
      while (if_crime >> temp_crime){
         crime_values.push_back(temp_crime);
      }
      /*float percent = value / crime_values.size() * 10;
      if (ceil(percent) == 0) {
         for (unsigned int i = 0; i < crime_values.size(); i++){
            printf("%s - %.0f\n", crime_values[i].c_str(), percent);
         }
      }
      else {
         for (unsigned int i = 0; i < crime_values.size(); i++){
            printf("%s - %.2f\n", crime_values[i].c_str(), percent);
         }
      }*/
   }
}

utils_tuple HotSpot::predictedClusters(double eps, unsigned int min_pts, const std::string& dist_metric)
{
   std::vector<Coordinates> coordinates;
   coordinates.push_back(Coordinates());
   coordinates.push_back(Coordinates());
   coordinates[0].lat_pts = lat_values;
   coordinates[1].long_pts = long_values;
   //coordinates.reduceLatValues(10);
   //coordinates.reduceLongValues(10);
   DBSCAN clusters(coordinates, eps, min_pts, dist_metric);
   utils_tuple dbscan_results = clusters.dbscan();
   //for (unsigned int i = 0; i < clusters.size(); i++){
   //}
   return std::make_tuple(std::get<0>(dbscan_results), std::get<1>(dbscan_results),
                          std::get<2>(dbscan_results), std::get<3>(dbscan_results));
}

utils_pair HotSpot::predictedCoordinates()
{
}

void HotSpot::launchWebClient()
{
}

void HotSpot::loadModel(const std::string& dates_file, const std::string& lat_file,
                        const std::string& long_file, double eps, unsigned int min_pts,
                        const std::string& dist_metric)
{
   Export expt(PREDICTION_FILE);
   std::ifstream if_dates(dates_file);
   if (!if_dates.is_open()){
      std::cout << "Error: Could not open dates file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
      while (if_dates >> temp_dates){
         date_values.push_back(temp_dates);
      }
   }
   std::ifstream if_lat(lat_file);
   if (!if_lat.is_open()){
      std::cout << "Error: Could not open latitude file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
      while (if_lat >> temp_lat){
         lat_values.push_back(temp_lat);
      }
   }
   std::ifstream if_long(long_file);
   if (!if_long.is_open()){
      std::cout << "Error: Could not open longitude file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
      while (if_long >> temp_long){
         long_values.push_back(temp_long);
      }
   }
   utils_tuple predicted_clusters = predictedClusters(eps, min_pts, dist_metric);
   //expt.exportPredictedData(std::get<0>(prediction), std::get<1>(prediction),
   //                         std::get<2>(prediction), std::get<3>(prediction));
}

} // hotspot namespace
