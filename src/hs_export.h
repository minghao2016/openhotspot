/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.1
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _HS_EXPORT_H_
#define _HS_EXPORT_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace hotspot {

class Export {
private:
   std::ofstream prediction_file;
   const std::string _csv_file;

public:
   Export(const std::string&);
   void exportPredictedData(unsigned int, double, double, unsigned int);
};

}

#endif
