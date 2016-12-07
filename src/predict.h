/*
 * BSD 3-Clause License
 * Canalysis v0.0.1 Alpha
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _PREDICT_H_
#define _PREDICT_H_

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <array>
#include <stdlib.h>

#include "layer.h"
#include "utils.h"

namespace canalysis {

struct Coordinates {
   double latitude;
   double longitude;
};

class Predict {
private:
   int variance_scale;
   const int max_variances = 50;

public:
   Predict();
   std::tuple<double, double> match_coordinates(double lat_values, double long_values);
   int get_fields_occurrence(double coordinates);
   float locate_correlation();
   double locate_variances(double coordinates);
};

}

#endif
