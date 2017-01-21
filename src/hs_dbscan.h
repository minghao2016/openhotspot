/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.3
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _HS_DBSCAN_H_
#define _HS_DBSCAN_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory>

#include "hs_utils.h"

struct Coordinates {
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

struct ClusterWeights {
   double eps;
   unsigned int min_pts;
   std::string dist_metric;
};

struct Metric {
   double lat_1;
   double lat_2;
   double long_1;
   double long_2;
};

namespace hotspot {

class DBSCAN {
private:
   unsigned int c_clusters;

   std::vector<int> core_pts;
   std::vector<int> noise_pts;
   std::vector<bool> visted_pts;

   std::vector<bool> clustered_pts;

   std::vector<int> neighbor_pts;
   std::vector<int> rq_pts;
   std::vector<int> rq_neighbor_pts;
   std::vector<int> ec_neighbor_pts_;

   std::vector<std::shared_ptr<Coordinates> > coordinates;
   std::vector<std::vector<Coordinates*> > clusters;

   const ClusterWeights& cluster_weights;

public:
   DBSCAN(std::vector<std::shared_ptr<Coordinates> >, const ClusterWeights&);
   ~DBSCAN();

   double radiansToDegrees(double);
   double degreesToRadians(double);
   double haversineMetric(Metric&);
   double euclideanMetric(Metric&);

   void reduceLatValues(unsigned int);
   void reduceLongValues(unsigned int);
   std::vector<double> clusterCenter(std::vector<std::vector<Coordinates*> >, unsigned int);
   std::vector<int> regionQuery(unsigned int);
   std::vector<std::shared_ptr<Coordinates> > expandCluster(unsigned int, std::vector<int>*,
                                                            unsigned int*);
   utils_tuple dbscan();
   float iterationTime();
};

}

#endif
