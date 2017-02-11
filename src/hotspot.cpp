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
#include "types.h"

//#include "qt/client.h"

#include "utils/reformat.h"

#include "version.h"

namespace hotspot {

std::istream& operator>>(std::istream& file, Reformat& reformat)
{
  reformat.getColumn(file);
  return file;
}

void Hotspot::reformatCSVFile(std::string csv_file, Columns columns)
{
  Reformat reformat;
  std::ifstream if_csv(csv_file);
  if (!if_csv.is_open()) {
    std::printf("ERROR: Could not open CSV file.\n");
    exit(EXIT_FAILURE);
   } else {
     while (if_csv >> reformat) {
       std::string crimes_column = reformat[columns.crimes_column];
       std::string days_column = reformat[columns.days_column];
       std::string lat_column = reformat[columns.lat_column];
       std::string long_column = reformat[columns.long_column];
       std::ofstream exported_crimes(CRIMES_FILE, std::ofstream::out | std::ofstream::app);
       if (!exported_crimes.is_open()) {
         std::printf("ERROR: Could not write crimes file.\n");
         exit(EXIT_FAILURE);
       } else {
         exported_crimes << crimes_column << std::endl;
       }
       std::ofstream exported_days(C_DAYS_FILE, std::ofstream::out | std::ofstream::app);
       if (!exported_days.is_open()) {
         std::printf("ERROR: Could not write c_dates file.\n");
         exit(EXIT_FAILURE);
       } else {
         exported_days << days_column << std::endl;
       }
       std::ofstream exported_lat(C_LATITUDES_FILE, std::ofstream::out | std::ofstream::app);
       if (!exported_lat.is_open()) {
         std::printf("ERROR: Could not write c_latitudes file.\n");
         exit(EXIT_FAILURE);
       } else {
         exported_lat << lat_column << std::endl;
       }
       std::ofstream exported_long(C_LONGITUDES_FILE, std::ofstream::out | std::ofstream::app);
       if (!exported_long.is_open()) {
         std::printf("ERROR: Could not write c_longitudes file.\n");
         exit(EXIT_FAILURE);
       } else {
         exported_long << long_column << std::endl;
       }
     }
   }
}

void Hotspot::printCrimeRate()
{
  std::ifstream if_crime(CRIMES_FILE);
  if (!if_crime.is_open()) {
    std::printf("ERROR: Could not open crimes file.\n");
    exit(EXIT_FAILURE);
  } else {
    std::string temp_crime;
    while (if_crime >> temp_crime) {
      crime_values.push_back(temp_crime);
    }
    std::cout << "Crime Percentages" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::set<std::string> unique_crimes(crime_values.begin(), crime_values.end());
    for (auto crimes : unique_crimes) {
      int crime_vectors = count(crime_values.begin(), crime_values.end(), crimes);
      double percentage = static_cast<double>(crime_vectors) / static_cast<double>(crime_values.size()) * 100;
      std::cout << std::setprecision(3) << crimes << ": " << percentage << "%" << std::endl;
    }
  }
}

Coordinates* Hotspot::addCoordinates()
{
  Coordinates* coordinates = new Coordinates;
  coordinates->lat_pts = lat_values;
  coordinates->long_pts = long_values;
  cluster_coordinates.push_back(coordinates);
  return coordinates;
}

DBSCAN Hotspot::addClusterWeights(ClusterWeights& cluster_weights, Coordinates* coordinates)
{
  DBSCAN dbscan(cluster_coordinates, cluster_weights);
  //for (uint32_t i = 0; i < coordinates->lat_pts.size(); i++) {
  //  dbscan.epsEstimation(i);
  //  dbscan.minptsEstimation();
  //}
  dbscan.performClusterSearch();
  dbscan.getClusterCenterPoint();
  return dbscan;
}

Model Hotspot::addModelWeights()
{
  Model model(cluster_coordinates);
  ModelWeights model_weights;
  model_weights.c_days = day_values;
  return model;
}

PredictedData Hotspot::addPredictedData(Coordinates* coordinates, DBSCAN dbscan)
{
  PredictedData p_data;
  p_data.n_clusters = dbscan.n_clusters();
  p_data.core_lat = coordinates->lat_pts;
  p_data.core_long = coordinates->lat_pts;
  std::vector<uint32_t> noise_pts = dbscan.noise_pts();
  for (uint32_t i = 0; i < coordinates->lat_pts.size(); i++) {
    //p_data.noise_lat[i] = coordinates->lat_pts[i];
    //p_data.noise_long[i] = coordinates->long_pts[i];
  }
  return p_data;
}

/*QApplication Hotspot::launchClient()
{
  QApplication qa;
  qt::Client client;
  client.show();
  return qa.exec();
}*/

void Hotspot::prediction(ClusterWeights& cluster_weights)
{
  std::ifstream if_days(C_DAYS_FILE);
  if (!if_days.is_open()) {
    std::printf("ERROR: Could not open c_days file.\n");
    exit(EXIT_FAILURE);
  } else {
    while (if_days >> temp_days) {
      day_values.push_back(temp_days);
    }
    day_values.erase(day_values.begin());
  }
  std::ifstream if_lat(C_LATITUDES_FILE);
  if (!if_lat.is_open()) {
    std::printf("ERROR: Could not open c_latitudes file.\n");
    exit(EXIT_FAILURE);
  } else {
    while (if_lat >> temp_lat) {
      double vector_lat = atof(temp_lat.c_str());
      lat_values.push_back(vector_lat);
    }
    lat_values.erase(lat_values.begin());
  }
  std::ifstream if_long(C_LONGITUDES_FILE);
  if (!if_long.is_open()) {
    std::printf("ERROR: Could not open c_longitudes file.\n");
    exit(EXIT_FAILURE);
  } else {
    while (if_long >> temp_long) {
      double vector_long = atof(temp_long.c_str());
      long_values.push_back(vector_long);
    }
    long_values.erase(long_values.begin());
  }
  Coordinates* coordinates = addCoordinates();
  DBSCAN dbscan = addClusterWeights(cluster_weights, coordinates);
  PredictedData prediction = addPredictedData(coordinates, dbscan);
  //Export csv_export(PREDICTION_FILE);
  //std::printf("INFO: Saving predicted cluster to '%s'.\n", PREDICTION_FILE);
  //csv_export.save(prediction);
}

} // hotspot namespace
