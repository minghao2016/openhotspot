/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
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
#include <algorithm>
#include <cmath>
#include <ctime>
#include <memory>
#include <set>
#include <iomanip>

#include "export.h"

namespace hotspot
{

class HotSpot {
private:
   double temp_lat;
   double temp_long;
   std::string temp_crime;
   uint32_t temp_dates;

   std::vector<double> lat_values;
   std::vector<double> long_values;
   std::vector<std::string> crime_values;
   std::vector<uint32_t> date_values;

public:
   void reformatCSVFile(const std::string&, unsigned int, unsigned int, unsigned int, unsigned int);
   void printCrimeRate(const std::string&);
   PredictedData prediction(float, unsigned int, const std::string&);
   void launchWebClient();
   void loadModel(const std::string&, const std::string&, const std::string&, float, unsigned int,
                  const std::string&);
};

}

#endif
