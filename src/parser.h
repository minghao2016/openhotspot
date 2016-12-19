/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _PARSER_H_
#define _PARSER_H_

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <fstream>
#include <list>

namespace canalysis {

class Parser {
private:
   std::string row;
   std::string line_values;
   std::vector<std::string> file_data;

public:
   std::string operator[](unsigned int);
   void getColumnFields(std::istream&);
};

}

#endif
