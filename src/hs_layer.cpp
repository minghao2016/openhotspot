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

namespace hotspot {

Layer::Layer(std::vector<Coordinates> _clusters):
   clusters(_clusters)
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

void Layer::reduceLatValues()
{
}

void Layer::reduceLongValues()
{
}

std::vector<int> Layer::regionQuery(unsigned int p, double eps)
{
   int dataset_size = clusters[0].lat_pts.size();
   std::vector<int> output_pts;
   for (unsigned int i = 0; i < dataset_size; ++i){
      // The metric here is haversine since we are working with coordinates
      if (haversineMetric(clusters[0].lat_pts[i],
                          clusters[1].long_pts[i],
                          clusters[0].lat_pts[p],
                          clusters[1].long_pts[p]) <= eps){
         output_pts.push_back(i);
      }
   }
   // Return all points within p's eps-neighborhood
   return output_pts;
}

std::vector<double> Layer::expandCluster(unsigned int p, double c, double eps,
                                         unsigned int min_pts, unsigned int min_samples)
{
   int dataset_size = clusters[0].lat_pts.size();
}

utils_tuple Layer::dbscan(double eps, unsigned int min_pts, unsigned int min_samples)
{
   double c = 0.0;
   // Both lat and long are the same size, so either can be used
   int dataset_size = clusters[0].lat_pts.size();
   for (unsigned int i = 0; i < dataset_size; ++i){
   }
}

std::vector<std::string> Layer::clusterType()
{
   PriorityTypes* pt;
   std::vector<std::string> output_types;
}

} // hotspot namespace
