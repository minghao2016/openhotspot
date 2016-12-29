/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.1
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "hs_layer.h"
#include "hs_utils.h"

namespace hotspot {

Layer::Layer(std::vector<Coordinates> clusters):
   _clusters(clusters)
{
}

Layer::~Layer()
{
}

double Layer::degreesToRadians(double degrees)
{
   return degrees * PI / 180;
}

double Layer::haversineMetric(double lat_v1, double lat_v2, double long_v1, double long_v2)
{
   double dlat_1 = degreesToRadians(lat_v1);
   double dlong_1 = degreesToRadians(long_v1);
   double dlat_2 = degreesToRadians(lat_v2);
   double dlong_2 = degreesToRadians(long_v2);
   double a = sin((dlat_2 - dlat_1) / 2);
   double b = sin((dlong_2 - dlong_1) / 2);
   return 2 * EARTH_RADIUS * asin(sqrt(a * a + cos(dlat_1) * cos(dlat_2) * b * b));
}

double Layer::euclideanMetric(double lat_v1, double lat_v2, double long_v1, double long_v2)
{
   double dlat = lat_v2 - lat_v1;
   double dlong = long_v2 - long_v1;
   return sqrt(dlat * dlat + dlong * dlong);
}

void Layer::reduceLatValues()
{
}

void Layer::reduceLongValues()
{
}

utils_tuple Layer::dbscan(unsigned int eps, unsigned int min_pts)
{
   double c = 0.0;
   // Since both lat and long are the same size, it does not matter which is used.
   int dataset_size = _clusters[0].lat_values.size();
   for (unsigned int i = 0; i < dataset_size; i++){
      std::cout << _clusters[0].lat_values[i] << std::endl;
   }
}

void Layer::expandCluster(unsigned int p, unsigned int c, unsigned int eps,
                          unsigned int min_pts)
{
}

double Layer::regionQuery(unsigned int p, unsigned int eps)
{
}

} // hotspot namespace
