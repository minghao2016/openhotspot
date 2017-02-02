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
   double long_1;
   double lat_2;
   double long_2;
};

namespace hotspot {

class DBSCAN {
private:
   std::vector<Coordinates*> coordinates;

   uint32_t n_clusters_;

   std::vector<uint32_t> core_pts_;
   std::vector<uint32_t> noise_pts_;

   std::vector<bool> visited_pts;
   std::vector<bool> clustered_pts;

   std::vector<uint32_t> rq_pts;

   std::vector<std::vector<uint32_t> > cluster_pts;

public:
   DBSCAN(std::vector<Coordinates*>);
   ~DBSCAN();

   std::vector<uint32_t> noise_pts();

   double degreesToRadians(double);
   double haversineMetric(Metric&);
   double euclideanMetric(Metric&);

   void clusterCenter();
   std::vector<uint32_t> regionQuery(uint32_t, const ClusterWeights&);
   void expandCluster(uint32_t, std::vector<uint32_t>*, uint32_t*, const ClusterWeights&);
   std::vector<Coordinates*> dbscan(const ClusterWeights&);
};

}

#endif
