#include "test_hs_layer.h"

namespace hotspot {

Layer::Layer(std::vector<Coordinates> _clusters):
   clusters(_clusters)
{
}

Layer::~Layer()
{
}

double Layer::degreesToRadians(double degrees)
{
   return degrees * PI / 180;
}

double Layer::haversineMetric(double lat_v1, double lat_v2, double long_v1, double long_v2)
{
   double dlat_1 = degreesToRadians(lat_v1);
   double dlong_1 = degreesToRadians(long_v1);
   double dlat_2 = degreesToRadians(lat_v2);
   double dlong_2 = degreesToRadians(long_v2);
   double a = sin((dlat_2 - dlat_1) / 2);
   double b = sin((dlong_2 - dlong_1) / 2);
   return 2 * EARTH_RADIUS * asin(sqrt(a * a + cos(dlat_1) * cos(dlat_2) * b * b));
}

void Layer::reduceLatValues()
{
}

void Layer::reduceLongValues()
{
}

utils_tuple Layer::dbscan(float eps, unsigned int min_pts)
{
   double c = 0.0;
   int dataset_size = clusters[0].lat_pts.size();
   for (unsigned int i = 0; i < dataset_size; ++i){
   }
}

void Layer::expandCluster(unsigned int p, double c, float eps, unsigned int min_pts)
{
}

double Layer::regionQuery(unsigned int p, float eps)
{
   int dataset_size = clusters[0].lat_pts.size();
   for (unsigned int i = 0; i < dataset_size; ++i){
      if (haversineMetric(clusters[0].lat_pts[i], clusters[1].long_pts[i],
                          clusters[0].lat_pts[p], clusters[1].long_pts[p]) <= eps){
      }
   }
}

} // hotspot namespace
