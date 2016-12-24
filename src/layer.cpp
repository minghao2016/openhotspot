/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.1
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "layer.h"

namespace canalysis {

Layer::Layer(std::vector<double> lat_values,
             std::vector<double> long_values)
   : _lat_values(lat_values),
     _long_values(long_values)
{
}

double haversine(Haversine& haver)
{
   double dlat = haver.lat2 - haver.lat1;
   double dlong = haver.long2 - haver.long1;
   double a = sin(dlat / 2) * sin(dlat / 2) + cos(haver.lat1);
   double b = sin(dlong / 2) * sin(dlong / 2) + cos(haver.lat2);
   double c = a * b;
   double d = 2 * asin(sqrt(c));
   return E_RADIUS * d;
}

std::vector<double> Layer::reduceLatValues()
{
}

std::vector<double> Layer::reduceLongValues()
{
}

std::tuple<int, double, double, int> Layer::dbscanCluster(unsigned int eps,
                                                          unsigned int min_pts)
{
   Haversine haver;
}

std::vector<double> Layer::expandCluster(unsigned int eps, unsigned int min_pts)
{
}

std::vector<double> Layer::regionQuery(unsigned int eps)
{
}

} // canalysis namespace
