/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.4
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "hs_dbscan.h"
#include "hs_types.h"

namespace hotspot
{

DBSCAN::DBSCAN(std::vector<Coordinates*> _coordinates):
   coordinates(_coordinates)
{
   n_clusters_ = 0;
   for (uint32_t i = 0; i < coordinates[0]->lat_pts.size(); i++){
      // Mark points
      visited_pts.push_back(false);
      clustered_pts.push_back(false);
   }
}

DBSCAN::~DBSCAN()
{
}

std::vector<uint32_t> DBSCAN::noise_pts()
{
   return noise_pts_;
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

void DBSCAN::getClusterCenterPoint(std::vector<Coordinates*> clusters)
{
   for (uint32_t i = 0; i < cluster_pts.size(); i++){
      for (unsigned int p = 0; p < cluster_pts[i].size(); p++){
         // Set averaged cluster points equal to cluster coordinates
      }
   }
}

std::vector<uint32_t> DBSCAN::regionQuery(uint32_t p, const ClusterWeights& cluster_weights)
{
   Metric metric;
   if (cluster_weights.dist_metric == "haversine"){
      for (unsigned int i = 0; i < coordinates[0]->lat_pts.size(); i++){
         metric.lat_1 = coordinates[0]->lat_pts[i];
         metric.lat_2 = coordinates[0]->lat_pts[p];
         metric.long_1 = coordinates[0]->long_pts[i];
         metric.long_2 = coordinates[0]->long_pts[p];
         if (haversineMetric(metric) <= cluster_weights.eps){
            rq_pts.push_back(i);
         }
      }
   } else if (cluster_weights.dist_metric == "euclidean"){
      for (unsigned int i = 0; i < coordinates[0]->lat_pts.size(); i++){
         metric.lat_1 = coordinates[0]->lat_pts[i];
         metric.lat_2 = coordinates[0]->lat_pts[p];
         metric.long_1 = coordinates[0]->long_pts[i];
         metric.long_2 = coordinates[0]->long_pts[p];
         if (euclideanMetric(metric) <= cluster_weights.eps){
            rq_pts.push_back(i);
         }
      }
   }
   // All points within the eps neighborhood
   return rq_pts;
}

void DBSCAN::expandCluster(uint32_t p, std::vector<uint32_t>* ec_neighbor_pts,
                           uint32_t* n_clusters, const ClusterWeights& cluster_weights)
{
   //cluster_pts.push_back(std::vector<uint32_t>());
   //cluster_pts[*n_clusters].push_back(p);
   for (uint32_t i = 0; i < (uint32_t)ec_neighbor_pts->size(); i++){
      if (!visited_pts[ec_neighbor_pts->at(i)]){
         // Mark point p as visited
         visited_pts[ec_neighbor_pts->at(i)] = true;
         std::vector<uint32_t> ec_neighbor_pts_ = regionQuery(ec_neighbor_pts->at(i), cluster_weights);
         if (ec_neighbor_pts_.size() >= cluster_weights.min_pts){
            ec_neighbor_pts->insert(ec_neighbor_pts->end(), ec_neighbor_pts_.begin(), ec_neighbor_pts_.end());
         }
         clustered_pts[ec_neighbor_pts->at(i)] = true;
         // Add any other points that haven't been clustered
         if (!clustered_pts[ec_neighbor_pts->at(i)]){
            //cluster_pts[*n_clusters].push_back(ec_neighbor_pts->at(i));
         }
      }
   }
}

std::vector<Coordinates*> DBSCAN::dbscan(const ClusterWeights& cluster_weights)
{
   std::vector<Coordinates*> clusters;
   for (uint32_t i = 0; i < coordinates[0]->lat_pts.size(); i++){
      if (visited_pts[i]) {
         continue;
      } else {
         // Mark point p as visited
         visited_pts[i] = true;
         std::vector<uint32_t> rq_neighbor_pts = regionQuery(i, cluster_weights);
         if (rq_neighbor_pts.size() < cluster_weights.min_pts){
            noise_pts_.push_back(rq_neighbor_pts[i]);
         } else {
            n_clusters_++;
            // Mark point p as clustered so that it only shows up once
            clustered_pts[i] = true;
            expandCluster(i, &rq_neighbor_pts, &n_clusters_, cluster_weights);
            getClusterCenterPoint(clusters);
         }
      }
   }
   return clusters;
}

} // hotspot namespace
