#include "clientmap.h"
#include <QApplication>

using namespace hotspot::qt;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientMap w;
    w.show();
    return a.exec();
}
