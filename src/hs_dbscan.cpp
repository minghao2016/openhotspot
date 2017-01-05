/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.2
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "hs_dbscan.h"

namespace hotspot {

DBSCAN::DBSCAN()
{
}

DBSCAN::DBSCAN(std::vector<Coordinates> _clusters):
   clusters(_clusters)
{
   c = 0.0;
}

DBSCAN::~DBSCAN()
{
}

double DBSCAN::radiansToDegrees(double radians)
{
   return radians * 180 / PI;
}

double DBSCAN::degreesToRadians(double degrees)
{
   return degrees * PI / 180;
}

double DBSCAN::haversineMetric(Metric& metric)
{
   double dlat_1 = degreesToRadians(metric.lat_1);
   double dlong_1 = degreesToRadians(metric.long_1);
   double dlat_2 = degreesToRadians(metric.lat_2);
   double dlong_2 = degreesToRadians(metric.long_2);
   double a = sin((dlat_2 - dlat_1) / 2);
   double b = sin((dlong_2 - dlong_1) / 2);
   return 2 * EARTH_RADIUS * asin(sqrt(a * a + cos(dlat_1) * cos(dlat_2) * b * b));
}

double DBSCAN::euclideanMetric(Metric& metric)
{
}

void DBSCAN::reduceLatValues(unsigned int size)
{
}

void DBSCAN::reduceLongValues(unsigned int size)
{
}

utils_tuple DBSCAN::dbscan(double eps, unsigned int min_pts, unsigned int min_samples,
                           const std::string& dist_metric)
{
   int dataset_size = clusters[0].lat_pts.size();
   for (unsigned int i = 0; i < dataset_size; ++i){
      visted_pts.push_back(false);
      if (visted_pts[i]) {
         // continue to next point
         continue;
      } else {
         // mark point p as visted
         visted_pts[i] = true;
         rq_neighbor_pts = regionQuery(visted_pts[i], eps, dist_metric);
         if (rq_neighbor_pts.size() < min_pts){
            // mark point p and a noise point
            noise_pts.push_back(i);
         } else {
         }
      }
   }
   //return std::make_tuple();
}

std::vector<OutputCenters> DBSCAN::expandCluster(unsigned int p, double eps,
                                                 unsigned int min_pts,
                                                 unsigned int min_samples)
{
   int dataset_size = clusters[0].lat_pts.size();
   for (unsigned int i = 0; i < dataset_size; ++i){
   }
}

std::vector<int> DBSCAN::regionQuery(unsigned int p, double eps, const std::string& dist_metric)
{
   Metric metric;
   int dataset_size = clusters[0].lat_pts.size();
   if (dist_metric == "haversine"){
      for (unsigned int i = 0; i < dataset_size; ++i){
         metric.lat_1 = clusters[0].lat_pts[i];
         metric.lat_2 = clusters[0].lat_pts[p];
         metric.long_1 = clusters[1].long_pts[i];
         metric.long_2 = clusters[1].long_pts[p];
         if (haversineMetric(metric) <= eps){
            // store points with an eps, smaller than the default, into a vector
            output_pts.push_back(i);
         }
      }
   } else if (dist_metric == "euclidean"){
      for (unsigned int i = 0; i < dataset_size; ++i){
         metric.lat_1 = clusters[0].lat_pts[i];
         metric.lat_2 = clusters[0].lat_pts[p];
         metric.long_1 = clusters[1].long_pts[i];
         metric.long_2 = clusters[1].long_pts[p];
         if (euclideanMetric(metric) <= eps){
            // store points with an eps, smaller than the default, into a vector
            output_pts.push_back(i);
         }
      }
   }
   // return all points within point p's eps-neighborhood
   return output_pts;
}

float DBSCAN::computeErrorRate()
{
}

std::vector<std::string> DBSCAN::clusterType(PriorityTypes& pt)
{
}

} // hotspot namespace
