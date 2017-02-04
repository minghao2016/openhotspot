/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.4
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "hotspot.h"
#include "hs_reformat.h"
#include "hs_model.h"
#include "hs_types.h"

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
      std::printf("ERROR: Could not open CSV file.\n");
      exit(EXIT_FAILURE);
   } else {
      while (if_csv >> reformat){
         std::string crime_c = reformat[crime_column];
         std::string date_c = reformat[date_column];
         std::string lat_c = reformat[lat_column];
         std::string long_c = reformat[long_column];
         if (crime_c.empty() || date_c.empty() || lat_c.empty() || long_c.empty()){
            std::printf("ERROR: One or more columns are empty.\n");
         }
         std::ofstream exported_crimes(CRIMES_FILE, std::ofstream::out | std::ofstream::app);
         if (!exported_crimes.is_open()){
            std::printf("ERROR: Could not write crimes file.\n");
            exit(EXIT_FAILURE);
         } else {
            exported_crimes << crime_c << std::endl;
         }
         std::ofstream exported_dates(DATES_FILE, std::ofstream::out | std::ofstream::app);
         if (!exported_dates.is_open()){
            std::printf("ERROR: Could not write dates file.\n");
            exit(EXIT_FAILURE);
         } else {
            exported_dates << date_c << std::endl;
         }
         std::ofstream exported_lat(LATITUDES_FILE, std::ofstream::out | std::ofstream::app);
         if (!exported_lat.is_open()){
            std::printf("ERROR: Could not write latitudes file.\n");
            exit(EXIT_FAILURE);
         } else {
            exported_lat << lat_c << std::endl;
         }
         std::ofstream exported_long(LONGITUDES_FILE, std::ofstream::out | std::ofstream::app);
         if (!exported_long.is_open()){
            std::printf("ERROR: Could not write longitudes file.\n");
            exit(EXIT_FAILURE);
         } else {
            exported_long << long_c << std::endl;
         }
      }
   }
}

void HotSpot::printCrimeRate(const std::string& crimes_file)
{
   std::ifstream if_crime(crimes_file);
   if (!if_crime.is_open()){
      std::printf("ERROR: Could not open crime file.\n");
      exit(EXIT_FAILURE);
   } else {
      while (if_crime >> temp_crime){
         crime_values.push_back(temp_crime);
      }
      std::cout << "Crime Percentages" << std::endl;
      std::cout << "-----------------" << std::endl;
      std::set<std::string> unique_crimes(crime_values.begin(), crime_values.end());
      for (auto crimes : unique_crimes){
         int crime_vectors = count(crime_values.begin(), crime_values.end(), crimes);
         double percentage = (double)crime_vectors / (double)crime_values.size() * 100;
         std::cout << std::setprecision(3) << crimes << ": " << percentage << "%" << std::endl;
      }
   }
}

PredictionData HotSpot::prediction(float eps, unsigned int min_pts, const std::string& dist_metric)
{
   std::vector<Coordinates*> cluster_coordinates;
   Coordinates* coordinates = new Coordinates;
   coordinates->lat_pts = lat_values;
   coordinates->long_pts = long_values;
   cluster_coordinates.push_back(coordinates);

   DBSCAN clusters(cluster_coordinates);
   ClusterWeights cluster_weights;
   cluster_weights.eps = eps;
   cluster_weights.min_pts = min_pts;
   cluster_weights.dist_metric = dist_metric;
   std::vector<Coordinates*> dbscan_results = clusters.dbscan(cluster_weights);

   //Model model(dbscan_results);
   //ModelWeights model_weights;
   //model_weights.crime_dates = date_values;
   //model_weights.crime_types = crime_values;

   PredictionData p_data;
   //p_data.core_lat = dbscan_results[0]->lat_pts;
   //p_data.core_long = dbscan_results[0]->long_pts;
   std::vector<uint32_t> noise_pts = clusters.noise_pts();
   //for (unsigned int i = 0; i < coordinates->lat_pts.size(); i++){
   //   p_data.noise_lat = coordinates->lat_pts[noise_pts[i]];
   //   p_data.noise_long = coordinates->long_pts[noise_pts[i]];
   //}
   return p_data;
}

void HotSpot::launchWebClient()
{
}

void HotSpot::loadModel(const std::string& dates_file, const std::string& lat_file,
                        const std::string& long_file, float eps, unsigned int min_pts,
                        const std::string& dist_metric)
{
   std::ifstream if_dates(dates_file);
   if (!if_dates.is_open()){
      std::printf("ERROR: Could not open dates file.\n");
      exit(EXIT_FAILURE);
   } else {
      while (if_dates >> temp_dates){
         date_values.push_back(temp_dates);
      }
   }
   std::ifstream if_lat(lat_file);
   if (!if_lat.is_open()){
      std::printf("ERROR: Could not open latitude file.\n");
      exit(EXIT_FAILURE);
   } else {
      while (if_lat >> temp_lat){
         lat_values.push_back(temp_lat);
      }
   }
   std::ifstream if_long(long_file);
   if (!if_long.is_open()){
      std::printf("ERROR: Could not open longitude file.\n");
      exit(EXIT_FAILURE);
   } else {
      while (if_long >> temp_long){
         long_values.push_back(temp_long);
      }
   }
   PredictionData predicted_coordinates = prediction(eps, min_pts, dist_metric);
   std::printf("INFO: Saving predicted cluster to '%s'.\n", PREDICTION_FILE);
   //Export csv_export(PREDICTION_FILE);
   //csv_export.exportData(predicted_coordinates);
}

} // hotspot namespace
