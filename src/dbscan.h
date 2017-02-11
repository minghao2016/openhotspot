/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#ifndef _DBSCAN_H_
#define _DBSCAN_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <assert.h>

struct Coordinates {
  std::vector<double> lat_pts;
  std::vector<double> long_pts;
};

struct ClusterWeights {
  float eps;
  unsigned int min_pts;
  std::string dist_metric;
};

namespace hotspot {

class DBSCAN {
private:
  std::vector<Coordinates*> coordinates;

  ClusterWeights& cluster_weights;

  int32_t n_clusters_;

  std::vector<uint32_t> rq_pts;
  std::vector<uint32_t> noise_pts_;

  std::vector<bool> visited_pts;
  std::vector<bool> clustered_pts;
  std::vector<std::vector<int32_t> > cluster_pts;

public:
  DBSCAN(std::vector<Coordinates*>, ClusterWeights&);
  ~DBSCAN();

  void markPoints(size_t);

  float error();
  uint32_t n_clusters();
  std::vector<uint32_t> noise_pts();

  void epsEstimation(uint32_t, size_t);
  void minptsEstimation(size_t);

  void getClusterCenterPoint();
  std::vector<uint32_t> regionQuery(uint32_t, size_t);
  void expandCluster(uint32_t, std::vector<uint32_t>*, int32_t*, size_t);
  void performClusterSearch();
};

}

#endif
