/********************************************************************************
** Form generated from reading UI file 'SuggestionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUGGESTIONDIALOG_H
#define UI_SUGGESTIONDIALOG_H

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

class Ui_SuggestionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gbSuggestion;
    QGridLayout *gridLayout;
    QLabel *lbWeapon;
    QComboBox *cbWeapon;
    QLabel *lbSuspect;
    QComboBox *cbSuspect;
    QLabel *lbWithThe;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSuggest;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SuggestionDialog)
    {
        if (SuggestionDialog->objectName().isEmpty())
            SuggestionDialog->setObjectName(QStringLiteral("SuggestionDialog"));
        SuggestionDialog->resize(400, 130);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SuggestionDialog->sizePolicy().hasHeightForWidth());
        SuggestionDialog->setSizePolicy(sizePolicy);
        SuggestionDialog->setMinimumSize(QSize(400, 130));
        SuggestionDialog->setMaximumSize(QSize(400, 130));
        SuggestionDialog->setStyleSheet(QLatin1String("QWidget {\n"
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
        verticalLayout = new QVBoxLayout(SuggestionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gbSuggestion = new QGroupBox(SuggestionDialog);
        gbSuggestion->setObjectName(QStringLiteral("gbSuggestion"));
        gbSuggestion->setStyleSheet(QLatin1String("QGroupBox {\n"
"font-weight: bold;\n"
"}"));
        gridLayout = new QGridLayout(gbSuggestion);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lbWeapon = new QLabel(gbSuggestion);
        lbWeapon->setObjectName(QStringLiteral("lbWeapon"));
        lbWeapon->setMaximumSize(QSize(16777215, 20));
        lbWeapon->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbWeapon, 0, 2, 1, 1);

        cbWeapon = new QComboBox(gbSuggestion);
        cbWeapon->addItem(QString());
        cbWeapon->addItem(QString());
        cbWeapon->addItem(QString());
        cbWeapon->addItem(QString());
        cbWeapon->addItem(QString());
        cbWeapon->addItem(QString());
        cbWeapon->setObjectName(QStringLiteral("cbWeapon"));

        gridLayout->addWidget(cbWeapon, 1, 2, 1, 1);

        lbSuspect = new QLabel(gbSuggestion);
        lbSuspect->setObjectName(QStringLiteral("lbSuspect"));
        lbSuspect->setMaximumSize(QSize(16777215, 20));
        lbSuspect->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbSuspect, 0, 0, 1, 1);

        cbSuspect = new QComboBox(gbSuggestion);
        cbSuspect->addItem(QString());
        cbSuspect->addItem(QString());
        cbSuspect->addItem(QString());
        cbSuspect->addItem(QString());
        cbSuspect->addItem(QString());
        cbSuspect->addItem(QString());
        cbSuspect->setObjectName(QStringLiteral("cbSuspect"));

        gridLayout->addWidget(cbSuspect, 1, 0, 1, 1);

        lbWithThe = new QLabel(gbSuggestion);
        lbWithThe->setObjectName(QStringLiteral("lbWithThe"));
        sizePolicy.setHeightForWidth(lbWithThe->sizePolicy().hasHeightForWidth());
        lbWithThe->setSizePolicy(sizePolicy);
        lbWithThe->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbWithThe, 1, 1, 1, 1);


        verticalLayout->addWidget(gbSuggestion);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnSuggest = new QPushButton(SuggestionDialog);
        btnSuggest->setObjectName(QStringLiteral("btnSuggest"));
        btnSuggest->setMinimumSize(QSize(120, 25));

        horizontalLayout->addWidget(btnSuggest);

        btnCancel = new QPushButton(SuggestionDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setMinimumSize(QSize(120, 25));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(SuggestionDialog);

        QMetaObject::connectSlotsByName(SuggestionDialog);
    } // setupUi

    void retranslateUi(QDialog *SuggestionDialog)
    {
        SuggestionDialog->setWindowTitle(QApplication::translate("SuggestionDialog", "Dialog", nullptr));
        gbSuggestion->setTitle(QApplication::translate("SuggestionDialog", "Suggestion", nullptr));
        lbWeapon->setText(QApplication::translate("SuggestionDialog", "Weapon", nullptr));
        cbWeapon->setItemText(0, QApplication::translate("SuggestionDialog", "Candlestick", nullptr));
        cbWeapon->setItemText(1, QApplication::translate("SuggestionDialog", "Knife", nullptr));
        cbWeapon->setItemText(2, QApplication::translate("SuggestionDialog", "Lead Pipe", nullptr));
        cbWeapon->setItemText(3, QApplication::translate("SuggestionDialog", "Revolver", nullptr));
        cbWeapon->setItemText(4, QApplication::translate("SuggestionDialog", "Rope", nullptr));
        cbWeapon->setItemText(5, QApplication::translate("SuggestionDialog", "Wrench", nullptr));

        lbSuspect->setText(QApplication::translate("SuggestionDialog", "Suspect", nullptr));
        cbSuspect->setItemText(0, QApplication::translate("SuggestionDialog", "Miss Scarlet", nullptr));
        cbSuspect->setItemText(1, QApplication::translate("SuggestionDialog", "Col. Mustard", nullptr));
        cbSuspect->setItemText(2, QApplication::translate("SuggestionDialog", "Mrs. White", nullptr));
        cbSuspect->setItemText(3, QApplication::translate("SuggestionDialog", "Mr. Green", nullptr));
        cbSuspect->setItemText(4, QApplication::translate("SuggestionDialog", "Mrs. Peacock", nullptr));
        cbSuspect->setItemText(5, QApplication::translate("SuggestionDialog", "Prof. Plum", nullptr));

        lbWithThe->setText(QApplication::translate("SuggestionDialog", "with the", nullptr));
        btnSuggest->setText(QApplication::translate("SuggestionDialog", "Suggest", nullptr));
        btnCancel->setText(QApplication::translate("SuggestionDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuggestionDialog: public Ui_SuggestionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUGGESTIONDIALOG_H
