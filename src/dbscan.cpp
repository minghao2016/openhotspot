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
#include "vector.h"

namespace hotspot {

DBSCAN::DBSCAN(std::vector<Coordinates*> _coordinates):
  coordinates(_coordinates),
  n_clusters_(-1)
{
}

DBSCAN::~DBSCAN() {}

float DBSCAN::error() const
{
  //return computeError();
}

uint32_t DBSCAN::n_clusters() const
{
  return n_clusters_;
}

std::vector<uint32_t> DBSCAN::noise_pts() const
{
  return noise_pts_;
}

void DBSCAN::markPoints(size_t coordinates_size)
{
  for (size_t i = 0; i < coordinates_size; i++) {
    visited_pts.push_back(false);
    clustered_pts.push_back(false);
  }
}

void DBSCAN::epsEstimation(uint32_t p, size_t coordinates_size, ClusterWeights& cluster_weights)
{
  Metrics metrics;
  MetricCoordinates _mc;
  std::vector<double> eps_estimates;
  if (cluster_weights.dist_metric == "haversine") {
    for (size_t i = 0; i < coordinates_size; i++){
      _mc.lat_1 = coordinates[0]->lat_pts[i];
      _mc.lat_2 = coordinates[0]->lat_pts[p];
      _mc.long_1 = coordinates[0]->long_pts[i];
      _mc.long_2 = coordinates[0]->long_pts[p];
      eps_estimates.push_back(metrics.haversineDistanceMetric(_mc));
    }
    double eps_sum = std::accumulate(eps_estimates.begin(), eps_estimates.end(), 0.0);
    double eps_mean = eps_sum / eps_estimates.size();
    // set upper and lower bounds for eps
    double max_eps = eps_mean + 2;
    double min_eps = eps_mean - 2;
    if (cluster_weights.eps < max_eps || cluster_weights.eps > min_eps) {
      cluster_weights.eps = eps_mean;
    }
  }
}

void DBSCAN::minptsEstimation(size_t coordinates_size, ClusterWeights& cluster_weights)
{
}

void DBSCAN::getClusterCenterPoint()
{
  size_t cluster_size = cluster_pts.size();
  assert(cluster_size != 0);
  for (size_t i = 0; i < cluster_size; i++) {
    for (size_t j = 0; j < cluster_pts[i].size(); j++){
      // set averaged cluster coordinates equal to cluster points
    }
  }
}

std::vector<uint32_t> DBSCAN::regionQuery(uint32_t p, size_t coordinates_size,
                                          ClusterWeights& cluster_weights)
{
  Metrics metrics;
  MetricCoordinates _mc;
  if (cluster_weights.dist_metric == "haversine") {
    for (size_t i = 0; i < coordinates_size; i++) {
      _mc.lat_1 = coordinates[0]->lat_pts[i];
      _mc.lat_2 = coordinates[0]->lat_pts[p];
      _mc.long_1 = coordinates[0]->long_pts[i];
      _mc.long_2 = coordinates[0]->long_pts[p];
      if (metrics.haversineDistanceMetric(_mc) <= cluster_weights.eps) {
        rq_pts.push_back(i);
      }
    }
  }
  // all points within the eps neighborhood
  return rq_pts;
}

void DBSCAN::expandCluster(uint32_t p, std::vector<uint32_t>* ec_neighbor_pts, int32_t* n_clusters,
                           size_t coordinates_size, ClusterWeights& cluster_weights)
{
  cluster_pts.push_back(std::vector<int32_t>());
  cluster_pts[*n_clusters].push_back(p);
  size_t ec_neighbors_size = ec_neighbor_pts->size();
  assert(ec_neighbors_size != 0);
  for (size_t i = 0; i < ec_neighbors_size; i++) {
    if (!visited_pts[ec_neighbor_pts->at(i)]){
      // mark point p as visited
      visited_pts[ec_neighbor_pts->at(i)] = true;
      ec_neighbor_pts_ = regionQuery(ec_neighbor_pts->at(i), coordinates_size, cluster_weights);
      if (ec_neighbor_pts_.size() >= cluster_weights.min_pts){
        ec_neighbor_pts->insert(ec_neighbor_pts->end(), ec_neighbor_pts_.begin(), ec_neighbor_pts_.end());
      }
      // mark point p as clustered
      clustered_pts[ec_neighbor_pts->at(i)] = true;
      // add any other points that haven't been clustered
      if (clustered_pts[ec_neighbor_pts->at(i)]) {
        cluster_pts[*n_clusters].push_back(ec_neighbor_pts->at(i));
      }
    }
  }
}

void DBSCAN::performClusterSearch(ClusterWeights& cluster_weights)
{
  size_t coordinates_size = coordinates[0]->lat_pts.size();
  for (size_t i = 0; i < coordinates_size; i++) {
    if (visited_pts[i]) {
      continue;
     } else {
       // mark point p as visited
       visited_pts[i] = true;
       rq_neighbor_pts = regionQuery(i, coordinates_size, cluster_weights);
       if (rq_neighbor_pts.size() < cluster_weights.min_pts) {
         noise_pts_.push_back(rq_neighbor_pts[i]);
       } else {
         n_clusters_++;
         // mark point p as clustered
         clustered_pts[i] = true;
         expandCluster(i, &rq_neighbor_pts, &n_clusters_, coordinates_size, cluster_weights);
       }
     }
   }
}

} // hotspot namespace
