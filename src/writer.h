/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.1
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

class Writer {
private:
   std::ofstream prediction_file;

public:
   Writer(const std::string);
   void exportData(unsigned int, double, double, unsigned int);
};

}

#endif
