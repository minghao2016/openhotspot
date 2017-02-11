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

void usage() {
  std::cout
  << "usage: ./hotspot [--crime-file] [--days-file] [--lat-file]\n"
  << "                 [--long-file] [--reformat-file] [--crime-column]\n"
  << "                 [--days-column] [--lat-column] [--long-column]\n"
  << "                 [--eps] [--min-pts] [--distance-metric] [--crime-rate]\n"
  << "\nFile Handler:\n"
  << "  --crime-file              <crime filename> Reformatted crime file.\n"
  << "  --days-file               <days filename> Reformatted days file.\n"
  << "  --lat-file                <lat filename> Reformatted latitude file.\n"
  << "  --long-file               <long filename> Reformatted longitude file.\n"
  << "Reformat Data:\n"
  << "  --reformat-file           <csv filename> Reformat criminal CSV data.\n"
  << "  --crime-column            CSV crime column number.\n"
  << "  --days-column             CSV days column number.\n"
  << "  --lat-column              CSV latitude column number.\n"
  << "  --long-column             CSV longitude column number.\n"
  << "Cluster Weights:\n"
  << "  --eps                     [default: 0.5 = 500m] Distance between two points to form cluster.\n"
  << "  --min-pts                 [default: 1000] Minimum points in a cluster.\n"
  << "  --distance-metric         [default: haversine] Metric used to calculate distance.\n"
  << "Model Weights:\n"
  << "Terminal View:\n"
  << "  --crime-rate              <crime filename> View the percentages of crimes.\n"
  << "  --version                 Current version of OpenHotspot."
  << std::endl;
}

int main(int argc, char **argv) {
  /*Hotspot hotspot;
  Columns columns;
  ClusterWeights cluster_weights;
  if (argc <= 1 || _argv == "--help") usage();
  std::string _argv = argv[1];
  else if (_argv == "-crime-file" || _argv == "--crime-file") {
  }
  else if (_argv == "-days-file" || _argv == "--days-file") {
  }
  else if (_argv == "-lat-file" || _argv == "--lat-file") {
  }
  else if (_argv == "-long-file" || _argv == "--long-file") {
  }
  else if (_argv == "-reformat-file" || _argv == "--reformat-file") {
  }
  else if (_argv == "-crime-column" || _argv == "--crime-column") {
  }
  else if (_argv == "-date-column" || _argv == "--date-column") {
  }
  else if (_argv == "-lat-column" || _argv == "--lat-column") {
  }
  else if (_argv == "-long-column" || _argv == "--long-column") {
  }
  else if (_argv == "-eps" || _argv == "--eps") {
  }
  else if (_argv == "-min-pts" || _argv == "--min-pts") {
  }
  else if (_argv == "-distance-metric" || _argv == "--distance-metric") {
  }
  else if (_argv == "-crime-rate" || _argv == "--crime-rate") {
    files.crimes_file = _argv[1];
    hotspot.printCrimeRate(files);
  }
  else if (_argv == "-version" || (_argv == "--version") {
    std::cout << VERSION_DESCRIPTION << std::endl;
  }*/
  Columns columns;
  columns.days_column = 3;
  columns.lat_column = 10;
  columns.long_column = 9;
  columns.crimes_column = 1;
  ClusterWeights cluster_weights;
  cluster_weights.eps = 0.5;
  cluster_weights.min_pts = 1000;
  cluster_weights.dist_metric = "haversine";
  Hotspot hotspot;
  hotspot.prediction(cluster_weights);
  //hotspot.reformatCSVFile("../data/test_sf_dataset.csv", columns);
}
