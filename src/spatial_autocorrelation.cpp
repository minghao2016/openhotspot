/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#include "spatial_autocorrelation.h"
#include "metrics.h"

namespace hotspot
{

SpatialAutocorrelation::SpatialAutocorrelation(std::vector<Coordinates*> _clusters):
   clusters(_clusters)
{
}

SpatialAutocorrelation::~SpatialAutocorrelation()
{
}

} // hotspot namespace
