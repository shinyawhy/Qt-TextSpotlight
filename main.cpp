#include "textspotlightwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextSpotlightWidget w;
    w.resize(1000, 500);
    w.show();
    return a.exec();
}
