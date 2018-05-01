#include "ClientWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Clue-Less");
    a.setApplicationDisplayName("Clue-Less");

    ClientWindow w;
    w.show();

    return a.exec();
}
