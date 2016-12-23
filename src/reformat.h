/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.1
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _REFORMAT_H_
#define _REFORMAT_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

namespace canalysis {

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
