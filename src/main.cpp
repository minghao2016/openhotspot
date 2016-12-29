/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.1
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

// main.cpp file just holds command line arguments.
// The file hotspot.cpp is the file that holds
// the actual model of the framework.

#include "hotspot.h"

using namespace canalysis;

void usage(){
   std::cout
   << "usage: ./hotspot [--lat-file] [--long-file]\n"
   << "                 [--crime-file] [--reformat-file]\n"
   << "                 [--version]\n\n"
   << "These are the current OpenHotSpot commands to use:\n\n"
   << "  --lat-file                Reformated latitude file.\n"
   << "  --long-file               Reformated longitude file.\n"
   << "  --crime-file              Reformated crime file.\n"
   << "  --reformat-file           Reformat criminal CSV data.\n"
   << "  --crime-percentage        View the percentages of crimes.\n"
   << "  --version                 Current version of Canalysis\n"
   << std::endl;
}

int main(int argc, char **argv){
   /*if (argc <= 1) {
      usage();
   }
   std::string _argv = argv[1];
   if (_argv == "--help"){
      usage();
   }
   if (_argv == "--lat-file"){
   }
   if (_argv == "--long-file"){
   }
   if (_argv == "--crime-file"){
   }
   if (_argv == "--reformat-file"){
   }
   if (_argv == "--version"){
   }*/
   HotSpot hotspot;
   hotspot.model("../data/test_latitudes.txt", "../data/test_longitudes.txt");
   //hotspot.reformat("../data/test.csv", 1, 10, 9);
}
