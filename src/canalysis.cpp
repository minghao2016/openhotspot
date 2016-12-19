/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include <iostream>

#include "canalysis.h"

namespace canalysis {

Canalysis::Canalysis(std::string csvfile,
                     unsigned int crime_column,
                     unsigned int lat_column,
                     unsigned int long_column)
{
   _csvfile = csvfile;
   _crime_coloumn = crime_column;
   _lat_column = lat_column;
   _long_column = long_column;
}

std::tuple<int, double, double, int> Canalysis::predictedLocations(std::string lat_values,
                                                                   std::string long_values)
{
   Layer layer(lat_values, long_values);
   layer.reduceLatValues();
   layer.reduceLongValues();
   auto prediction = layer.dbscan(5, 20);
   return std::make_tuple(std::get<0>(prediction),
                          std::get<1>(prediction),
                          std::get<2>(prediction),
                          std::get<3>(prediction));
}

std::istream &operator>>(std::istream &file, Parser &parser)
{
   parser.getColumnFields(file);
   return file;
}

void Canalysis::model()
{
   Parser parser;
   Writer writer;
   std::fstream file(_csvfile);
   while (file >> parser){
      std::string crime_c = parser[_crime_coloumn];
      std::string lat_c = parser[_lat_column];
      std::string long_c = parser[_long_column];
      auto prediction = predictedLocations(lat_c, long_c);
      writer.exportData("templates/data/prediction.csv",
                        std::get<0>(prediction),
                        std::get<1>(prediction),
                        std::get<2>(prediction),
                        std::get<3>(prediction));
   }
}

}
