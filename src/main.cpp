/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#include "hotspot.h"

using namespace hotspot;

void usage()
{
   std::cout
   << "usage: ./hotspot [--crime-file] [--date-file] [--lat-file]\n"
   << "                 [--long-file] [--reformat-file] [--crime-column]\n"
   << "                 [--date-column] [--lat-column] [--long-column]\n"
   << "                 [--eps] [--min-pts] [--distance-metric] [--crime-rate]\n"
   << "\nFile Handler:\n"
   << "  --crime-file              <crime filename> Reformatted crime file.\n"
   << "  --date-file               <date filename> Reformatted date file.\n"
   << "  --lat-file                <lat filename> Reformatted latitude file.\n"
   << "  --long-file               <long filename> Reformatted longitude file.\n"
   << "Reformat Data:\n"
   << "  --reformat-file           <csv filename> Reformat criminal CSV data.\n"
   << "  --crime-column            CSV crime column number.\n"
   << "  --date-column             CSV date column number.\n"
   << "  --lat-column              CSV latitude column number.\n"
   << "  --long-column             CSV longitude column number.\n"
   << "Cluster Weights:\n"
   << "  --eps                     [default: 1.7 = 1700m] Distance between two points to form cluster.\n"
   << "  --min-pts                 [default: 1000] Minimum points in a cluster.\n"
   << "  --distance-metric         [default: haversine] Metric used to calculate distance.\n"
   << "Model Weights:\n"
   << "Terminal View:\n"
   << "  --crime-rate              <crime filename> View the percentages of crimes.\n"
   << "  --version                 Current version of OpenHotspot."
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
      std::cout << VERSION_DESCRIPTION << std::endl;
   }*/
   HotSpot hotspot;
   hotspot.loadModel("../data/test_dates.txt", "../data/test_latitudes.txt",
                     "../data/test_longitudes.txt", 1.7, 1000, "haversine");
}
