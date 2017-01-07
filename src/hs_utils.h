/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.2
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _HS_UTILS_H_
#define _HS_UTILS_H_

#include <vector>
#include <tuple>
#include <utility>

namespace hotspot {

struct Coordinates {
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

struct OutputCoordinateCenters {
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

enum ClusterPriorityTypes {
   critical = 1,
   major = 2,
   normal = 3,
   minor = 4
};

enum OutputClusterTypes {
   border = 1,
   noise = 2,
   core = 3
};

typedef std::tuple<unsigned int, double, double, unsigned int> utils_tuple;
typedef std::pair<double, double> utils_pair;

}

#endif
