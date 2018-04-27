#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = 0);
    ~ClientWindow();

private slots:
    void on_NavigateBoard_clicked();

    void on_MakeSuggestion_clicked();

    void on_Refute_clicked();

    void on_MakeAccusation_clicked();

    void on_ViewNotebook_clicked();

    void on_EndTurn_clicked();

private:
    Ui::ClientWindow *ui;
};

#endif // CLIENTWINDOW_H
