/*
 * BSD 3-Clause License
 * Canalysis v0.0.1 Alpha
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include <iostream>

#include "predict.h"

namespace canalysis {

Predict::Predict(unsigned int input_layers,
                 unsigned int hidden_layers,
                 int max_variances)
{
   _input_layers = input_layers;
   _hidden_layers = hidden_layers;
   _max_variances = max_variances;
}

std::pair<float, float> Predict::matchCoordinates(float lat_values, float long_values)
{
}

float Predict::locateVariances(float coordinates)
{
   Layer layer(_input_layers, _hidden_layers, _max_variances);
}

}
