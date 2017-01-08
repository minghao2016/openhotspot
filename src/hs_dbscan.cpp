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

DBSCAN::DBSCAN(std::vector<Coordinates> _coordinates):
   coordinates(_coordinates)
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

double DBSCAN::haversineMetric(Metric* metric)
{
   double dlat_1 = degreesToRadians(metric->lat_1);
   double dlong_1 = degreesToRadians(metric->long_1);
   double dlat_2 = degreesToRadians(metric->lat_2);
   double dlong_2 = degreesToRadians(metric->long_2);
   double a = sin((dlat_2 - dlat_1) / 2);
   double b = sin((dlong_2 - dlong_1) / 2);
   return 2 * EARTH_RADIUS * asin(sqrt(a * a + cos(dlat_1) * cos(dlat_2) * b * b));
}

double DBSCAN::euclideanMetric(Metric* metric)
{
}

void DBSCAN::reduceLatValues(unsigned int size)
{
}

void DBSCAN::reduceLongValues(unsigned int size)
{
}

utils_tuple DBSCAN::dbscan(double eps, unsigned int min_pts,
                           unsigned int min_samples,
                           const std::string& dist_metric)
{
   int dataset_size = coordinates[0].lat_pts.size();
   for (unsigned int i = 0; i < dataset_size; i++){
      visted_pts.push_back(false);
      if (visted_pts[i]) {
         // continue to next point
         continue;
      } else {
         // mark point p as visted
         visted_pts[i] = true;
         rq_neighbor_pts = regionQuery(i, i, eps, dist_metric);
         //std::cout << rq_neighbor_pts.size() << std::endl;
         if (rq_neighbor_pts.size() < min_pts){
            // mark point p and a noise point
            noise_pts.push_back(i);
            //std::cout << coordinates[0].lat_pts[i] << std::endl;
         } else {
            // move to next clusters and expand
            //expandCluster(rq_neighbor_pts, eps, min_pts, min_samples);
            //std::cout << coordinates[0].lat_pts[i] << std::endl;
         }
      }
   }
   //return std::make_tuple();
}

std::vector<OutputCoordinateCenters> DBSCAN::expandCluster(std::vector<int> ec_neighbor_pts,
                                                           unsigned int p, double eps,
                                                           unsigned int min_pts,
                                                           unsigned int min_samples)
{
   int dataset_size = coordinates[0].lat_pts.size();
   for (unsigned int i = 0; i < dataset_size; i++){
   }
}

std::vector<int> DBSCAN::regionQuery(unsigned int d, unsigned int p,
                                     double eps, const std::string& dist_metric)
{
   Metric metric;
   if (dist_metric == "haversine"){
      metric.lat_1 = coordinates[0].lat_pts[d];
      metric.lat_2 = coordinates[0].lat_pts[p + 1];
      metric.long_1 = coordinates[1].long_pts[d];
      metric.long_2 = coordinates[1].long_pts[p + 1];
      if (haversineMetric(&metric) <= eps){
         rq_pts.push_back(d);
      }
   } else if (dist_metric == "euclidean"){
      metric.lat_1 = coordinates[0].lat_pts[d];
      metric.lat_2 = coordinates[0].lat_pts[p + 1];
      metric.long_1 = coordinates[1].long_pts[d];
      metric.long_2 = coordinates[1].long_pts[p + 1];
      if (euclideanMetric(&metric) <= eps){
         rq_pts.push_back(d);
      }
   }
   // return all points within point p's eps-neighborhood
   return rq_pts;
}

std::vector<std::string> DBSCAN::clusterType(OutputClusterTypes* oct)
{
}

float DBSCAN::computeErrorRate()
{
}

} // hotspot namespace
