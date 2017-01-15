/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.3
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

namespace hotspot {

class Export {
private:
   const std::string& csv_file;

public:
   Export(const std::string&);
   void exportPredictedData(unsigned int, double, double, std::string);
};

}

#endif
