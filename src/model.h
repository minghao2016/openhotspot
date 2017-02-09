/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#ifndef _MODEL_H_
#define _MODEL_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <assert.h>

#include "dbscan.h"

enum CrimeTypes {
   AssaultCrime,
   TheftCrime,
   DrugCrime,
   VandalismCrime,
   BurglaryCrime,
   RapeCrime,
   OtherCrime
};

struct ModelWeights {
   std::vector<std::string> c_dates;
};

struct PredictedCoordinates {
   std::vector<double> lat_pts;
   std::vector<double> long_pts;
};

namespace hotspot {

class Model {
private:
   std::vector<Coordinates*> clusters;

public:
   Model(std::vector<Coordinates*>);
   ~Model();
   std::vector<uint32_t> getCrimeFrequency(ModelWeights& weights);
   std::vector<PredictedCoordinates> modelPrediction();
   float computeAccuracy();
   float computeError();
};

}

#endif
