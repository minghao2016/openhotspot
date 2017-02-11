/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#include "metrics.h"

namespace hotspot {

double Metrics::degreesToRadians(double degrees) {return degrees * 3.14159 / 180;}

double Metrics::haversineDistanceMetric(MetricCoordinates& _mc)
{
  double dlat_1 = degreesToRadians(_mc.lat_1);
  double dlong_1 = degreesToRadians(_mc.long_1);
  double dlat_2 = degreesToRadians(_mc.lat_2);
  double dlong_2 = degreesToRadians(_mc.long_2);
  double a = sin((dlat_2 - dlat_1) / 2);
  double b = sin((dlong_2 - dlong_1) / 2);
  return 2 * 6371 * asin(sqrt(a * a + cos(dlat_1) * cos(dlat_2) * b * b));
}

} // hotspot namespace
