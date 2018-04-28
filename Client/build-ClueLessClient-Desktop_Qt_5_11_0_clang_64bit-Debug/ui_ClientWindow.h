/********************************************************************************
** Form generated from reading UI file 'ClientWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QWidget *centralWidget;
    QPushButton *NavigateBoard;
    QPushButton *MakeSuggestion;
    QPushButton *Refute;
    QPushButton *MakeAccusation;
    QPushButton *ViewNotebook;
    QFrame *ClientBoardFrame;
    QTextEdit *Conservatory;
    QTextEdit *Ballroom;
    QTextEdit *Kitchen;
    QTextEdit *DiningRoom;
    QTextEdit *BilliardRoom;
    QTextEdit *Library;
    QTextEdit *Study;
    QTextEdit *Hall;
    QTextEdit *Lounge;
    QPushButton *SendChat;
    QLabel *GameActions;
    QLabel *PlayerTurn;
    QPushButton *EndTurn;
    QLabel *MyCards;
    QTextEdit *GroupChat;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QStringLiteral("ClientWindow"));
        ClientWindow->resize(789, 572);
        centralWidget = new QWidget(ClientWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        NavigateBoard = new QPushButton(centralWidget);
        NavigateBoard->setObjectName(QStringLiteral("NavigateBoard"));
        NavigateBoard->setGeometry(QRect(0, 10, 141, 32));
        MakeSuggestion = new QPushButton(centralWidget);
        MakeSuggestion->setObjectName(QStringLiteral("MakeSuggestion"));
        MakeSuggestion->setGeometry(QRect(0, 40, 141, 32));
        Refute = new QPushButton(centralWidget);
        Refute->setObjectName(QStringLiteral("Refute"));
        Refute->setGeometry(QRect(0, 70, 141, 32));
        MakeAccusation = new QPushButton(centralWidget);
        MakeAccusation->setObjectName(QStringLiteral("MakeAccusation"));
        MakeAccusation->setGeometry(QRect(0, 100, 141, 32));
        ViewNotebook = new QPushButton(centralWidget);
        ViewNotebook->setObjectName(QStringLiteral("ViewNotebook"));
        ViewNotebook->setGeometry(QRect(0, 130, 141, 32));
        ClientBoardFrame = new QFrame(centralWidget);
        ClientBoardFrame->setObjectName(QStringLiteral("ClientBoardFrame"));
        ClientBoardFrame->setGeometry(QRect(160, 10, 601, 401));
        ClientBoardFrame->setFrameShape(QFrame::StyledPanel);
        ClientBoardFrame->setFrameShadow(QFrame::Raised);
        Conservatory = new QTextEdit(ClientBoardFrame);
        Conservatory->setObjectName(QStringLiteral("Conservatory"));
        Conservatory->setGeometry(QRect(10, 320, 141, 71));
        Conservatory->setReadOnly(true);
        Conservatory->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        Ballroom = new QTextEdit(ClientBoardFrame);
        Ballroom->setObjectName(QStringLiteral("Ballroom"));
        Ballroom->setGeometry(QRect(230, 320, 141, 74));
        Kitchen = new QTextEdit(ClientBoardFrame);
        Kitchen->setObjectName(QStringLiteral("Kitchen"));
        Kitchen->setGeometry(QRect(450, 320, 141, 74));
        DiningRoom = new QTextEdit(ClientBoardFrame);
        DiningRoom->setObjectName(QStringLiteral("DiningRoom"));
        DiningRoom->setGeometry(QRect(450, 170, 141, 74));
        BilliardRoom = new QTextEdit(ClientBoardFrame);
        BilliardRoom->setObjectName(QStringLiteral("BilliardRoom"));
        BilliardRoom->setGeometry(QRect(230, 170, 141, 74));
        Library = new QTextEdit(ClientBoardFrame);
        Library->setObjectName(QStringLiteral("Library"));
        Library->setGeometry(QRect(10, 170, 141, 74));
        Study = new QTextEdit(ClientBoardFrame);
        Study->setObjectName(QStringLiteral("Study"));
        Study->setGeometry(QRect(10, 10, 141, 74));
        Hall = new QTextEdit(ClientBoardFrame);
        Hall->setObjectName(QStringLiteral("Hall"));
        Hall->setGeometry(QRect(230, 10, 141, 74));
        Lounge = new QTextEdit(ClientBoardFrame);
        Lounge->setObjectName(QStringLiteral("Lounge"));
        Lounge->setGeometry(QRect(450, 10, 141, 74));
        SendChat = new QPushButton(centralWidget);
        SendChat->setObjectName(QStringLiteral("SendChat"));
        SendChat->setGeometry(QRect(0, 480, 141, 32));
        GameActions = new QLabel(centralWidget);
        GameActions->setObjectName(QStringLiteral("GameActions"));
        GameActions->setGeometry(QRect(10, 210, 121, 41));
        GameActions->setFrameShape(QFrame::Box);
        GameActions->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        PlayerTurn = new QLabel(centralWidget);
        PlayerTurn->setObjectName(QStringLiteral("PlayerTurn"));
        PlayerTurn->setGeometry(QRect(10, 270, 121, 41));
        PlayerTurn->setFrameShape(QFrame::Box);
        PlayerTurn->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        EndTurn = new QPushButton(centralWidget);
        EndTurn->setObjectName(QStringLiteral("EndTurn"));
        EndTurn->setGeometry(QRect(0, 160, 141, 32));
        MyCards = new QLabel(centralWidget);
        MyCards->setObjectName(QStringLiteral("MyCards"));
        MyCards->setGeometry(QRect(8, 335, 121, 141));
        MyCards->setFrameShape(QFrame::Box);
        MyCards->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        MyCards->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        GroupChat = new QTextEdit(centralWidget);
        GroupChat->setObjectName(QStringLiteral("GroupChat"));
        GroupChat->setGeometry(QRect(160, 420, 601, 74));
        ClientWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ClientWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 789, 22));
        ClientWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClientWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ClientWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ClientWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ClientWindow->setStatusBar(statusBar);

        retranslateUi(ClientWindow);

        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWindow)
    {
        ClientWindow->setWindowTitle(QApplication::translate("ClientWindow", "ClientWindow", nullptr));
        NavigateBoard->setText(QApplication::translate("ClientWindow", "Navigate Board", nullptr));
        MakeSuggestion->setText(QApplication::translate("ClientWindow", "Make Suggestion", nullptr));
        Refute->setText(QApplication::translate("ClientWindow", "Refute", nullptr));
        MakeAccusation->setText(QApplication::translate("ClientWindow", "Make Accusation", nullptr));
        ViewNotebook->setText(QApplication::translate("ClientWindow", "View Notebook", nullptr));
        SendChat->setText(QApplication::translate("ClientWindow", "Send Chat", nullptr));
        GameActions->setText(QApplication::translate("ClientWindow", "Game Actions", nullptr));
        PlayerTurn->setText(QApplication::translate("ClientWindow", "It's Colonel\n"
"Mustard's turn", nullptr));
        EndTurn->setText(QApplication::translate("ClientWindow", "End Turn", nullptr));
        MyCards->setText(QApplication::translate("ClientWindow", "My Cards", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
