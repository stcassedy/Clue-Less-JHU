/********************************************************************************
** Form generated from reading UI file 'NavigatBoard.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATBOARD_H
#define UI_NAVIGATBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_NavigatBoard
{
public:

    void setupUi(QDialog *NavigatBoard)
    {
        if (NavigatBoard->objectName().isEmpty())
            NavigatBoard->setObjectName(QStringLiteral("NavigatBoard"));
        NavigatBoard->resize(400, 300);

        retranslateUi(NavigatBoard);

        QMetaObject::connectSlotsByName(NavigatBoard);
    } // setupUi

    void retranslateUi(QDialog *NavigatBoard)
    {
        NavigatBoard->setWindowTitle(QApplication::translate("NavigatBoard", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NavigatBoard: public Ui_NavigatBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATBOARD_H
