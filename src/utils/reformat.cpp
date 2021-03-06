/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#include "reformat.h"

#include <boost/tokenizer.hpp>

namespace hotspot {
/*
* @brief See: http://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c/1120224#1120224
* For more information on this source.
*/
std::string Reformat::operator[](unsigned int column) { return column_data[column]; }

void Reformat::getColumn(std::istream& file)
{
  column_data.clear();
  std::getline(file, row);
  std::istringstream stream(row);
  while (std::getline(stream, line)){
    boost::escaped_list_separator<char> delimiter;
    boost::tokenizer<boost::escaped_list_separator<char> > token(line, delimiter);
    for (auto t : token){
      column_data.push_back(t);
    }
  }
}

} // hotspot namespace
