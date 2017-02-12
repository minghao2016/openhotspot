QT+=core gui
greaterThan(QT_MAJOR_VERSION, 4): QT+=widgets
TARGET=OpenHotspot
TEMPLATE=app
CONFIG-=app_bundle

SOURCES+=main.cpp \
         clientmap.cpp \
         dashboardwidget.cpp \
         trendingwidget.cpp

HEADERS+=clientmap.h \
         dashboardwidget.h \
         trendingwidget.h

FORMS+=forms/clientmap.ui \
       forms/dashboardwidget.ui \
       forms/trendingwidget.ui
