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
   float latitude;
   float longitude;
};

class Predict {
private:
   // Neurons
   unsigned int _input_layers;
   unsigned int _hidden_layers;

   // Output layer
   int _max_variances;

public:
   Predict(unsigned int input_layers,
           unsigned int hidden_layers,
           int max_variances);
   std::pair<float, float> matchCoordinates(float lat_values, float long_values);
   float locateVariances(float coordinates);
};

}

#endif
