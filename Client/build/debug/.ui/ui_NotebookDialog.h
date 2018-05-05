/********************************************************************************
** Form generated from reading UI file 'NotebookDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEBOOKDIALOG_H
#define UI_NOTEBOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NotebookDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gbNotebook;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *gbTrackItems;
    QGridLayout *gridLayout;
    QCheckBox *chDiningRoom;
    QCheckBox *chBallroom;
    QCheckBox *chLibrary;
    QCheckBox *chConservatory;
    QCheckBox *chBilliardRoom;
    QCheckBox *chCandlestick;
    QCheckBox *chStudy;
    QCheckBox *chMrsWihte;
    QCheckBox *chMrGreen;
    QCheckBox *chMrsPeacock;
    QCheckBox *chMissScarlet;
    QLabel *lbRoom;
    QLabel *lbWeapon;
    QCheckBox *chColMustard;
    QLabel *lbSuspect;
    QCheckBox *chProfPlum;
    QCheckBox *chHall;
    QCheckBox *chLounge;
    QCheckBox *chKitchen;
    QCheckBox *chKnife;
    QCheckBox *chLeadPipe;
    QCheckBox *chRevolver;
    QCheckBox *chRope;
    QCheckBox *chWrench;
    QGroupBox *gbNotes;
    QVBoxLayout *verticalLayout;
    QTextEdit *teNotes;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *NotebookDialog)
    {
        if (NotebookDialog->objectName().isEmpty())
            NotebookDialog->setObjectName(QStringLiteral("NotebookDialog"));
        NotebookDialog->resize(589, 457);
        NotebookDialog->setStyleSheet(QLatin1String("QWidget {\n"
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
"}\n"
"\n"
"QGroupBox {\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox {\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox:checked {\n"
"color: darkgrey; \n"
"}\n"
"\n"
"QCheckBox:unchecked {\n"
"color: black; \n"
"}\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(NotebookDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gbNotebook = new QGroupBox(NotebookDialog);
        gbNotebook->setObjectName(QStringLiteral("gbNotebook"));
        verticalLayout_3 = new QVBoxLayout(gbNotebook);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gbTrackItems = new QGroupBox(gbNotebook);
        gbTrackItems->setObjectName(QStringLiteral("gbTrackItems"));
        gridLayout = new QGridLayout(gbTrackItems);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        chDiningRoom = new QCheckBox(gbTrackItems);
        chDiningRoom->setObjectName(QStringLiteral("chDiningRoom"));

        gridLayout->addWidget(chDiningRoom, 6, 1, 1, 1);

        chBallroom = new QCheckBox(gbTrackItems);
        chBallroom->setObjectName(QStringLiteral("chBallroom"));

        gridLayout->addWidget(chBallroom, 8, 1, 1, 1);

        chLibrary = new QCheckBox(gbTrackItems);
        chLibrary->setObjectName(QStringLiteral("chLibrary"));

        gridLayout->addWidget(chLibrary, 4, 1, 1, 1);

        chConservatory = new QCheckBox(gbTrackItems);
        chConservatory->setObjectName(QStringLiteral("chConservatory"));

        gridLayout->addWidget(chConservatory, 7, 1, 1, 1);

        chBilliardRoom = new QCheckBox(gbTrackItems);
        chBilliardRoom->setObjectName(QStringLiteral("chBilliardRoom"));

        gridLayout->addWidget(chBilliardRoom, 5, 1, 1, 1);

        chCandlestick = new QCheckBox(gbTrackItems);
        chCandlestick->setObjectName(QStringLiteral("chCandlestick"));
        chCandlestick->setChecked(false);

        gridLayout->addWidget(chCandlestick, 1, 0, 1, 1);

        chStudy = new QCheckBox(gbTrackItems);
        chStudy->setObjectName(QStringLiteral("chStudy"));

        gridLayout->addWidget(chStudy, 1, 1, 1, 1);

        chMrsWihte = new QCheckBox(gbTrackItems);
        chMrsWihte->setObjectName(QStringLiteral("chMrsWihte"));

        gridLayout->addWidget(chMrsWihte, 3, 2, 1, 1);

        chMrGreen = new QCheckBox(gbTrackItems);
        chMrGreen->setObjectName(QStringLiteral("chMrGreen"));

        gridLayout->addWidget(chMrGreen, 4, 2, 1, 1);

        chMrsPeacock = new QCheckBox(gbTrackItems);
        chMrsPeacock->setObjectName(QStringLiteral("chMrsPeacock"));

        gridLayout->addWidget(chMrsPeacock, 5, 2, 1, 1);

        chMissScarlet = new QCheckBox(gbTrackItems);
        chMissScarlet->setObjectName(QStringLiteral("chMissScarlet"));

        gridLayout->addWidget(chMissScarlet, 1, 2, 1, 1);

        lbRoom = new QLabel(gbTrackItems);
        lbRoom->setObjectName(QStringLiteral("lbRoom"));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        lbRoom->setFont(font);
        lbRoom->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lbRoom, 0, 1, 1, 1);

        lbWeapon = new QLabel(gbTrackItems);
        lbWeapon->setObjectName(QStringLiteral("lbWeapon"));
        lbWeapon->setFont(font);
        lbWeapon->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lbWeapon, 0, 0, 1, 1);

        chColMustard = new QCheckBox(gbTrackItems);
        chColMustard->setObjectName(QStringLiteral("chColMustard"));

        gridLayout->addWidget(chColMustard, 2, 2, 1, 1);

        lbSuspect = new QLabel(gbTrackItems);
        lbSuspect->setObjectName(QStringLiteral("lbSuspect"));
        lbSuspect->setFont(font);
        lbSuspect->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lbSuspect, 0, 2, 1, 1);

        chProfPlum = new QCheckBox(gbTrackItems);
        chProfPlum->setObjectName(QStringLiteral("chProfPlum"));

        gridLayout->addWidget(chProfPlum, 6, 2, 1, 1);

        chHall = new QCheckBox(gbTrackItems);
        chHall->setObjectName(QStringLiteral("chHall"));

        gridLayout->addWidget(chHall, 2, 1, 1, 1);

        chLounge = new QCheckBox(gbTrackItems);
        chLounge->setObjectName(QStringLiteral("chLounge"));

        gridLayout->addWidget(chLounge, 3, 1, 1, 1);

        chKitchen = new QCheckBox(gbTrackItems);
        chKitchen->setObjectName(QStringLiteral("chKitchen"));

        gridLayout->addWidget(chKitchen, 9, 1, 1, 1);

        chKnife = new QCheckBox(gbTrackItems);
        chKnife->setObjectName(QStringLiteral("chKnife"));

        gridLayout->addWidget(chKnife, 2, 0, 1, 1);

        chLeadPipe = new QCheckBox(gbTrackItems);
        chLeadPipe->setObjectName(QStringLiteral("chLeadPipe"));

        gridLayout->addWidget(chLeadPipe, 3, 0, 1, 1);

        chRevolver = new QCheckBox(gbTrackItems);
        chRevolver->setObjectName(QStringLiteral("chRevolver"));

        gridLayout->addWidget(chRevolver, 4, 0, 1, 1);

        chRope = new QCheckBox(gbTrackItems);
        chRope->setObjectName(QStringLiteral("chRope"));

        gridLayout->addWidget(chRope, 5, 0, 1, 1);

        chWrench = new QCheckBox(gbTrackItems);
        chWrench->setObjectName(QStringLiteral("chWrench"));

        gridLayout->addWidget(chWrench, 6, 0, 1, 1);


        verticalLayout_3->addWidget(gbTrackItems);

        gbNotes = new QGroupBox(gbNotebook);
        gbNotes->setObjectName(QStringLiteral("gbNotes"));
        verticalLayout = new QVBoxLayout(gbNotes);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        teNotes = new QTextEdit(gbNotes);
        teNotes->setObjectName(QStringLiteral("teNotes"));
        teNotes->setStyleSheet(QLatin1String("QTextEdit {\n"
"color: black;\n"
"background-color: white;\n"
"border: 1px solid black;\n"
"}"));
        teNotes->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(teNotes);


        verticalLayout_3->addWidget(gbNotes);


        verticalLayout_2->addWidget(gbNotebook);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnClose = new QPushButton(NotebookDialog);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setMinimumSize(QSize(120, 25));

        horizontalLayout->addWidget(btnClose);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(NotebookDialog);

        QMetaObject::connectSlotsByName(NotebookDialog);
    } // setupUi

    void retranslateUi(QDialog *NotebookDialog)
    {
        NotebookDialog->setWindowTitle(QApplication::translate("NotebookDialog", "Dialog", nullptr));
        gbNotebook->setTitle(QApplication::translate("NotebookDialog", "Notebook", nullptr));
        gbTrackItems->setTitle(QApplication::translate("NotebookDialog", "Track Items", nullptr));
        chDiningRoom->setText(QApplication::translate("NotebookDialog", "Dining Room", nullptr));
        chBallroom->setText(QApplication::translate("NotebookDialog", "Ballroom", nullptr));
        chLibrary->setText(QApplication::translate("NotebookDialog", "Library", nullptr));
        chConservatory->setText(QApplication::translate("NotebookDialog", "Conservatory", nullptr));
        chBilliardRoom->setText(QApplication::translate("NotebookDialog", "Billiard Room", nullptr));
        chCandlestick->setText(QApplication::translate("NotebookDialog", "Candlestick", nullptr));
        chStudy->setText(QApplication::translate("NotebookDialog", "Study", nullptr));
        chMrsWihte->setText(QApplication::translate("NotebookDialog", "Mrs. White", nullptr));
        chMrGreen->setText(QApplication::translate("NotebookDialog", "Mr. Green", nullptr));
        chMrsPeacock->setText(QApplication::translate("NotebookDialog", "Mrs. Peacock", nullptr));
        chMissScarlet->setText(QApplication::translate("NotebookDialog", "Miss Scarlet", nullptr));
        lbRoom->setText(QApplication::translate("NotebookDialog", "Room", nullptr));
        lbWeapon->setText(QApplication::translate("NotebookDialog", "Weapon", nullptr));
        chColMustard->setText(QApplication::translate("NotebookDialog", "Col. Mustard", nullptr));
        lbSuspect->setText(QApplication::translate("NotebookDialog", "Suspect", nullptr));
        chProfPlum->setText(QApplication::translate("NotebookDialog", "Prof. Plum", nullptr));
        chHall->setText(QApplication::translate("NotebookDialog", "Hall", nullptr));
        chLounge->setText(QApplication::translate("NotebookDialog", "Lounge", nullptr));
        chKitchen->setText(QApplication::translate("NotebookDialog", "Kitchen", nullptr));
        chKnife->setText(QApplication::translate("NotebookDialog", "Knife", nullptr));
        chLeadPipe->setText(QApplication::translate("NotebookDialog", "Lead Pipe", nullptr));
        chRevolver->setText(QApplication::translate("NotebookDialog", "Revolver", nullptr));
        chRope->setText(QApplication::translate("NotebookDialog", "Rope", nullptr));
        chWrench->setText(QApplication::translate("NotebookDialog", "Wrench", nullptr));
        gbNotes->setTitle(QApplication::translate("NotebookDialog", "Notes", nullptr));
        btnClose->setText(QApplication::translate("NotebookDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NotebookDialog: public Ui_NotebookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEBOOKDIALOG_H
