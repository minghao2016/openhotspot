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

#include "parser.h"

namespace canalysis {

Parser::Parser()
{
}

std::string Parser::operator[](unsigned int column)
{
   return file_data[column];
}

std::string Parser::getColumnFields(std::istream &csvfile)
{
   file_data.clear();
   std::getline(csvfile, row);
   std::istringstream stream(row);
   while (std::getline(stream, line_values)){
      boost::escaped_list_separator<char> separator;
      boost::tokenizer<boost::escaped_list_separator<char> > token(line_values, separator);
      for (auto t : token){
         file_data.push_back(t);
      }
   }
}

}
