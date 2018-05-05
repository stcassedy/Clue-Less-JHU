#include "ClientWindow.h"
#include <QApplication>
#include "ClientManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Clue-Less");
    a.setApplicationDisplayName("Clue-Less");

    ClientWindow w;
    ClientManager::getInstance()->setClientWindow(&w);
    w.show();

    return a.exec();
}
