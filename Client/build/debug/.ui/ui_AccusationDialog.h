/********************************************************************************
** Form generated from reading UI file 'AccusationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCUSATIONDIALOG_H
#define UI_ACCUSATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_AccusationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gbAccusation;
    QGridLayout *gridLayout;
    QLabel *lbWeapon;
    QComboBox *cbWeapon;
    QLabel *lbSuspect;
    QComboBox *cbSuspect;
    QLabel *lbWithThe;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnAccuse;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AccusationDialog)
    {
        if (AccusationDialog->objectName().isEmpty())
            AccusationDialog->setObjectName(QStringLiteral("AccusationDialog"));
        AccusationDialog->resize(400, 130);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AccusationDialog->sizePolicy().hasHeightForWidth());
        AccusationDialog->setSizePolicy(sizePolicy);
        AccusationDialog->setMinimumSize(QSize(400, 130));
        AccusationDialog->setMaximumSize(QSize(400, 130));
        AccusationDialog->setStyleSheet(QLatin1String("QWidget {\n"
"background-color: rgb(112,128,144);\n"
"}\n"
"\n"
"QLabel {\n"
"color: black;\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QComboBox {\n"
"color: black;\n"
"background-color:  rgb(150,160,180) ;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"padding: 1px 0px 1px 3px;\n"
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
        verticalLayout = new QVBoxLayout(AccusationDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gbAccusation = new QGroupBox(AccusationDialog);
        gbAccusation->setObjectName(QStringLiteral("gbAccusation"));
        gbAccusation->setStyleSheet(QLatin1String("QGroupBox {\n"
"font-weight: bold;\n"
"}"));
        gridLayout = new QGridLayout(gbAccusation);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lbWeapon = new QLabel(gbAccusation);
        lbWeapon->setObjectName(QStringLiteral("lbWeapon"));
        lbWeapon->setMaximumSize(QSize(16777215, 20));
        lbWeapon->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbWeapon, 0, 2, 1, 1);

        cbWeapon = new QComboBox(gbAccusation);
        cbWeapon->addItem(QString());
        cbWeapon->addItem(QString());
        cbWeapon->addItem(QString());
        cbWeapon->addItem(QString());
        cbWeapon->addItem(QString());
        cbWeapon->addItem(QString());
        cbWeapon->setObjectName(QStringLiteral("cbWeapon"));

        gridLayout->addWidget(cbWeapon, 1, 2, 1, 1);

        lbSuspect = new QLabel(gbAccusation);
        lbSuspect->setObjectName(QStringLiteral("lbSuspect"));
        lbSuspect->setMaximumSize(QSize(16777215, 20));
        lbSuspect->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbSuspect, 0, 0, 1, 1);

        cbSuspect = new QComboBox(gbAccusation);
        cbSuspect->addItem(QString());
        cbSuspect->addItem(QString());
        cbSuspect->addItem(QString());
        cbSuspect->addItem(QString());
        cbSuspect->addItem(QString());
        cbSuspect->addItem(QString());
        cbSuspect->setObjectName(QStringLiteral("cbSuspect"));

        gridLayout->addWidget(cbSuspect, 1, 0, 1, 1);

        lbWithThe = new QLabel(gbAccusation);
        lbWithThe->setObjectName(QStringLiteral("lbWithThe"));
        sizePolicy.setHeightForWidth(lbWithThe->sizePolicy().hasHeightForWidth());
        lbWithThe->setSizePolicy(sizePolicy);
        lbWithThe->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbWithThe, 1, 1, 1, 1);


        verticalLayout->addWidget(gbAccusation);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnAccuse = new QPushButton(AccusationDialog);
        btnAccuse->setObjectName(QStringLiteral("btnAccuse"));
        btnAccuse->setMinimumSize(QSize(120, 25));

        horizontalLayout->addWidget(btnAccuse);

        btnCancel = new QPushButton(AccusationDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setMinimumSize(QSize(120, 25));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(AccusationDialog);

        QMetaObject::connectSlotsByName(AccusationDialog);
    } // setupUi

    void retranslateUi(QDialog *AccusationDialog)
    {
        AccusationDialog->setWindowTitle(QApplication::translate("AccusationDialog", "Dialog", nullptr));
        gbAccusation->setTitle(QApplication::translate("AccusationDialog", "Accusation", nullptr));
        lbWeapon->setText(QApplication::translate("AccusationDialog", "Weapon", nullptr));
        cbWeapon->setItemText(0, QApplication::translate("AccusationDialog", "Candlestick", nullptr));
        cbWeapon->setItemText(1, QApplication::translate("AccusationDialog", "Knife", nullptr));
        cbWeapon->setItemText(2, QApplication::translate("AccusationDialog", "Lead Pipe", nullptr));
        cbWeapon->setItemText(3, QApplication::translate("AccusationDialog", "Revolver", nullptr));
        cbWeapon->setItemText(4, QApplication::translate("AccusationDialog", "Rope", nullptr));
        cbWeapon->setItemText(5, QApplication::translate("AccusationDialog", "Wrench", nullptr));

        lbSuspect->setText(QApplication::translate("AccusationDialog", "Suspect", nullptr));
        cbSuspect->setItemText(0, QApplication::translate("AccusationDialog", "Miss Scarlet", nullptr));
        cbSuspect->setItemText(1, QApplication::translate("AccusationDialog", "Col. Mustard", nullptr));
        cbSuspect->setItemText(2, QApplication::translate("AccusationDialog", "Mrs. White", nullptr));
        cbSuspect->setItemText(3, QApplication::translate("AccusationDialog", "Mr. Green", nullptr));
        cbSuspect->setItemText(4, QApplication::translate("AccusationDialog", "Mrs. Peacock", nullptr));
        cbSuspect->setItemText(5, QApplication::translate("AccusationDialog", "Prof. Plum", nullptr));

        lbWithThe->setText(QApplication::translate("AccusationDialog", "with the", nullptr));
        btnAccuse->setText(QApplication::translate("AccusationDialog", "Accuse", nullptr));
        btnCancel->setText(QApplication::translate("AccusationDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccusationDialog: public Ui_AccusationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUSATIONDIALOG_H
