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
#include "utils.h"

namespace canalysis {

std::istream& operator>>(std::istream& file, Reformat& reform)
{
   reform.getColumn(file);
   return file;
}

void Canalysis::exportCSVData(const std::string csv_file,
                              int lat_column, int long_column)
{
   Reformat reform;
   std::ifstream if_csv(csv_file);
   if (!if_csv.is_open()){
      std::cout << "Error: Could not open CSV file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
      while (if_csv >> reform){
         std::string lat_c = reform[lat_column];
         std::string long_c = reform[long_column];
         if (lat_c.empty() || long_c.empty()){
            std::cout << "Error: One or more columns are empty." << std::endl;
         }
      }
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
   Writer writer(PFILE);
   writer.exportData(std::get<0>(prediction), std::get<1>(prediction),
                     std::get<2>(prediction), std::get<3>(prediction));
}

} // canalysis namespace
