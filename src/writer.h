/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _WRITER_H_
#define _WRITER_H_

#include <iostream>
#include <string>
#include <fstream>

namespace canalysis {

class Writer{
public:
   void exportData(std::string filename,
                   unsigned int clusters,
                   double center_lat,
                   double center_long,
                   unsigned int pts);

};

}

#endif
