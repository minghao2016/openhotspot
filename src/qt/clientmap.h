/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#ifndef _CLIENTMAP_H_
#define _CLIENTMAP_H_

#include <QMainWindow>
//#include <QWebFrame>
//#include <QWebView>

#include "../types.h"

namespace hotspot {

namespace qt {

class ClientMap : public QMainWindow {
  Q_OBJECT

private:
  Ui::ClientMap* ui;

public:
  explicit ClientMap(QWidget* parent = 0);
  ~ClientMap();
};

}

}

#endif
