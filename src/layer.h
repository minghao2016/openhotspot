/*
 * BSD 3-Clause License
 * Canalysis v0.0.1 Alpha
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
#include <set>
#include <map>
#include <math.h>

#include "utils.h"

#define LEARNING_RATE 0.01f

namespace canalysis {

class Layer {
private:
   // Neurons
   unsigned int _input_layers;
   unsigned int _hidden_layers;
   unsigned int _output_layers;

public:
   Layer(unsigned int input_layers,
         unsigned int hidden_layers,
         unsigned int output_layers);
   bool getWeights(float coordinates);
   float forward();
};

}

#endif
