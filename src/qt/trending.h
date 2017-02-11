/*
 * BSD 3-Clause License
 * OpenHotspot Framework 0.1.5
 * Copyright (c) 2017, Matt Perez, all rights reserved.
 *
 * This source is licensed under the BSD 3-Clause License.
 * The license can be found in the main directory for more
 * information about using this program.
*/
#ifndef _TRENDING_H_
#define _TRENDING_H_

#include <QWidget>

namespace Ui {
  class Trending;
}

namespace hotspot {

namespace qt {

class Trending : public QWidget {
  Q_OBJECT

private:
  Ui::Trending* ui;

public:
  explicit Trending(QWidget* parent);
  ~Trending();
};

}

}

#endif
