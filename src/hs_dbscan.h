/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.2
 * Copyright (c) 2016, Matt Perez, all rights reserved.
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

namespace hotspot {

class DBSCAN {
private:
   const float PI = 3.14159265;
   const int EARTH_RADIUS = 6371;
   double c;

   std::vector<Coordinates> clusters;

   std::vector<double> neighbor_pts;
   std::vector<double> rq_neighbor_pts;
   std::vector<double> border_pts;
   std::vector<double> noise_pts;
   std::vector<bool> visted_pts;

   std::vector<OutputCenters> output_centers;
   std::vector<std::string> output_types;
   std::vector<int> output_pts;

public:
   DBSCAN();
   DBSCAN(std::vector<Coordinates>);
   virtual ~DBSCAN();

   double radiansToDegrees(double);
   double degreesToRadians(double);
   double haversineMetric(double, double, double, double);
   double euclideanMetric(double, double, double, double);

   void reduceLatValues(unsigned int);
   void reduceLongValues(unsigned int);
   utils_tuple dbscan(double, unsigned int, unsigned int, std::string);
   std::vector<OutputCenters> expandCluster(unsigned int, double, double,
                                            unsigned int, unsigned int);
   std::vector<int> regionQuery(unsigned int, double, std::string);
   float computeErrorRate();
   std::vector<std::string> clusterType(PriorityTypes*);
};

}

#endif
