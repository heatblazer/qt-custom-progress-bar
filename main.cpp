#include <QApplication>
#include "test-widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test t;
    t.showAll();
    return a.exec();
}
