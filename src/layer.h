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

#define LEARNING_RATE 0.001

namespace canalysis {

class Layer {
private:
   int _input;
   int _hidden;
   int _output;

public:
   Layer(int input,
         int hidden,
         int output);
   float feedforward();
   double predict();
   void train();
};

}

#endif
