/*
 * BSD 3-Clause License
 * Canalysis v0.0.1 Alpha
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

// Parts of this CSV parser were taken from stackoverflow found here:
// http://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c

#ifndef _PARSER_H_
#define _PARSER_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include <boost/tokenizer.hpp>

#include "utils.h"

namespace canalysis {

class Parser {
private:
   std::string row;
   std::string column_value;
   std::vector<std::string> file_data;

public:
   std::string operator[](int column){return file_data[column];}
   void getColumnFields(std::istream &csvfile);
};

}

#endif
