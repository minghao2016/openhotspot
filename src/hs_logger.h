/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.4
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _HS_LOGGER_H_
#define _HS_LOGGER_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

enum Level {
   ERROR_LOG,
   WARNING_LOG,
   INFO_LOG,
   DEBUG_LOG,
   TRACE_LOG
};

namespace hotspot {

class Logger {
public:
   std::string logLevel(Level& level);
};

}

#endif
