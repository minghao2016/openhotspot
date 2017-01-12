/*
 * BSD 3-Clause License
 * OpenHotSpot Framework 0.1.3
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

// main.cpp file just holds command line arguments.
// The file hotspot.cpp is the file that holds
// the actual model of the framework.

#include "hotspot.h"

using namespace hotspot;

void usage()
{
   std::cout
   << "usage: ./hotspot [--lat-file] [--long-file] [--reformat-file]\n"
   << "                 [--crime-column] [--lat-column] [--long-column]\n"
   << "                 [--eps] [--min-pts] [--min-samples] [--distance-metric]\n"
   << "                 [--crime-percentage] [--version]\n"
   << "\nFile Handler:\n"
   << "  --lat-file                <lat filename> Reformated latitude file.\n"
   << "  --long-file               <long filename> Reformated longitude file.\n"
   << "\nReformat Data:\n"
   << "  --reformat-file           <csv filename> Reformat criminal CSV data.\n"
   << "  --crime-column            CSV crime column number.\n"
   << "  --lat-column              CSV latitude column number.\n"
   << "  --long-column             CSV longitude column number.\n"
   << "\nCluster Parameters:\n"
   << "  --eps                     [default: 1.7 = 1700m] Distance between two points to form cluster.\n"
   << "  --min-pts                 [default: 800] Minimum points in a cluster.\n"
   << "  --distance-metric         [default: haversine] Metric used to calculate distance.\n"
   << "\nTerminal View:\n"
   << "  --crime-percentage        <crime filename> View the percentages of crimes.\n"
   << "  --version                 Current version of OpenHotSpot.\n"
   << "\nExample Usage:\n"
   << "  ./hotspot --lat-file latitudes.txt --long-file longitudes.txt --crime-file crimes.txt\n"
   << "  --eps 3.3 --min-pts 800 --distance-metric haversine\n"
   << "  ./hotspot --reformat-file dataset.csv --crime-column 1 --lat-column 10 --long-column 9\n"
   << "  ./hotspot --crimePercentage crimes.txt"
   << std::endl;
}

int main(int argc, char **argv)
{
   /*if (argc <= 1) {
      usage();
   }

   std::string _argv = argv[1];
   if (_argv == "--help"){
      usage();
   }
   else if (_argv == "--lat-file"){
   }
   else if (_argv == "--long-file"){
   }
   else if (_argv == "--reformat-file"){
   }
   else if (_argv == "--crime-column"){
   }
   else if (_argv == "--lat-column"){
   }
   else if (_argv == "--long-column"){
   }
   else if (_argv == "--eps"){
   }
   else if (_argv == "--min-pts"){
   }
   else if (_argv == "--distance-metric"){
   }
   else if (_argv == "--crime-percentage"){
   }
   else if (_argv == "--version"){
      std::cout << version << std::endl;
   }*/
   HotSpot hotspot;
   hotspot.loadModel("../data/test_latitudes.txt", "../data/test_longitudes.txt",
                     1.7, 800, "haversine");
   //hotspot.reformat("../data/test_sf_dataset.csv", 1, 10, 9);
}
