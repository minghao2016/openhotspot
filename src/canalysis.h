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
#include <utility>
#include <vector>

#include <boost/lexical_cast.hpp>

#include "parser.h"
#include "layer.h"
#include "writer.h"
#include "utils.h"

namespace canalysis {

class Canalysis {
private:
   std::string _csvfile;

   // CSV file data
   unsigned int _crime_coloumn;
   unsigned int _lat_column;
   unsigned int _long_column;

public:
   Canalysis(std::string csvfile,
             unsigned int crime_column,
             unsigned int lat_column,
             unsigned int long_column);
   std::pair<double, double> predictedLocations(double lat_values, double long_values);
   void model();
};

}

#endif
