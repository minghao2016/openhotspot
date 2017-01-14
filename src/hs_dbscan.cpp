/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.3
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "hs_dbscan.h"

namespace hotspot {

DBSCAN::DBSCAN(std::vector<Coordinates> _coordinates, double _eps, unsigned int _min_pts,
               const std::string& _dist_metric):
   coordinates(_coordinates),
   eps(_eps),
   min_pts(_min_pts),
   dist_metric(_dist_metric)
{
   c = 0;
   for (unsigned int i = 0; i < coordinates[0].lat_pts.size(); i++){
      visted_pts.push_back(false);
   }
}

DBSCAN::~DBSCAN()
{
}

double DBSCAN::radiansToDegrees(double radians)
{
   return radians * 180 / 3.14159;
}

double DBSCAN::degreesToRadians(double degrees)
{
   return degrees * 3.14159 / 180;
}

double DBSCAN::haversineMetric(Metric* metric)
{
   double dlat_1 = degreesToRadians(metric->lat_1);
   double dlong_1 = degreesToRadians(metric->long_1);
   double dlat_2 = degreesToRadians(metric->lat_2);
   double dlong_2 = degreesToRadians(metric->long_2);
   double a = sin((dlat_2 - dlat_1) / 2);
   double b = sin((dlong_2 - dlong_1) / 2);
   return 2 * 6371 * asin(sqrt(a * a + cos(dlat_1) * cos(dlat_2) * b * b));
}

double DBSCAN::euclideanMetric(Metric* metric)
{
   double dlat_1 = metric->lat_2 - metric->lat_1;
   double dlong_1 = metric->long_2 - metric->long_1;
   return sqrt(dlat_1 * dlat_1 + dlong_1 * dlong_1);
}

void DBSCAN::reduceLatValues(unsigned int size)
{
}

void DBSCAN::reduceLongValues(unsigned int size)
{
}


std::vector<double> DBSCAN::clusterCenter(std::vector<std::vector<Coordinates> > center_coords,
                                          unsigned int cc_size)
{
   for (unsigned int i = 0; i < center_coords.size(); i++){
      for (unsigned int p = 0; p < cc_size; p++){
      }
   }
}

std::vector<std::string> DBSCAN::clusterType(std::vector<std::vector<Coordinates> > center_coords)
{
}

std::vector<int> DBSCAN::regionQuery(unsigned int p)
{
   Metric metric;
   if (dist_metric == "haversine"){
      for (unsigned int i = 0; i < coordinates[0].lat_pts.size(); i++){
         metric.lat_1 = coordinates[0].lat_pts[i];
         metric.lat_2 = coordinates[0].lat_pts[p];
         metric.long_1 = coordinates[1].long_pts[i];
         metric.long_2 = coordinates[1].long_pts[p];
         if (haversineMetric(&metric) <= eps){
            rq_pts.push_back(i);
         }
      }
   } else if (dist_metric == "euclidean"){
      for (unsigned int i = 0; i < coordinates[0].lat_pts.size(); i++){
         metric.lat_1 = coordinates[0].lat_pts[i];
         metric.lat_2 = coordinates[0].lat_pts[p];
         metric.long_1 = coordinates[1].long_pts[i];
         metric.long_2 = coordinates[1].long_pts[p];
         if (euclideanMetric(&metric) <= eps){
            rq_pts.push_back(i);
         }
      }
   }
   return rq_pts;
}

std::vector<Coordinates> DBSCAN::expandCluster(unsigned int p, std::vector<int> ec_neighbor_pts,
                                               unsigned int c)
{
   clusters.push_back(std::vector<Coordinates>());
   //clusters[c].push_back(coordinates[0].lat_pts[rq_neighbor_pts[i]]);
   for (unsigned int i = 0; i < ec_neighbor_pts.size(); p++){
      if (!visted_pts[i]){
         //ec_neighbor_pts_ = regionQuery(rq_neighbor_pts[p]);
         //if (ec_neighbor_pts.size() >= min_pts){
         //}
      }
   }
}

utils_tuple DBSCAN::dbscan()
{
   for (unsigned int i = 0; i < coordinates[0].lat_pts.size(); i++){
      if (visted_pts[i]) {
         continue;
      } else {
         visted_pts[i] = true;
         rq_neighbor_pts = regionQuery(i);
         if (rq_neighbor_pts.size() < min_pts){
            noise_pts.push_back(rq_neighbor_pts[i]);
         } else {
            c++;
            ec_pts = expandCluster(i, rq_neighbor_pts, c);
         }
      }
      //return std::make_tuple();
   }
}

float DBSCAN::computeErrorCoverage()
{
}

} // hotspot namespace
