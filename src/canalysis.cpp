/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.1
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "canalysis.h"
#include "reformat.h"
#include "layer.h"
#include "writer.h"

namespace canalysis {

std::istream& operator>>(std::istream& file, Reformat& ref)
{
   ref.getColumn(file);
   return file;
}

void Canalysis::exportCSVData(const std::string csv_file,
                              int lat_column, int long_column)
{
   Reformat ref;
   std::ifstream if_csv(csv_file);
   if (!if_csv.is_open()){
      std::cout << "Error: Could not open CSV file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
      while (if_csv >> ref){
         std::string lat_c = ref[lat_column];
         std::string long_c = ref[long_column];
         if (lat_c.empty() || long_c.empty()){
            std::cout << "Error: One or more columns are empty." << std::endl;
         }
         std::ofstream exported_lat("../data/latitudes.txt");
         if (!exported_lat.is_open()){
            std::cout << "Error: Could not write latitudes file." << std::endl;
            exit(EXIT_FAILURE);
         } else {
            exported_lat << lat_c << std::endl;
         }
         std::ofstream exported_long("../data/longitudes.txt");
         if (!exported_long.is_open()){
            std::cout << "Error: Could not write longitudes file." << std::endl;
            exit(EXIT_FAILURE);
         } else {
            exported_long << long_c << std::endl;
         }
      }
   }
}

void Canalysis::crimePercentage(const std::string crime_file)
{
   std::ifstream if_crime(crime_file);
   if (!if_crime.is_open()){
      std::cout << "Error: Could not open crime file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
      while (if_crime >> temp_crime){
         crime_values.push_back(temp_crime);
      }
      //float percent = value / crime_values.size() * 10;
      //if (ceil(percent) == 0) {
      //   printf("%s - %.0f\n", crime_values.c_str(), percent);
      //}
      //else {
      //   printf("%s - %.2f\n", crime_values.c_str(), percent);
      //}
   }
}

std::tuple<int, double, double, int> Canalysis::predictedLocations()
{
   Layer layer(lat_values, long_values);
   layer.reduceLatValues();
   auto cluster = layer.dbscanCluster(5, 20);
   return std::make_tuple(std::get<0>(cluster), std::get<1>(cluster),
                          std::get<2>(cluster), std::get<3>(cluster));
}

void Canalysis::model(const std::string lat_file, const std::string long_file)
{
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
   auto prediction = predictedLocations();
   Writer writer(PREDICTION_FILE);
   writer.exportData(std::get<0>(prediction), std::get<1>(prediction),
                     std::get<2>(prediction), std::get<3>(prediction));
}

} // canalysis namespace
