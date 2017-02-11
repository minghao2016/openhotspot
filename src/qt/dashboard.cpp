/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#include "dashboard.h"

#include "ui_dashboard.h"

#include "../types.h"

namespace hotspot {

namespace qt {

Dashboard::Dashboard(QWidget* parent):
  QWidget(parent),
  ui(new Ui::Dashboard)
{
  ui->setupUi(this);
}

Dashboard::~Dashboard()
{
  delete ui;
}

} // qt namespace

} // hotspot namespace
