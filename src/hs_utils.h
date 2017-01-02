/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.1
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _HS_UTILS_H_
#define _HS_UTILS_H_

#include <vector>
#include <tuple>

namespace hotspot {

struct Coordinates
{
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

struct OutputCenters
{
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

struct NoisePts
{
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

struct NeighborPts
{
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

struct BorderPts
{
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

struct VistedPts
{
   std::vector<bool> lat_pts;
   std::vector<bool> long_pts;
};

enum PriorityTypes
{
   critical = 1,
   major = 2,
   normal = 3,
   minor = 4
};

typedef std::tuple<unsigned int, double, double, unsigned int> utils_tuple;

}

#endif
