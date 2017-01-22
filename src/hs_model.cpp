/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.3
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "hs_model.h"

namespace HotSpot {

Model::Model(std::vector<std::vector<Coordinates> > _clusters):
   clusters(_clusters)
{
}

Model::~Model()
{
}

std::vector<int> Model::crimeFrequency()
{
}

std::vector<PredictedCoordinates> Model::predict()
{
}

float Model::computeAccuracyRate()
{
}

float Model::computeLoss()
{
}

} // hotspot namespace
