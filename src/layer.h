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
#include <map>
#include <math.h>

#include "utils.h"

namespace canalysis {

class Layer {
private:
   double _lat_values;
   double _long_values;

public:
   Layer(double lat_values,
         double long_values);
   double reduceLatValues();
   double reduceLongValues();
   std::pair<double, double> clusterValues();
};

}

#endif
