/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.1
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _HS_LAYER_H_
#define _HS_LAYER_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <math.h>
#include <map>

#include "hs_utils.h"

#define PI 3.14159265
#define EARTH_RADIUS 6371

namespace hotspot {

struct Coordinates {
   std::vector<double> lat_values;
   std::vector<double> long_values;
};

class Layer {
private:
   // Cluster variables
   std::vector<Coordinates> _clusters;
   std::vector<double> noise_pts;
   std::vector<double> neighbor_pts;
   std::vector<bool> visted_clusters;
   std::vector<std::string> clusters_types;

public:
   Layer(std::vector<Coordinates>);
   ~Layer();

   double degreesToRadians(double);
   double haversineMetric(double, double, double, double);
   double euclideanMetric(double, double, double, double);

   void reduceLatValues();
   void reduceLongValues();
   utils_tuple dbscan(unsigned int, unsigned int);
   void expandCluster(unsigned int, unsigned int, unsigned int, unsigned int);
   double regionQuery(unsigned int, unsigned int);
};

}

#endif
