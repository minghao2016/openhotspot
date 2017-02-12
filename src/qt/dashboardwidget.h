/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#ifndef _DASHBOARDWIDGET_H_
#define _DASHBOARDWIDGET_H_

#include <QWidget>

#include "../types.h"

namespace hotspot {

namespace qt {

class DashboardWidget : public QWidget {
  Q_OBJECT

private:
  Ui::DashboardWidget* ui;

public:
  explicit DashboardWidget(QWidget* parent = 0);
  ~DashboardWidget();
};

}

}

#endif
