/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#include "export.h"

namespace hotspot {

Export::Export(const std::string& _csv_file):
   csv_file(_csv_file),
   prediction_file(csv_file, std::ofstream::out | std::ofstream::app)
{
}

Export::~Export()
{
   if (!prediction_file.is_open()){
      std::printf("ERROR: Could not write prediction file.\n");
      exit(EXIT_FAILURE);
   }
}

void Export::save(PredictedData& p_data)
{
}

} // hotspot namespace
