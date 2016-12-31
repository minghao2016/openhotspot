/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.1
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "hs_export.h"

namespace hotspot {

Export::Export(const std::string& _csv_file):
   csv_file(_csv_file)
{
}

Export::~Export()
{
}

void Export::exportPredictedData(unsigned int n_clusters,
                                 double center_lat,
                                 double center_long,
                                 unsigned int pts)
{
}

} // hotspot namespace
