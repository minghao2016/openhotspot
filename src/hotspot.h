/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.3
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _HOTSPOT_H_
#define _HOTSPOT_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

#include "hs_utils.h"

namespace hotspot {

class HotSpot {
private:
   double temp_lat;
   double temp_long;
   std::string temp_crime;

   std::vector<double> lat_values;
   std::vector<double> long_values;
   std::vector<std::string> crime_values;

public:
   void reformatCSVFile(const std::string&, unsigned int, unsigned int,
                        unsigned int);
   void crimePercentage(const std::string&);
   utils_tuple predictedClusters(double, unsigned int, const std::string&);
   utils_pair predictedCoordinates();
   void launchWebClient();
   void loadModel(const std::string&, const std::string&, double,
                  unsigned int, const std::string&);
};

}

#endif
