/**
  * @file ServerWindow.h
  */
#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>

//declares UI namespace
namespace Ui {
class ServerWindow;
}

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

private slots:
    /**
     * @brief on_serverStartStop_toggled Handles the user toggling start/stop
     * @param checked bool true if checked, false otherwise
     */
    void on_serverStartStop_toggled(bool checked);
    void on_numPlayers_valueChanged(int value);

private:
    //Member Variables
    Ui::ServerWindow *m_ui;
};

#endif // SERVERWINDOW_H
