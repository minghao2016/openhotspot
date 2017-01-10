/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.2
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

struct OutputCoordinateCenters {
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
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
   int c;

   std::vector<Coordinates> coordinates;
   std::vector<std::vector<Coordinates> > clusters;

   std::vector<int> rq_neighbor_pts;
   std::vector<int> rq_pts;

   std::vector<int> border_pts;
   std::vector<int> noise_pts;
   std::vector<bool> visted_pts;

   std::vector<OutputCoordinateCenters> output_coordinates;
   std::vector<int> output_types;

public:
   DBSCAN();
   DBSCAN(std::vector<Coordinates>);
   ~DBSCAN();

   double radiansToDegrees(double);
   double degreesToRadians(double);
   double haversineMetric(Metric*);
   double euclideanMetric(Metric*);

   void reduceLatValues(unsigned int);
   void reduceLongValues(unsigned int);
   utils_tuple dbscan(double, unsigned int, const std::string&);
   std::vector<int> regionQuery(unsigned int, double, const std::string&);
   std::vector<std::string> clusterType(OutputCoordinateCenters*);
   float computeErrorCoverage();
};

}

#endif
