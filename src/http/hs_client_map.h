/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.4
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/

#ifndef _HS_CLIENT_MAP_H_
#define _HS_CLIENT_MAP_H_

namespace hotspot {

class ClientMap {
public:
   ClientMap();
   ~ClientMap();
   void createMapJavaScript();
   void createDashboardJavaScript();
};

}

#endif