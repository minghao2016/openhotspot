/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#ifndef _HS_TYPES_H_
#define _HS_TYPES_H_

#define CRIMES_FILE "../data/crimes.txt"
#define C_LATITUDES_FILE "../data/c_latitudes.txt"
#define C_LONGITUDES_FILE "../data/c_longitudes.txt"
#define C_DAYS_FILE "../data/c_days.txt"

#define PREDICTION_FILE "../data/prediction.csv"

#define MAP_JS "qt/js/client.js"
#define DASHBOARD_JS "qt/js/dashboard.js"
#define TRENDING_JS "qt/js/trending.js"

namespace Ui {
  class TrendingWidget;
  class DashboardWidget;
  class ClientMap;
}

#endif
