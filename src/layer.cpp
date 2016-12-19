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

Layer::Layer(std::string lat_values,
             std::string long_values)
   : _lat_values(lat_values),
     _long_values(long_values)
{
   e_radius = 6371;
}

double haversine(double lat1, double long1, double lat2, double long2)
{
   double dlong = long2 - long1;
   double dlat = lat2 - lat1;
}

double Layer::reduceLatValues()
{
}

double Layer::reduceLongValues()
{
}

std::tuple<int, double, double, int> Layer::dbscan(int eps, int min_pts)
{
   double reducedLat = reduceLatValues();
   double reducedLong = reduceLongValues();
}

}
