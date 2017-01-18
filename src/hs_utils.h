/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.3
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _HS_UTILS_H_
#define _HS_UTILS_H_

#include <tuple>
#include <utility>

#define LATITUDES_FILE "../data/hs_latitudes.txt"
#define LONGITUDES_FILE "../data/hs_longitudes.txt"
#define CRIMES_FILE "../data/hs_crimes.txt"
#define DATES_FILE "../data/hs_dates.txt"
#define PREDICTION_FILE "../data/prediction.csv"
#define CORE_CLUSTERS 1
#define NOISE_CLUSTERS 2

namespace hotspot {

typedef std::pair<double, double> utils_pair;
typedef std::tuple<unsigned int, double, double, std::string> utils_tuple;

}

#endif
