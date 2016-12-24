/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.1
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "writer.h"

namespace canalysis {

Writer::Writer(const std::string csv_file) : _csv_file(csv_file)
{
}

void Writer::exportData(unsigned int clusters,
                        double center_lat,
                        double center_long,
                        unsigned int pts)
{
}

} // canalysis namespace
