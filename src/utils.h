/*
 * BSD 3-Clause License
 * Canalysis v0.0.1 Alpha
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
#include <math>

namespace canalysis {

int percent_conversion(std::string crime, int value, int total);
double sigmoid(double value);

}

#endif
