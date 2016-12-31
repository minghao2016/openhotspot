#ifndef _TEST_HS_LAYER_H_
#define _TEST_HS_LAYER_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <math.h>
#include <map>

#include "../src/hs_utils.h"

#define PI 3.14159265
#define EARTH_RADIUS 6371

namespace hotspot {

class Layer {
private:
   std::vector<Coordinates> clusters;

   std::vector<NeighborPts> neighbor_pts;
   std::vector<NoisePts> noise_pts;
   std::vector<VistedPts> visted_pts;

   std::vector<int> output_pts;
   std::vector<OutputCenters> output_centers;
   std::vector<std::string> output_types;

public:
   Layer(std::vector<Coordinates>);
   ~Layer();

   double degreesToRadians(double);
   double haversineMetric(double, double, double, double);
   //double euclideanMetric(double, double, double, double);

   void reduceLatValues();
   void reduceLongValues();
   utils_tuple dbscan(float, unsigned int);
   void expandCluster(unsigned int, double, float, unsigned int);
   double regionQuery(unsigned int, float);


};

}

#endif
