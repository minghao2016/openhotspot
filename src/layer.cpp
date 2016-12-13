/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include <iostream>

#include "layer.h"

using namespace std;

namespace canalysis {

Layer::Layer(unsigned int input_layers,
             unsigned int hidden_layers,
             unsigned int output_layers)
{
   _input_layers = input_layers;
   _hidden_layers = hidden_layers;
   _output_layers = output_layers;
}

bool getWeights(float coordinates)
{
}

float Layer::forward()
{
}

float Layer::backward()
{
}

}
