/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

namespace hotspot {

class Vector {
private:
public:
  Vector();
  ~Vector();
  float computeAccuracy();
  float computeError();
};

}

#endif
