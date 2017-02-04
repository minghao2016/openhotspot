/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _HS_REFORMAT_H_
#define _HS_REFORMAT_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

namespace hotspot
{

class Reformat {
private:
   std::string row;
   std::string line;
   std::vector<std::string> column_data;

public:
   std::string operator[](unsigned int);
   void getColumn(std::istream&);
};

}

#endif
