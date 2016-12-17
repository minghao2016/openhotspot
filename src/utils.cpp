/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include <iostream>

#include "utils.h"

namespace canalysis {

void percentConversion(std::string crime, int value, int total)
{
   float percent = value / total * 10;
   if (ceil(percent) == 0) {
      printf("%s - %.0f\n", crime.c_str(), percent);
   }
   else {
      printf("%s - %.1f\n", crime.c_str(), percent);
   }
}

double sigmoid(double value)
{
   return 1 / (1 + exp(-value));
}

double mean(double sum, int total)
{
   return sum / total;
}

void getVersion()
{
   std::cout << version << std::endl;
}

}
