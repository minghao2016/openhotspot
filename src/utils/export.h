/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#ifndef _HS_EXPORT_H_
#define _HS_EXPORT_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct PredictedData {
  int32_t n_clusters;
  std::vector<double> core_lat;
  std::vector<double> core_long;
  std::vector<double> noise_lat;
  std::vector<double> noise_long;
};

namespace hotspot {

class Export {
private:
  const std::string& csv_file;
  std::ofstream prediction_file;

public:
  Export(const std::string&);
  ~Export();
  void save(PredictedData&);
};

}

#endif
