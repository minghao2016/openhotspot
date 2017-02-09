/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#include "model.h"
#include "types.h"
#include "spatial_autocorrelation.h"

namespace hotspot {

Model::Model(std::vector<Coordinates*> _clusters):
   clusters(_clusters)
{
}

Model::~Model() {}

} // hotspot namespace
