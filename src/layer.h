/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
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
   std::vector<double> lat_avg;
   std::vector<double> long_avg;
   int e_radius;

public:
   Layer(std::vector<double>, std::vector<double>);
   double haversine(Haversine&);
   double reduceLatValues();
   double reduceLongValues();
   std::tuple<int, double, double, int> dbscanCluster(unsigned int, unsigned int);
   double expandCluster(unsigned int, unsigned int);
   double regionQuery(unsigned int);
};

}

#endif
