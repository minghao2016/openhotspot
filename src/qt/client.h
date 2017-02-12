/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <iostream>
#include <vector>
#include <string>

#include <QMainWindow>
//#include <QWebFrame>
//#include <QWebView>

namespace Ui {
  class Client;
}

namespace hotspot {

namespace qt {

class Client : public QMainWindow {
  Q_OBJECT

private:
  Ui::Client* ui;

public:
  explicit Client(QWidget*);
  ~Client();
};

}

}

#endif
