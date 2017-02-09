/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#ifndef _HOTSPOT_H_
#define _HOTSPOT_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <memory>
#include <set>
#include <iomanip>

#include "dbscan.h"
#include "model.h"

#include "utils/export.h"

struct Files {
   std::string days_file;
   std::string lat_file;
   std::string long_file;
   std::string crimes_file;
   std::string csv_file;
};

struct Columns {
   unsigned int days_column;
   unsigned int lat_column;
   unsigned int long_column;
   unsigned int crimes_column;
};

namespace hotspot {

class Hotspot {
private:
   std::vector<double> lat_values;
   std::vector<double> long_values;
   std::vector<std::string> crime_values;
   std::vector<std::string> day_values;

   std::vector<Coordinates*> cluster_coordinates;

public:
   void reformatCSVFile(const Files&, Columns);
   void printCrimeRate(const Files&);

   Coordinates* addCoordinates();
   DBSCAN addClusterWeights(ClusterWeights&);
   Model addModelWeights();
   PredictedData addPredictedData(Coordinates*, DBSCAN);

   void launchWebClient();
   void prediction(const Files&, ClusterWeights&);
};

}

#endif
