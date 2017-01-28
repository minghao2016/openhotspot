/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.4
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
#include <cmath>
#include <memory>

#include "hs_types.h"

struct Coordinates {
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

struct ClusterWeights {
   float eps;
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
   uint32_t n_clusters;

   std::vector<uint32_t> core_pts;
   std::vector<uint32_t> noise_pts;
   std::vector<std::vector<uint32_t> > cluseter_pts;

   std::vector<bool> visted_pts;
   std::vector<bool> clustered_pts;

   std::vector<uint32_t> neighbor_pts;
   std::vector<uint32_t> rq_pts;
   std::vector<uint32_t> rq_neighbor_pts;
   std::vector<uint32_t> ec_neighbor_pts_;

   std::vector<std::shared_ptr<Coordinates> > coordinates;
   std::vector<std::vector<Coordinates> > clusters;

public:
   DBSCAN(std::vector<std::shared_ptr<Coordinates> >);
   ~DBSCAN();

   double radiansToDegrees(double);
   double degreesToRadians(double);
   double haversineMetric(Metric&);
   double euclideanMetric(Metric&);

   float iterationTime();
   void clusterCenter(std::vector<std::vector<Coordinates*> >, unsigned int);
   std::vector<uint32_t> regionQuery(uint32_t, const ClusterWeights&);
   void expandCluster(uint32_t, std::vector<uint32_t>*, uint32_t*, const ClusterWeights&);
   std::vector<std::vector<Coordinates> > dbscan(const ClusterWeights&);
};

}

#endif
