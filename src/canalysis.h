/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _CANALYSIS_H_
#define _CANALYSIS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>

#define PFILE "./data/prediction.csv"

namespace canalysis {

class Canalysis {
private:
   double temp_lat;
   double temp_long;
   std::vector<double> lat_values;
   std::vector<double> long_values;

   std::string row;
   std::string line;
   std::vector<std::string> csv_data;

public:
   //Canalysis(const std::string, unsigned int, unsigned int, unsigned int);
   void reformat(const std::string, int, int);
   std::tuple<int, double, double, int> predictedLocations();
   void model(const std::string, const std::string);
};

}

#endif
