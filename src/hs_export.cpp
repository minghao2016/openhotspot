/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.3
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "hs_export.h"
#include "hs_logger.h"

namespace hotspot {

Export::Export(const std::string& _csv_file):
   csv_file(_csv_file)
{
}

void Export::exportPredictedData(unsigned int n_clusters, double center_lat,
                                 double center_long, std::string c_type)
{
   std::ofstream prediction_file(csv_file, std::ofstream::out | std::ofstream::app);
   if (!prediction_file.is_open()){
      std::cout << "Error: Could not write prediction file." << std::endl;
      exit(EXIT_FAILURE);
   } else {
   }
}

} // hotspot namespace
