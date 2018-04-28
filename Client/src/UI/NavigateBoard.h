#ifndef NAVIGATEBOARD_H
#define NAVIGATEBOARD_H

#include <QDialog>

namespace Ui {
class NavigateBoard;
}

class NavigateBoard : public QDialog
{
    Q_OBJECT

public:
    explicit NavigateBoard(QWidget *parent = 0);
    ~NavigateBoard();

private:
    Ui::NavigateBoard *ui;
};

#endif // NAVIGATEBOARD_H
