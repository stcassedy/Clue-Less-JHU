/********************************************************************************
** Form generated from reading UI file 'ServerWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStartStop;

    void setupUi(QMainWindow *ServerWindow)
    {
        if (ServerWindow->objectName().isEmpty())
            ServerWindow->setObjectName(QStringLiteral("ServerWindow"));
        ServerWindow->resize(200, 50);
        ServerWindow->setMinimumSize(QSize(200, 50));
        ServerWindow->setMaximumSize(QSize(200, 50));
        ServerWindow->setStyleSheet(QLatin1String("QMainWindow {\n"
"color: black;\n"
"background-color: white;\n"
"border: 1px solid white;\n"
"}"));
        centralWidget = new QWidget(ServerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnStartStop = new QPushButton(centralWidget);
        btnStartStop->setObjectName(QStringLiteral("btnStartStop"));
        btnStartStop->setMinimumSize(QSize(50, 30));
        btnStartStop->setStyleSheet(QLatin1String("QPushButton:checked{\n"
"color: rgb(150, 0, 0);\n"
"background-color: rgb(255, 175, 175);\n"
"border: 1px solid rgb(150, 0, 0);\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton{\n"
"color: rgb(0, 150, 0);\n"
"background-color: rgb(200, 255, 200);\n"
"border: 1px solid rgb(0, 150, 0);\n"
"border-radius: 10px;\n"
"}"));
        btnStartStop->setCheckable(true);
        btnStartStop->setChecked(false);

        horizontalLayout->addWidget(btnStartStop);

        ServerWindow->setCentralWidget(centralWidget);

        retranslateUi(ServerWindow);

        QMetaObject::connectSlotsByName(ServerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ServerWindow)
    {
        ServerWindow->setWindowTitle(QApplication::translate("ServerWindow", "ServerWindow", nullptr));
        btnStartStop->setText(QApplication::translate("ServerWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWindow: public Ui_ServerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
