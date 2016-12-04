/*
 * BSD 3-Clause License
 * Canalysis v0.0.1 Alpha
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _CANALYSIS_H_
#define _CANALYSIS_H_

#include <iostream>
#include <tuple>

#include "parser.h"
#include "predict.h"
#include "version.h"
#include "utils.h"

using namespace std;

namespace canalysis {

class Canalysis {
private:
   std::string _csvfile;
   int _crime_coloumn;
   int _lat_column;
   int _long_column;

public:
   Canalysis(std::string csvfile,
             int crime_column,
             int lat_column,
             int long_column);
   ~Canalysis();
   void get_version();
   void model();
};

}

#endif
