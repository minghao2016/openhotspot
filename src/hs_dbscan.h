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
#include <numeric>
#include <cmath>
#include <map>

#include "hs_utils.h"

struct Coordinates {
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

struct ClusterPoints {
   std::vector<bool> visted_pts;
   std::vector<int> border_pts;
   std::vector<int> noise_pts;
   std::vector<int> core_pts;

   std::vector<int> rq_pts;
   std::vector<int> rq_neighbor_pts;
   std::vector<int> ec_neighbor_pts_;
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
   unsigned int c;
   double eps;
   unsigned int min_pts;
   const std::string& dist_metric;

   std::vector<Coordinates>& coordinates;
   std::vector<std::vector<Coordinates> > clusters;

public:
   DBSCAN(std::vector<Coordinates>&, double, unsigned int, const std::string&);
   ~DBSCAN();

   double radiansToDegrees(double);
   double degreesToRadians(double);
   double haversineMetric(struct Metric*);
   double euclideanMetric(struct Metric*);

   void reduceLatValues(unsigned int);
   void reduceLongValues(unsigned int);
   std::vector<double> clusterCenter(std::vector<std::vector<Coordinates> >&,
                                     unsigned int);
   std::vector<std::string> clusterType(std::vector<std::vector<Coordinates> >&);
   std::vector<int> regionQuery(unsigned int, struct ClusterPoints*);
   std::vector<Coordinates>& expandCluster(unsigned int, std::vector<int>*, unsigned int*,
                                           struct ClusterPoints*);
   utils_tuple dbscan();
   float computeLoss();
};

}

#endif
