/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "layer.h"
#include "utils.h"

namespace canalysis {

Layer::Layer(std::vector<double> lat_values,
             std::vector<double> long_values)
   : _lat_values(lat_values),
     _long_values(long_values)
{
   e_radius = 6371;
}

double haversine(Haversine& haver)
{
   double dlong = haver.long2 - haver.long1;
   double dlat = haver.lat2 - haver.lat1;
}

double Layer::reduceLatValues()
{
}

double Layer::reduceLongValues()
{
}

std::tuple<int, double, double, int> Layer::dbscanCluster(unsigned int eps,
                                                          unsigned int min_pts)
{
   Haversine haver;
}

double Layer::expandCluster(unsigned int eps, unsigned int min_pts)
{
}

double Layer::regionQuery(unsigned int eps)
{
}

}
