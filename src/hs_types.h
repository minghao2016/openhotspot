/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.4
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

#define LATITUDES_FILE "../data/latitudes.txt"
#define LONGITUDES_FILE "../data/longitudes.txt"
#define CRIMES_FILE "../data/crimes.txt"
#define DATES_FILE "../data/dates.txt"
#define PREDICTION_FILE "../data/prediction.csv"

namespace hotspot {

typedef std::tuple<double, double, std::string> utils_tuple;

}

#endif
