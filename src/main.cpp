/*
 * BSD 3-Clause License
 * Canalysis (Crime Analysis) 0.1.0
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

// main.cpp file just holds command line arguments.
// The file canalysis.cpp is the file that holds
// the actual model of the framework.

#include <iostream>
#include <fstream>
#include <sstream>

#include "canalysis.h"

using namespace canalysis;

void usage(){
   std::cout
   << "usage: ./canalysis [--lat-file] [--long-file]\n"
   << "                [--reformat-file] [--version]\n"
   << "These are the current Canalysis commands to use:\n\n"
   << "  --lat-file                Reformated latitude file.\n"
   << "  --long-file               Reformated longitude file.\n"
   << "  --reformat-file           Reformat criminal CSV data.\n"
   << "  --version                 Current version of Canalysis\n"
   << std::endl;
}

int main(int argc, char **argv){
   Canalysis canalysis;

   /*if (argc <= 1) {
      usage();
   }

   std::string _argv = argv[1];
   if (_argv == "--help"){
      usage();
   }
   if (_argv == "--reformat-file"){
   }
   if (_argv == "--lat-file"){
   }
   if (_args == "--long-file"){
   }
   if (_argv == "--version"){
      getVersion();
   }*/

   canalysis.model("../data/test_latitudes.txt", "../data/test_longitudes.txt");
}
