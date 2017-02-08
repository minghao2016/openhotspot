/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#ifndef _HS_SPATIAL_AUTOCORRELATION_H_
#define _HS_SPATIAL_AUTOCORRELATION_H_

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

#include "dbscan.h"

namespace hotspot {

class SpatialAutocorrelation {
private:
   std::vector<Coordinates*> clusters;

public:
   SpatialAutocorrelation(std::vector<Coordinates*>);
   ~SpatialAutocorrelation();
};

}

#endif
