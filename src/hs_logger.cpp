/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.4
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "hs_logger.h"

namespace hotspot {

std::string Logger::logLevel(Level& level)
{
   if (level == ERROR_LOG){
      std::cout << "";
   } else if (level == WARNING_LOG){
      std::cout << "";
   } else if (level == INFO_LOG){
      std::cout << "";
   } else if (level == DEBUG_LOG) {
      std::cout << "";
   } else if (level == TRACE_LOG) {
      std::cout << "";
   }
}

} // hotspot namespace
