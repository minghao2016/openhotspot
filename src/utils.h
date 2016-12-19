/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

#include "version.h"

namespace canalysis {

void percentConversion(const std::string crime, unsigned int value, unsigned int total);
double mean(double sum, unsigned int total);
void getVersion();

}

#endif
