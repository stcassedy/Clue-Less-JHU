/********************************************************************************
** Form generated from reading UI file 'RefutationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFUTATIONDIALOG_H
#define UI_REFUTATIONDIALOG_H

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

class Ui_RefutationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gbRefutation;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *cbRefutation;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnRefute;
    QPushButton *btnPass;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *RefutationDialog)
    {
        if (RefutationDialog->objectName().isEmpty())
            RefutationDialog->setObjectName(QStringLiteral("RefutationDialog"));
        RefutationDialog->resize(410, 130);
        RefutationDialog->setMinimumSize(QSize(410, 130));
        RefutationDialog->setMaximumSize(QSize(410, 130));
        RefutationDialog->setStyleSheet(QLatin1String("QWidget {\n"
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
        verticalLayout = new QVBoxLayout(RefutationDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gbRefutation = new QGroupBox(RefutationDialog);
        gbRefutation->setObjectName(QStringLiteral("gbRefutation"));
        gbRefutation->setStyleSheet(QLatin1String("QGroupBox {\n"
"font-weight: bold;\n"
"}"));
        gridLayout = new QGridLayout(gbRefutation);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        cbRefutation = new QComboBox(gbRefutation);
        cbRefutation->setObjectName(QStringLiteral("cbRefutation"));
        cbRefutation->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(cbRefutation, 1, 1, 1, 1);

        label = new QLabel(gbRefutation);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);


        verticalLayout->addWidget(gbRefutation);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnRefute = new QPushButton(RefutationDialog);
        btnRefute->setObjectName(QStringLiteral("btnRefute"));
        btnRefute->setMinimumSize(QSize(120, 25));

        horizontalLayout->addWidget(btnRefute);

        btnPass = new QPushButton(RefutationDialog);
        btnPass->setObjectName(QStringLiteral("btnPass"));
        btnPass->setMinimumSize(QSize(120, 25));

        horizontalLayout->addWidget(btnPass);

        btnCancel = new QPushButton(RefutationDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setMinimumSize(QSize(120, 25));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(RefutationDialog);

        QMetaObject::connectSlotsByName(RefutationDialog);
    } // setupUi

    void retranslateUi(QDialog *RefutationDialog)
    {
        RefutationDialog->setWindowTitle(QApplication::translate("RefutationDialog", "Dialog", nullptr));
        gbRefutation->setTitle(QApplication::translate("RefutationDialog", "Refutation", nullptr));
        label->setText(QApplication::translate("RefutationDialog", "Refutation Card", nullptr));
        btnRefute->setText(QApplication::translate("RefutationDialog", "Refute", nullptr));
        btnPass->setText(QApplication::translate("RefutationDialog", "Pass", nullptr));
        btnCancel->setText(QApplication::translate("RefutationDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RefutationDialog: public Ui_RefutationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFUTATIONDIALOG_H
