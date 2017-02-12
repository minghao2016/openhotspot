/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#include "clientmap.h"
#include "ui_clientmap.h"

namespace hotspot {

namespace qt {

ClientMap::ClientMap(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::ClientMap)
{
  ui->setupUi(this);
}

ClientMap::~ClientMap()
{
  delete ui;
}

}

}
