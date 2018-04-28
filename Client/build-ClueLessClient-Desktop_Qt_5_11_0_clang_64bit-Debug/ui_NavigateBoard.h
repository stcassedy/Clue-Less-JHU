/********************************************************************************
** Form generated from reading UI file 'NavigateBoard.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATEBOARD_H
#define UI_NAVIGATEBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NavigateBoard
{
public:
    QPushButton *MoveLeft;
    QPushButton *MoveRight;
    QPushButton *MoveDown;
    QPushButton *SecretPassage;
    QPushButton *Cancel;
    QPushButton *MoveUp;

    void setupUi(QDialog *NavigateBoard)
    {
        if (NavigateBoard->objectName().isEmpty())
            NavigateBoard->setObjectName(QStringLiteral("NavigateBoard"));
        NavigateBoard->resize(400, 300);
        NavigateBoard->setModal(true);
        MoveLeft = new QPushButton(NavigateBoard);
        MoveLeft->setObjectName(QStringLiteral("MoveLeft"));
        MoveLeft->setGeometry(QRect(10, 100, 113, 32));
        MoveLeft->setAutoDefault(false);
        MoveRight = new QPushButton(NavigateBoard);
        MoveRight->setObjectName(QStringLiteral("MoveRight"));
        MoveRight->setGeometry(QRect(250, 100, 113, 32));
        MoveRight->setAutoDefault(false);
        MoveDown = new QPushButton(NavigateBoard);
        MoveDown->setObjectName(QStringLiteral("MoveDown"));
        MoveDown->setGeometry(QRect(130, 150, 113, 32));
        MoveDown->setAutoDefault(false);
        SecretPassage = new QPushButton(NavigateBoard);
        SecretPassage->setObjectName(QStringLiteral("SecretPassage"));
        SecretPassage->setGeometry(QRect(120, 100, 131, 32));
        SecretPassage->setAutoDefault(false);
        Cancel = new QPushButton(NavigateBoard);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(130, 210, 113, 32));
        Cancel->setAutoDefault(false);
        MoveUp = new QPushButton(NavigateBoard);
        MoveUp->setObjectName(QStringLiteral("MoveUp"));
        MoveUp->setGeometry(QRect(130, 40, 113, 32));
        MoveUp->setAutoDefault(false);

        retranslateUi(NavigateBoard);
        QObject::connect(Cancel, SIGNAL(clicked()), NavigateBoard, SLOT(close()));

        QMetaObject::connectSlotsByName(NavigateBoard);
    } // setupUi

    void retranslateUi(QDialog *NavigateBoard)
    {
        NavigateBoard->setWindowTitle(QApplication::translate("NavigateBoard", "Navigate", nullptr));
        MoveLeft->setText(QApplication::translate("NavigateBoard", "Move Left", nullptr));
        MoveRight->setText(QApplication::translate("NavigateBoard", "Move Right", nullptr));
        MoveDown->setText(QApplication::translate("NavigateBoard", "Move Down", nullptr));
        SecretPassage->setText(QApplication::translate("NavigateBoard", "Secret Passage", nullptr));
        Cancel->setText(QApplication::translate("NavigateBoard", "Cancel", nullptr));
        MoveUp->setText(QApplication::translate("NavigateBoard", "Move Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NavigateBoard: public Ui_NavigateBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATEBOARD_H
