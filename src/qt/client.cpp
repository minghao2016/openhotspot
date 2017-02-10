/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#include "client.h"
#include "dashboard.h"
#include "trending.h"

#include "ui_client.h"

#include "../types.h"

namespace hotspot {

Client::Client(QWidget* parent):
   QMainWindow(parent),
   ui(new Ui::Client)
{
   ui->setupUi(this);
}

Client::~Client()
{
   delete ui;
}

} // hotspot namespace
