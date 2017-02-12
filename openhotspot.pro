QT+=core gui
greaterThan(QT_MAJOR_VERSION, 4): QT+=widgets
TARGET=hotspot
TEMPLATE=app
CONFIG-=app_bundle

SOURCES+=src/main.cpp \
         src/hotspot.cpp \
         src/qt/client.cpp \
         src/qt/dashboard.cpp \
         src/qt/trending.cpp

HEADERS+=src/hotspot.h \
         src/qt/client.h \
         src/qt/dashboard.h \
         src/qt/trending.h

FORMS+=src/qt/forms/client.ui \
       src/qt/forms/dashboard.ui \
       src/qt/forms/trending.ui \
