/*
 * BSD 3-Clause License
 * Canalysis v0.0.1 Alpha
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include <iostream>

#include "canalysis.h"

using namespace std;

namespace canalysis {

Parser parser;
Predict predict;

Canalysis::Canalysis(std::string csvfile, int crime_column, int lat_column, int long_column)
{
   _csvfile = csvfile;
   _crime_coloumn = crime_column;
   _lat_column = lat_column;
   _long_column = long_column;
}

Canalysis::~Canalysis()
{
}

void canalysis::Canalysis::get_version()
{
}

std::istream &operator>>(std::istream &file, Parser &parser)
{
   parser.get_column_fields(file);
   return file;
}

void canalysis::Canalysis::model()
{
   std::ifstream file(_csvfile);
   int column_length = parser.get_column_length(file);

   while (file >> parser){
      std::string crime_c = parser[_crime_coloumn];
      std::string lat_c = parser[_lat_column];
      std::string long_c = parser[_long_column];

      if (crime_c.empty() || lat_c.empty() || long_c.empty()){
         std::cout << "[!] Error: One or more fields are empty" << std::endl;
      }

      double lat_values = atof(lat_c.c_str());
      double long_values = atof(long_c.c_str());

      auto mf = predict.match_coordinates(lat_values, long_values);
   }
}

void canalysis::Canalysis::train_layer(float learning_rate)
{
}

}
