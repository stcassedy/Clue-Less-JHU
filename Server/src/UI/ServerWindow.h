/**
  * @file ServerWindow.h
  */
#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include <ServerManager.h>

//declares UI namespace
namespace Ui {
class ServerWindow;
}

class ServerManager;

/**
 * @brief The ServerWindow class is a simple UI class for starting and stopping
 * the Server Application.
 */
class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief ServerWindow Explicit Constructor
     * @param parent QWidget
     */
    explicit ServerWindow(QWidget *parent = 0);

    /**
      * @brief ~ServerWindow Destructor
      */
    ~ServerWindow();

    void Notify(QString note);
    void setAddress(QString address);
    void setPort(QString port);

private slots:
    /**
     * @brief on_serverStartStop_toggled Handles the user toggling start/stop
     * @param checked bool true if checked, false otherwise
     */
    void on_serverStartStop_toggled(bool checked);

private:
    //Member Variables
    Ui::ServerWindow *m_ui;
    ServerManager * serverManager_;
};

#endif // SERVERWINDOW_H
