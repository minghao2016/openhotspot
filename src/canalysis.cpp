/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "canalysis.h"
#include "layer.h"
#include "writer.h"
#include "utils.h"

#include <boost/tokenizer.hpp>

namespace canalysis {

//std::string Parser::operator[](unsigned int column)
//{
//   return file_data[column];
//}

void Canalysis::reformat(const std::string csv_file, int lat_column, int long_colum)
{
   std::ifstream if_csv(csv_file);
   if (!if_csv.is_open()){
      std::cout << "Error: Could not open CSV file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
      csv_data.clear();
      std::getline(if_csv, row);
      std::istringstream stream(row);
      while (std::getline(stream, line)){
         boost::escaped_list_separator<char> delimiter;
         boost::tokenizer<boost::escaped_list_separator<char> > token(line, delimiter);
         for (auto t : token){
            csv_data.push_back(t);
         }
      }
   }
}

std::tuple<int, double, double, int> Canalysis::predictedLocations()
{
   Layer layer;
   layer.reduceLatValues();
   auto cluster = layer.dbscanCluster(5, 20);
   return std::make_tuple(std::get<0>(cluster), std::get<1>(cluster),
                          std::get<2>(cluster), std::get<3>(cluster));
}

//std::istream& operator>>(std::istream& file, Parser& parser)
//{
//   parser.getColumnFields(file);
//   return file;
//}

void Canalysis::model(const std::string lat_file, const std::string long_file)
{
   std::ifstream if_lat(lat_file);
   if (!if_lat.is_open()){
      std::cout << "Error: Could not open latitude file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
      while (!if_lat.eof()){
         if_lat >> temp_lat;
         lat_values.push_back(temp_lat);
      }
   }
   std::ifstream if_long(long_file);
   if (!if_long.is_open()){
      std::cout << "Error: Could not open longitude file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
      while (!if_long.eof()){
         if_long >> temp_long;
         long_values.push_back(temp_long);
      }
   }
   auto prediction = predictedLocations();
   Writer writer("templates/data/prediction.csv");
   writer.exportData(std::get<0>(prediction), std::get<1>(prediction),
                     std::get<2>(prediction), std::get<3>(prediction));
   //Parser parser;
   //std::fstream file(_csv_file);
   //while (file >> parser){
   //   std::string crime_c = parser[_crime_column];
   //   std::string lat_c = parser[_lat_column];
   //   std::string long_c = parser[_long_column];
   //   if (crime_c.empty() || lat_c.empty() || long_c.empty()){
   //      std::cout << "Error: One or more CSV column fields may be empty.\n";
   //   }
   //}
}

}
