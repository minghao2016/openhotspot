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
#include <tuple>
#include <map>
#include <math.h>

#include "utils.h"

namespace canalysis {

class Layer {
private:
   std::string _lat_values;
   std::string _long_values;

   // In km
   int e_radius = 6371;

public:
   Layer(std::string lat_values,
         std::string long_values);
   double haversine(double lat1, double long1, double lat2, double long2);
   double reduceLatValues();
   double reduceLongValues();
   std::tuple<int, double, double, int> dbscan(int eps, int min_pts);
};

}

#endif
