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
   << "usage: ./hotspot [--crime-file] [--date-file] [--lat-file] [--long-file]\n"
   << "                 [--reformat-file] [--crime-column] [--date-column] [--lat-column]\n"
   << "                 [--long-column] [--eps] [--min-pts] [--distance-metric] [--crime-rate]\n"
   << "                 [--version]\n"
   << "\nFile Handler:\n"
   << "  --crime-file              <crime filename> Reformatted crime file.\n"
   << "  --date-file             <date filename> Reformatted date file.\n"
   << "  --lat-file                <lat filename> Reformatted latitude file.\n"
   << "  --long-file               <long filename> Reformatted longitude file.\n"
   << "\nReformat Data:\n"
   << "  --reformat-file           <csv filename> Reformat criminal CSV data.\n"
   << "  --crime-column            CSV crime column number.\n"
   << "  --date-column             CSV date column number.\n"
   << "  --lat-column              CSV latitude column number.\n"
   << "  --long-column             CSV longitude column number.\n"
   << "\nCluster Parameters:\n"
   << "  --eps                     [default: 1.7 = 1700m] Distance between two points to form cluster.\n"
   << "  --min-pts                 [default: 1000] Minimum points in a cluster.\n"
   << "  --distance-metric         [default: haversine] Metric used to calculate distance.\n"
   << "\nTerminal View:\n"
   << "  --crime-rate              <crime filename> View the percentages of crimes.\n"
   << "  --version                 Current version of OpenHotSpot.\n"
   << "\nExample Usage:\n"
   << "  ./hotspot --reformat-file dataset.csv --crime-column 1 --date-column 2 --lat-column 4 --long-column 3\n"
   << "  ./hotspot --crime-file crimes.txt --dates-file dates.txt --lat-file latitudes.txt \
         --long-file longitudes.txt --eps 1.7 --min-pts 1000 --distance-metric haversine\n"
   << "  ./hotspot --crime-rate crimes.txt"
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
   else if (_argv == "--crime-file"){
   }
   else if (_argv == "--date-file"){
   }
   else if (_argv == "--lat-file"){
   }
   else if (_argv == "--long-file"){
   }
   else if (_argv == "--reformat-file"){
   }
   else if (_argv == "--crime-column"){
   }
   else if (_argv == "--date-column"){
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
   else if (_argv == "--crime-rate"){
   }
   else if (_argv == "--version"){
      std::cout << version << std::endl;
   }*/
   HotSpot hotspot;
   hotspot.loadModel("../data/test_dates.txt", "../data/test_latitudes.txt",
                     "../data/test_longitudes.txt", 1.7, 1000, "haversine");
}
