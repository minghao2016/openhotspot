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

Predict::Predict()
{
}

std::pair<float, float> canalysis::Predict::matchCoordinates(float lat_values, float long_values)
{
}

float canalysis::Predict::locateVariances(int input_layers, int hidden_layers, double coordinates)
{
   Layer layer(input_layers, hidden_layers, max_variances);
}

void canalysis::Predict::trainLayer()
{

}

}
