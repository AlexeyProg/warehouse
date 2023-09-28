#include "menudialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MenuDialog dial;
    dial.exec();
    return a.exec();
}
