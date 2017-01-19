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

struct ModelWeights {
   std::vector<int> date_pts;
   std::vector<std::string> crime_names;
};

struct PredictedCoordinates {
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

namespace HotSpot {

class Model {
private:
   std::vector<std::vector<Coordinates> > clusters;

public:
   Model(std::vector<std::vector<Coordinates> >);
   ~Model();
   std::vector<int> crimeFrequency();
   std::vector<PredictedCoordinates> predict();
   float computeAccuracyRate();
   float computeLoss();
};

}

#endif
