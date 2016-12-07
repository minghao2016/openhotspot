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

std::tuple<double, double> canalysis::Predict::match_coordinates(double lat_values, double long_values)
{
   return std::make_tuple(lat_values, long_values);
}

}
