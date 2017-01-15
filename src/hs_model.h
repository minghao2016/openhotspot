/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.3
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _HS_MODEL_H_
#define _HS_MODEL_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "hs_dbscan.h"
#include "hs_utils.h"

struct Weights {
   std::vector<int> date_pts;
   std::vector<std::string> crime_names;
};

namespace HotSpot {

class Model {
private:

public:
   Model();
   ~Model();
   std::vector<float> crimeFrequency(std::vector<std::vector<Coordinates> >&);
   float computeAccuracyRate();
   float computeErrorCoverage();
};

}

#endif
