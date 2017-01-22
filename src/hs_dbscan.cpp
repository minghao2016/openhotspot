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

DBSCAN::DBSCAN(std::vector<std::shared_ptr<Coordinates> > _coordinates):
   coordinates(_coordinates)
{
   c_clusters = 0;
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

double DBSCAN::haversineMetric(Metric& metric)
{
   double dlat_1 = degreesToRadians(metric.lat_1);
   double dlong_1 = degreesToRadians(metric.long_1);
   double dlat_2 = degreesToRadians(metric.lat_2);
   double dlong_2 = degreesToRadians(metric.long_2);
   double a = sin((dlat_2 - dlat_1) / 2);
   double b = sin((dlong_2 - dlong_1) / 2);
   return 2 * 6371 * asin(sqrt(a * a + cos(dlat_1) * cos(dlat_2) * b * b));
}

double DBSCAN::euclideanMetric(Metric& metric)
{
   double dlat_1 = metric.lat_2 - metric.lat_1;
   double dlong_1 = metric.long_2 - metric.long_1;
   return sqrt(dlat_1 * dlat_1 + dlong_1 * dlong_1);
}

float DBSCAN::iterationTime()
{
}

std::vector<double> DBSCAN::clusterCenter(std::vector<std::vector<Coordinates*> > c_coordinates,
                                          unsigned int c_size)
{
   for (unsigned int i = 0; i < c_coordinates.size(); i++){
      for (unsigned int p = 0; p < c_size; p++){
      }
   }
}

std::vector<int> DBSCAN::regionQuery(unsigned int p, const ClusterWeights& cluster_weights)
{
   Metric metric;
   if (cluster_weights.dist_metric == "haversine"){
      for (unsigned int i = 0; i < coordinates[0]->lat_pts.size(); i++){
         metric.lat_1 = coordinates[0]->lat_pts[i];
         metric.lat_2 = coordinates[0]->lat_pts[p];
         metric.long_1 = coordinates[0]->long_pts[i];
         metric.long_2 = coordinates[0]->long_pts[p];
         if (haversineMetric(metric) < cluster_weights.eps){
            rq_pts.push_back(i);
         }
      }
   } else if (cluster_weights.dist_metric == "euclidean"){
      for (unsigned int i = 0; i < coordinates[0]->lat_pts.size(); i++){
         metric.lat_1 = coordinates[0]->lat_pts[i];
         metric.lat_2 = coordinates[0]->lat_pts[p];
         metric.long_1 = coordinates[0]->long_pts[i];
         metric.long_2 = coordinates[0]->long_pts[p];
         if (euclideanMetric(metric) < cluster_weights.eps){
            rq_pts.push_back(i);
         }
      }
   }
   return rq_pts;
}

std::vector<std::vector<Coordinates*> >
DBSCAN::expandCluster(unsigned int p, std::vector<int>* ec_neighbor_pts, unsigned int* c_clusters,
                      const ClusterWeights& cluster_weights)
{
   for (unsigned int i = 0; i < (int)ec_neighbor_pts->size(); i++){
      if (visted_pts[i]){
         visted_pts[i] = true;
         //ec_neighbor_pts_ = regionQuery(p, cluster_weights);
         /*if (ec_neighbor_pts_.size() >= cluster_weights.min_pts){
            ec_neighbor_pts->insert(ec_neighbor_pts->end(), ec_neighbor_pts_.begin(),
                                    ec_neighbor_pts_.end());
         }
         clustered_pts.push_back(false);
         if (!clustered_pts[ec_neighbor_pts->at(i)]){
         //   clusters[*c_clusters].push_back(ec_neighbor_pts->at(i));
         }*/
      }
   }
}

utils_tuple DBSCAN::dbscan(const ClusterWeights& cluster_weights)
{
   for (unsigned int i = 0; i < coordinates[0]->lat_pts.size(); i++){
      visted_pts.push_back(false);
      if (visted_pts[i]) {
         continue;
      } else {
         visted_pts[i] = true;
         rq_neighbor_pts = regionQuery(i, cluster_weights);
         if (rq_neighbor_pts.size() < cluster_weights.min_pts){
            noise_pts.push_back(rq_neighbor_pts[i]);
         } else {
            c_clusters++;
            //clusters.push_back(std::vector<std::shared_ptr<Coordinates> >());
            std::vector<std::vector<Coordinates*> > ec_pts = expandCluster(i, &rq_neighbor_pts, &c_clusters, cluster_weights);
         }
      }
   }
}

} // hotspot namespace
