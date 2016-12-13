/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
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
   unsigned int _output_layers;

public:
   Predict(unsigned int input_layers,
           unsigned int hidden_layers,
           unsigned int output_layers);
   float matchCoordinates(float lat_values, float long_values);
   float predictedLocations(float coordinates);
   void exportData(char *filename);
};

}

#endif
