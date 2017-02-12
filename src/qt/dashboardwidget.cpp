/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#include "dashboardwidget.h"
#include "ui_dashboardwidget.h"

namespace hotspot {

namespace qt {

DashboardWidget::DashboardWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::DashboardWidget)
{
  ui->setupUi(this);
}

DashboardWidget::~DashboardWidget()
{
  delete ui;
}

}

}
