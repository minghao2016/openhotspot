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

#define LATITUDES_FILE "../data/latitudes.txt"
#define LONGITUDES_FILE "../data/longitudes.txt"
#define CRIMES_FILE "../data/crimes.txt"
#define PREDICTION_FILE "../data/prediction.csv"
#define BORDER_CLUSTERS 1
#define NOISE_CLUSTERS 2
#define CORE_CLUSTERS 3
#define PRIORITY_CRITICAL 1
#define PRIORITY_MAJOR 2
#define PRIORITY_NORMA 3
#define PRIORITY_MINOR 4

namespace hotspot {

typedef std::pair<double, double> utils_pair;
typedef std::tuple<unsigned int, double, double, unsigned int> utils_tuple;

}

#endif
