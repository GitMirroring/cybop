#include "cybolmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CybolMainWindow w;
    w.show();

    return a.exec();
}
