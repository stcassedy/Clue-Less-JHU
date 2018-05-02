/********************************************************************************
** Form generated from reading UI file 'NavigateBoardDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATEBOARDDIALOG_H
#define UI_NAVIGATEBOARDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NavigateBoardDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnBilliardRoom;
    QPushButton *btnDiningRoom;
    QPushButton *btnConservatory;
    QPushButton *btnKitchen;
    QPushButton *btnBallroom;
    QPushButton *btnHallway8;
    QPushButton *btnHallway9;
    QPushButton *btnHallway10;
    QPushButton *btnHallway11;
    QPushButton *btnLibrary;
    QPushButton *btnHallway12;
    QLabel *label_2;
    QLabel *label;
    QPushButton *btnStudy;
    QPushButton *btnHallway1;
    QPushButton *btnHall;
    QPushButton *btnHallway2;
    QPushButton *btnHallway3;
    QPushButton *btnLounge;
    QPushButton *btnHallway6;
    QPushButton *btnHallway4;
    QPushButton *btnHallway5;
    QPushButton *btnHallway7;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *NavigateBoardDialog)
    {
        if (NavigateBoardDialog->objectName().isEmpty())
            NavigateBoardDialog->setObjectName(QStringLiteral("NavigateBoardDialog"));
        NavigateBoardDialog->resize(429, 475);
        NavigateBoardDialog->setStyleSheet(QLatin1String("QWidget {\n"
"background-color: rgb(112,128,144);\n"
"}\n"
"\n"
"QPushButton {\n"
"color: rgb(0,0,0);\n"
"font-weight: bold;\n"
"background-color: rgb(150,160,180);\n"
"border: 1px solid black;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"color: rgb(0,0,0);\n"
"font-weight: bold;\n"
"background-color: rgb(250,250,250);\n"
"border: 1px solid black;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"color: darkgrey;\n"
"font-weight: bold;\n"
"background-color:lightgrey;\n"
"border: 1px solid darkgrey;\n"
"border-radius: 5px;\n"
"}"));
        NavigateBoardDialog->setModal(true);
        verticalLayout = new QVBoxLayout(NavigateBoardDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(NavigateBoardDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"font-weight: bold;\n"
"}"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnBilliardRoom = new QPushButton(groupBox);
        btnBilliardRoom->setObjectName(QStringLiteral("btnBilliardRoom"));
        btnBilliardRoom->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnBilliardRoom, 5, 0, 1, 1);

        btnDiningRoom = new QPushButton(groupBox);
        btnDiningRoom->setObjectName(QStringLiteral("btnDiningRoom"));
        btnDiningRoom->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnDiningRoom, 6, 0, 1, 1);

        btnConservatory = new QPushButton(groupBox);
        btnConservatory->setObjectName(QStringLiteral("btnConservatory"));
        btnConservatory->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnConservatory, 7, 0, 1, 1);

        btnKitchen = new QPushButton(groupBox);
        btnKitchen->setObjectName(QStringLiteral("btnKitchen"));
        btnKitchen->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnKitchen, 9, 0, 1, 1);

        btnBallroom = new QPushButton(groupBox);
        btnBallroom->setObjectName(QStringLiteral("btnBallroom"));
        btnBallroom->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnBallroom, 8, 0, 1, 1);

        btnHallway8 = new QPushButton(groupBox);
        btnHallway8->setObjectName(QStringLiteral("btnHallway8"));
        btnHallway8->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway8, 8, 1, 1, 1);

        btnHallway9 = new QPushButton(groupBox);
        btnHallway9->setObjectName(QStringLiteral("btnHallway9"));
        btnHallway9->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway9, 9, 1, 1, 1);

        btnHallway10 = new QPushButton(groupBox);
        btnHallway10->setObjectName(QStringLiteral("btnHallway10"));
        btnHallway10->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway10, 10, 1, 1, 1);

        btnHallway11 = new QPushButton(groupBox);
        btnHallway11->setObjectName(QStringLiteral("btnHallway11"));
        btnHallway11->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway11, 11, 1, 1, 1);

        btnLibrary = new QPushButton(groupBox);
        btnLibrary->setObjectName(QStringLiteral("btnLibrary"));
        btnLibrary->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnLibrary, 4, 0, 1, 1);

        btnHallway12 = new QPushButton(groupBox);
        btnHallway12->setObjectName(QStringLiteral("btnHallway12"));
        btnHallway12->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway12, 12, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"color: black;\n"
"font-weight: bold;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"color: black;\n"
"font-weight: bold;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        btnStudy = new QPushButton(groupBox);
        btnStudy->setObjectName(QStringLiteral("btnStudy"));
        btnStudy->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnStudy, 1, 0, 1, 1);

        btnHallway1 = new QPushButton(groupBox);
        btnHallway1->setObjectName(QStringLiteral("btnHallway1"));
        btnHallway1->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway1, 1, 1, 1, 1);

        btnHall = new QPushButton(groupBox);
        btnHall->setObjectName(QStringLiteral("btnHall"));
        btnHall->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHall, 2, 0, 1, 1);

        btnHallway2 = new QPushButton(groupBox);
        btnHallway2->setObjectName(QStringLiteral("btnHallway2"));
        btnHallway2->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway2, 2, 1, 1, 1);

        btnHallway3 = new QPushButton(groupBox);
        btnHallway3->setObjectName(QStringLiteral("btnHallway3"));
        btnHallway3->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway3, 3, 1, 1, 1);

        btnLounge = new QPushButton(groupBox);
        btnLounge->setObjectName(QStringLiteral("btnLounge"));
        btnLounge->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnLounge, 3, 0, 1, 1);

        btnHallway6 = new QPushButton(groupBox);
        btnHallway6->setObjectName(QStringLiteral("btnHallway6"));
        btnHallway6->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway6, 6, 1, 1, 1);

        btnHallway4 = new QPushButton(groupBox);
        btnHallway4->setObjectName(QStringLiteral("btnHallway4"));
        btnHallway4->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway4, 4, 1, 1, 1);

        btnHallway5 = new QPushButton(groupBox);
        btnHallway5->setObjectName(QStringLiteral("btnHallway5"));
        btnHallway5->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway5, 5, 1, 1, 1);

        btnHallway7 = new QPushButton(groupBox);
        btnHallway7->setObjectName(QStringLiteral("btnHallway7"));
        btnHallway7->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(btnHallway7, 7, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 13, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 13, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnCancel = new QPushButton(NavigateBoardDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setMinimumSize(QSize(100, 25));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(NavigateBoardDialog);

        QMetaObject::connectSlotsByName(NavigateBoardDialog);
    } // setupUi

    void retranslateUi(QDialog *NavigateBoardDialog)
    {
        NavigateBoardDialog->setWindowTitle(QApplication::translate("NavigateBoardDialog", "Navigate", nullptr));
        groupBox->setTitle(QApplication::translate("NavigateBoardDialog", "Select Board Location", nullptr));
        btnBilliardRoom->setText(QApplication::translate("NavigateBoardDialog", "Billiard Room", nullptr));
        btnDiningRoom->setText(QApplication::translate("NavigateBoardDialog", "Dining Room", nullptr));
        btnConservatory->setText(QApplication::translate("NavigateBoardDialog", "Conservatory", nullptr));
        btnKitchen->setText(QApplication::translate("NavigateBoardDialog", "Kitchen", nullptr));
        btnBallroom->setText(QApplication::translate("NavigateBoardDialog", "Ballroom", nullptr));
        btnHallway8->setText(QApplication::translate("NavigateBoardDialog", "Hallway #8", nullptr));
        btnHallway9->setText(QApplication::translate("NavigateBoardDialog", "Hallway #9", nullptr));
        btnHallway10->setText(QApplication::translate("NavigateBoardDialog", "Hallway #10", nullptr));
        btnHallway11->setText(QApplication::translate("NavigateBoardDialog", "Hallway #11", nullptr));
        btnLibrary->setText(QApplication::translate("NavigateBoardDialog", "Library", nullptr));
        btnHallway12->setText(QApplication::translate("NavigateBoardDialog", "Hallway #12", nullptr));
        label_2->setText(QApplication::translate("NavigateBoardDialog", "Hallways", nullptr));
        label->setText(QApplication::translate("NavigateBoardDialog", "Rooms", nullptr));
        btnStudy->setText(QApplication::translate("NavigateBoardDialog", "Study", nullptr));
        btnHallway1->setText(QApplication::translate("NavigateBoardDialog", "Hallway #1", nullptr));
        btnHall->setText(QApplication::translate("NavigateBoardDialog", "Hall", nullptr));
        btnHallway2->setText(QApplication::translate("NavigateBoardDialog", "Hallway #2", nullptr));
        btnHallway3->setText(QApplication::translate("NavigateBoardDialog", "Hallway #3", nullptr));
        btnLounge->setText(QApplication::translate("NavigateBoardDialog", "Lounge", nullptr));
        btnHallway6->setText(QApplication::translate("NavigateBoardDialog", "Hallway #6", nullptr));
        btnHallway4->setText(QApplication::translate("NavigateBoardDialog", "Hallway #4", nullptr));
        btnHallway5->setText(QApplication::translate("NavigateBoardDialog", "Hallway #5", nullptr));
        btnHallway7->setText(QApplication::translate("NavigateBoardDialog", "Hallway #7", nullptr));
        btnCancel->setText(QApplication::translate("NavigateBoardDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NavigateBoardDialog: public Ui_NavigateBoardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATEBOARDDIALOG_H
