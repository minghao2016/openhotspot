/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "dbscan.h"
#include "metrics.h"
#include "types.h"

namespace hotspot
{

DBSCAN::DBSCAN(std::vector<Coordinates*> _coordinates):
   coordinates(_coordinates)
{
   n_clusters_ = -1;
   for (uint32_t i = 0; i < coordinates[0]->lat_pts.size(); i++){
      // mark points
      visited_pts.push_back(false);
      clustered_pts.push_back(false);
   }
}

DBSCAN::~DBSCAN()
{
}

uint32_t DBSCAN::n_clusters()
{
   return n_clusters_;
}

std::vector<uint32_t> DBSCAN::noise_pts()
{
   return noise_pts_;
}

void DBSCAN::getClusterCenterPoint()
{
   /*for (uint32_t i = 0; i < cluster_pts.size(); i++){
      std::cout << "---------" << i << "---------" << std::endl;
      for (unsigned int p = 0; p < cluster_pts[i].size(); p++){
         std::cout << coordinates[0]->lat_pts[cluster_pts[i][p]] << std::endl;
      }
   }*/
   for (uint32_t i = 0; i < cluster_pts.size(); i++){
      for (unsigned int p = 0; p < cluster_pts[i].size(); p++){
         // set averaged cluster points equal to cluster coordinates
      }
   }
}

std::vector<uint32_t> DBSCAN::regionQuery(uint32_t p, const ClusterWeights& cluster_weights)
{
   Metrics metrics;
   MetricCoordinates _mc;
   if (cluster_weights.dist_metric == "haversine"){
      for (uint32_t i = 0; i < coordinates[0]->lat_pts.size(); i++){
         _mc.lat_1 = coordinates[0]->lat_pts[i];
         _mc.lat_2 = coordinates[0]->lat_pts[p];
         _mc.long_1 = coordinates[0]->long_pts[i];
         _mc.long_2 = coordinates[0]->long_pts[p];
         if (metrics.haversineDistanceMetric(_mc) <= cluster_weights.eps){
            rq_pts.push_back(i);
         }
      }
   } else if (cluster_weights.dist_metric == "euclidean"){
      for (uint32_t i = 0; i < coordinates[0]->lat_pts.size(); i++){
         _mc.lat_1 = coordinates[0]->lat_pts[i];
         _mc.lat_2 = coordinates[0]->lat_pts[p];
         _mc.long_1 = coordinates[0]->long_pts[i];
         _mc.long_2 = coordinates[0]->long_pts[p];
         if (metrics.euclideanDistanceMetric(_mc) <= cluster_weights.eps){
            rq_pts.push_back(i);
         }
      }
   }
   // all points within the eps neighborhood
   return rq_pts;
}

void DBSCAN::expandCluster(uint32_t p, std::vector<uint32_t>* ec_neighbor_pts,
                           uint32_t* n_clusters, const ClusterWeights& cluster_weights)
{
   cluster_pts.push_back(std::vector<uint32_t>());
   cluster_pts[*n_clusters].push_back(p);
   for (uint32_t i = 0; i < (uint32_t)ec_neighbor_pts->size(); i++){
      if (!visited_pts[ec_neighbor_pts->at(i)]){
         // mark point p as visited
         visited_pts[ec_neighbor_pts->at(i)] = true;
         std::vector<uint32_t> ec_neighbor_pts_ = regionQuery(ec_neighbor_pts->at(i), cluster_weights);
         if (ec_neighbor_pts_.size() >= cluster_weights.min_pts){
            //std::cout << ec_neighbor_pts->at(i) << std::endl;
            ec_neighbor_pts->insert(ec_neighbor_pts->end(), ec_neighbor_pts_.begin(), ec_neighbor_pts_.end());
         }
         // mark point p as clustered
         clustered_pts[ec_neighbor_pts->at(i)] = true;
         // add any other points that haven't been clustered
         if (clustered_pts[ec_neighbor_pts->at(i)]){
            cluster_pts[*n_clusters].push_back(ec_neighbor_pts->at(i));
         }
      }
   }
}

void DBSCAN::performClusterSearch(const ClusterWeights& cluster_weights)
{
   for (uint32_t i = 0; i < coordinates[0]->lat_pts.size(); i++){
      if (visited_pts[i]) {
         continue;
      } else {
         // mark point p as visited
         visited_pts[i] = true;
         std::vector<uint32_t> rq_neighbor_pts = regionQuery(i, cluster_weights);
         if (rq_neighbor_pts.size() < cluster_weights.min_pts){
            noise_pts_.push_back(rq_neighbor_pts[i]);
         } else {
            n_clusters_++;
            // mark point p as clustered
            clustered_pts[i] = true;
            expandCluster(i, &rq_neighbor_pts, &n_clusters_, cluster_weights);
            getClusterCenterPoint();
         }
      }
   }
}

float DBSCAN::computeError()
{
}

} // hotspot namespace
