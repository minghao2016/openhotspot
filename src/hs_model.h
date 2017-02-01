/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.4
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
#include <memory>

#include "hs_dbscan.h"

enum CrimeTypes {
   ASSAULT_CRIME,
   THEFT_CRIME,
   DRUG_CRIME,
   VANDALISM_CRIME,
   BURGLARY_CRIME,
   RAPE_CRIME,
   OTHER_CRIME
};

struct ModelWeights {
   std::vector<uint32_t> crime_dates;
   std::vector<std::string> crime_types;
};

struct PredictedCoordinates {
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

namespace HotSpot {

class Model {
private:
   std::vector<Coordinates*> clusters;

public:
   Model(std::vector<Coordinates*>);
   ~Model();
   std::vector<int> crimeFrequency(ModelWeights& weights);
   float computeAccuracyRate();
   float computeError();
};

}

#endif
