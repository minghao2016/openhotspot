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

namespace canalysis {

Layer::Layer(double lat_values,
             double long_values)
{
   _lat_values = lat_values;
   _long_values = long_values;
}

double Layer::reduceLatValues()
{
}

double Layer::reduceLongValues()
{
}

std::pair<double, double> Layer::clusterValues()
{
}

}
