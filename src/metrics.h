/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _METRICS_H_
#define _METRICS_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

struct MetricCoordinates
{
   double lat_1;
   double long_1;
   double lat_2;
   double long_2;
};

namespace hotspot
{

class Metrics
{
public:
   /*
   * @brief Degrees to radians conversion
   * @param degrees double Number of degrees to be converted
   */
   double degreesToRadians(double);
   /*
   * @brief Determines the great-circle distance between two points on a sphere given
   * their longitudes and latitudes; More Information: https://en.wikipedia.org/wiki/Haversine_formula
   * @param _mc MetricCoordinates struct containing lat/long values
   */
   double haversineDistanceMetric(MetricCoordinates&);
   /*
   * @brief Is the ordinary -- straight line -- distance between two points in the Euclidean space
   * More Information: https://en.wikipedia.org/wiki/Euclidean_distance
   * @param _mc MetricCoordinates struct containing lat/long values
   */
   double euclideanDistanceMetric(MetricCoordinates&);
};

}

#endif
