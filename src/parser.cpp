/*
 * BSD 3-Clause License
 * Canalysis v0.0.1 Beta
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

Parser::~Parser()
{
}

void canalysis::Parser::get_column_fields(std::istream &csvfile)
{
   file_data.clear();
   std::getline(csvfile, row);
   std::stringstream stream(row);
   while (getline(stream, column_value)){
      boost::escaped_list_separator<char> separator;
      boost::tokenizer<boost::escaped_list_separator<char> > token(column_value, separator);

      for (auto t : token){
         file_data.push_back(t);
      }
   }
}

int canalysis::Parser::get_column_length(std::istream &csvfile)
{
   file_data.clear();
   std::getline(csvfile, row);
   std::stringstream stream(row);
   while (getline(stream, column_value)){
   }
}

}
