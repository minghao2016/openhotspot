/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.1
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _LAYER_H_
#define _LAYER_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <sstream>
#include <math.h>

#define E_RADIUS 6371

namespace canalysis {

struct Haversine {
   double lat1;
   double long1;
   double lat2;
   double long2;
};

class Layer {
private:
   std::vector<double> _lat_values;
   std::vector<double> _long_values;
   const std::vector<double> lat_avg;
   const std::vector<double> long_avg;

public:
   Layer(std::vector<double>, std::vector<double>);
   double haversine(Haversine&);
   std::vector<double> reduceLatValues();
   std::vector<double> reduceLongValues();
   std::tuple<int, double, double, int> dbscanCluster(unsigned int, unsigned int);
   std::vector<double> expandCluster(unsigned int, unsigned int);
   std::vector<double> regionQuery(unsigned int);
};

}

#endif
