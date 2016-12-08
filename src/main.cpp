/*
 * BSD 3-Clause License
 * Canalysis v0.0.1 Alpha
 * Copyright (c) 2016, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

// main.cpp file just holds command line arguments.
// The file canalysis.cpp is the file that holds
// the actual model of the framework.

#include <fstream>
#include <sstream>
#include <iostream>

#include "canalysis.h"

#include "predict.h"

using namespace canalysis;

void usage(){
   std::cout
   << "usage: ./olivia [--file] [--crime-column-number]\n"
   << "                [--lat-column-number] [--long-column-number]\n"
   << "                [--train-model] [--version]\n\n"
   << "These are the current Canalysis commands to use:\n\n"
   << "  --file                    name of CSV file to classify\n"
   << "  --crime-column-number     the specific crime column number\n"
   << "  --lat-column-number       the specific lat column number\n"
   << "  --long-column-number      the specific long column number\n"
   << "  --train-model             train the neural network model\n"
   << "  --version                 the current version of Canalysis\n"
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
   if (_argv == "--file"){
   }
   if (_argv == "--crime-column"){
   }
   if (_argv == "--lat-column"){
   }
   if (_argv == "--long-column"){
   }
   if (_argv == "--train-model"){
   }
   if (_argv == "--version"){
      get_version();
   }*/

   Canalysis canalysis("../test.csv", 0, 1, 2, 60, 70);
   canalysis.model();
}
