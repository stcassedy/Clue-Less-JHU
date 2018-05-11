#include "ClientManager.h"

#include "BoardEnums.h"
#include "BoardElement.h"
#include "Envelope.h"
#include "Card.h"
#include "Hand.h"
#include "PlayerCard.h"
#include "RoomCard.h"
#include "WeaponCard.h"
#include "Player.h"
#include "Board.h"
#include "ClientWindow.h"
#include "Connection.h"
#include "Room.h"
#include <QMessageBox>

#include <QDebug>

//---------------------------------------------------------------
//Static Variables:
ClientManager ClientManager::m_instance;

//---------------------------------------------------------------
//Constructor:
ClientManager::ClientManager() :
    m_currentPlayer(MISS_SCARLET),
    m_currentPlayerTurn(MISS_SCARLET),
    m_currentPhase(NOT_JOINED),
    m_numberOfPlayers(1),
    m_clientWindow(NULL),
    m_serverConnection(false),
    m_tcpConnection(NULL),
    m_suggestor(MISS_SCARLET),
    m_movedForSuggestion(false),
    m_refuted(false),
    m_sugMsgBox(NULL),
    m_sugNotRefBox(NULL),
    m_refMsgBox(NULL),
    m_accMsgBox(NULL),
    m_accResultMsgBox(NULL)
{
    //initializes the board
    Board::makeInstance();
}

//---------------------------------------------------------------
//Constructor:
ClientManager::~ClientManager()
{
    //destroys the board
    Board::destroyInstance();

    //deletes tcp connection
    if (m_tcpConnection != NULL)
    {
        delete m_tcpConnection;
    }
}

//---------------------------------------------------------------
//Public Functions:
ClientManager* ClientManager::getInstance()
{
    //returns a pointer to the ClientManager instance
    return &m_instance;
}

void ClientManager::setClientWindow(ClientWindow* clientWindow)
{
    //sets the pointer to the client window
    m_clientWindow = clientWindow;
}

ClientWindow* ClientManager::getClientWindow()
{
    //returns a pointer to the client window
    return m_clientWindow;
}

void ClientManager::startGame()
{
    //tell server to start the game!
    qDebug() << "Start Game!";
}

void ClientManager::movePlayer(BoardElement* destination)
{
    //Get current player info
    Player* player = Board::getInstance()->getPlayer(m_currentPlayer);

    qDebug() << "Player: " << player->getPlayerNum();
    qDebug() << "Destination Type: " << destination->getBoardElementType();
    qDebug() << "Destination: " << destination->getBoardElementEnum();

    //Form movement message to send to server
    protocol::Movement move(player->getPlayerNum(),
                            destination->getBoardElementType(),
                            destination->getBoardElementEnum());
    QByteArray moveMessage = protocol::form_movement(move);

    //last move was made by a move command
    m_movedForSuggestion = false;

    //Send message through connection
    m_tcpConnection->send(moveMessage);

    //Form change turn message
    protocol::ChangeTurn turn(player->getPlayerNum(),
                                     player->getPlayerNum(),
                                     SUGGESTION);
    QByteArray turnMessage = protocol::form_change_turn(turn);

    //Send message through connection
    m_tcpConnection->send(turnMessage);

}

void ClientManager::makeSuggestion(RoomCard* room, PlayerCard* player,
                                   WeaponCard* weapon)
{
    //Get current player info
    Player* curPlayer = Board::getInstance()->getPlayer(m_currentPlayer);

    qDebug() << "Suggested Room: " << room->getCardName();
    qDebug() << "Suggested Player: " << player->getCardName();
    qDebug() << "Accused Weapon: " << weapon->getCardName();

    //making a suggestion clears flag
    m_movedForSuggestion = false;

    //Build up message to send to server
    protocol::Suggestion suggestion(curPlayer->getPlayerNum(),
                                    player->getCardIdentifier(),
                                    room->getCardIdentifier(),
                                    weapon->getCardIdentifier());
    QByteArray suggestionMessage = protocol::form_suggestion(suggestion);

    //Send message through connection
    m_tcpConnection->send(suggestionMessage);

    //determines the next phase
    Envelope env;
    env.setPlayerCard(player);
    env.setWeaponCard(weapon);
    env.setRoomCard(room);
    if (Board::getInstance()->getHiddenEnvelope()->isAccusationCorrect(&env))
    {
        //Form change turn message
        protocol::ChangeTurn turn(curPlayer->getPlayerNum(),
                                         curPlayer->getPlayerNum(),
                                         ACCUSATION);
        QByteArray turnMessage = protocol::form_change_turn(turn);

        //Send message through connection
        m_tcpConnection->send(turnMessage);
    }
    else
    {
        //gets the player for refuting
        Player* refPlayer = getRefutationPlayer(curPlayer, weapon, player,room);

        //checks if none of the other players could refute the suggestion
        if (refPlayer == curPlayer)
        {
            //Form change turn message
            protocol::ChangeTurn turn(curPlayer->getPlayerNum(),
                                      curPlayer->getPlayerNum(),
                                      ACCUSATION);
            QByteArray turnMessage = protocol::form_change_turn(turn);

            //Send message through connection
            m_tcpConnection->send(turnMessage);
        }
        else
        {
            //Form change turn message
            protocol::ChangeTurn turn(curPlayer->getPlayerNum(),
                                      refPlayer->getPlayerNum(),
                                      REFUTATION);
            QByteArray turnMessage = protocol::form_change_turn(turn);

            //Send message through connection
            m_tcpConnection->send(turnMessage);
        }
    }
}

void ClientManager::refuteSuggestion(Card* card)
{
    //Get player info
    Player* curPlayer = Board::getInstance()->getPlayer(m_currentPlayer);

    //Get info for player's whos turn it is (suggesting player)
    Player* suggestingPlayer = Board::getInstance()->getPlayer(m_suggestor);

    qDebug() << "Suggesting Player: " << suggestingPlayer->getPlayerNum();
    qDebug() << "Refuting Player: " << curPlayer->getPlayerNum();
    qDebug() << "Refute Card: " << card->getCardName();

    protocol::Refutation refutation(curPlayer->getPlayerNum(),
                                    suggestingPlayer->getPlayerNum(),
                                    card->getCardIdentifier());
    QByteArray refutationMessage = protocol::form_refutation(refutation);

    //Send message through connection
    m_tcpConnection->send(refutationMessage);

    //Form change turn message
    protocol::ChangeTurn turn(curPlayer->getPlayerNum(),
                                     m_suggestor,
                                     ACCUSATION);
    QByteArray turnMessage = protocol::form_change_turn(turn);

    //Send message through connection
    m_tcpConnection->send(turnMessage);
}

void ClientManager::makeAccusation(RoomCard *room, PlayerCard *player,
                                   WeaponCard *weapon)
{ 
    //Get player info
    Player* curPlayer = Board::getInstance()->getPlayer(m_currentPlayer);

    qDebug() << "Accusing Player: " << curPlayer->getPlayerNum();
    qDebug() << "Accused Room: " << room->getCardName();
    qDebug() << "Accused Player: " << player->getCardName();
    qDebug() << "Accused Weapon: " << weapon->getCardName();

    //Build up accusation message
    protocol::Accusation accusation(curPlayer->getPlayerNum(),
                                    player->getCardIdentifier(),
                                    room->getCardIdentifier(),
                                    weapon->getCardIdentifier());
    QByteArray accusationMessage = protocol::form_accusation(accusation);

    //Send message through connection
    m_tcpConnection->send(accusationMessage);

    //determines if another turn is necessary
    Envelope env;
    env.setPlayerCard(player);
    env.setWeaponCard(weapon);
    env.setRoomCard(room);
    if (!Board::getInstance()->getHiddenEnvelope()->isAccusationCorrect(&env))
    {
        //Build up the change turn message
        protocol::ChangeTurn changeTurn(curPlayer->getPlayerNum(),
                                        getNextPlayer(curPlayer)->
                                        getPlayerNum(),
                                        MOVE);
        QByteArray changeTurnMessage = protocol::form_change_turn(changeTurn);

        //Send message through connection
        m_tcpConnection->send(changeTurnMessage);
    }
}

void ClientManager::endTurn()
{
    //Get player info
    Player* curPlayer = Board::getInstance()->getPlayer(m_currentPlayer);

    //Get next player
    Player* nextPlayer = getNextPlayer(curPlayer);

    qDebug() << "End Turn for Player " << curPlayer->getPlayerNum();
    qDebug() << "Transition to Player " << nextPlayer->getPlayerNum();

    //Build up the change turn message
    protocol::ChangeTurn changeTurn(curPlayer->getPlayerNum(),
                                    nextPlayer->getPlayerNum(),
                                    MOVE);
    QByteArray changeTurnMessage = protocol::form_change_turn(changeTurn);

    //clears refuted flag
    m_refuted = false;

    //Send message through connection
    m_tcpConnection->send(changeTurnMessage);
}

void ClientManager::connectToServer(QString host, int port)
{
    //deletes the old connection
    if (m_tcpConnection != NULL)
    {
        delete m_tcpConnection;
        m_tcpConnection = NULL;
    }

    qDebug() << "Host Address: " << host;
    qDebug() << "Port: " << QString::number(port);

    //creates a new connection and attempts to open the connection
    m_tcpConnection = new Connection(host, port);
    m_serverConnection = m_tcpConnection->openConnection();
    if (!m_serverConnection)
    {
        qDebug() << "Connection timed out";
    }
}

Player* ClientManager::getCurrentPlayer()
{
    //returns the client player
    Player* player = Board::getInstance()->getPlayer(m_currentPlayer);
    return player;
}

Player* ClientManager::getCurrentPlayerTurn()
{
    //returns the player whose turn it is
    Player* player = Board::getInstance()->getPlayer(m_currentPlayerTurn);
    return player;
}

GamePhaseEnum ClientManager::getCurrentGamePhase()
{
    //returns the current game phase
    return m_currentPhase;
}

int ClientManager::getNumberOfPlayers()
{
    //returns the current number of players
    return m_numberOfPlayers;
}

bool ClientManager::serverConnected()
{
    return m_serverConnection;
}

void ClientManager::processServerAction(protocol::Action* act)
{
    //checks the action is not null
    if (act != NULL)
    {
        //Determine message type
        protocol::MessageType type = act->messageType;

        qDebug() << "Message Type: " << act->messageType;

        //process message based on type
        if (type == protocol::MOVEMENT)
        {
            protocol::Movement* mov =
                    reinterpret_cast<protocol::Movement*>(act);
            processMovement(mov);
        }
        else if (type == protocol::SUGGESTION)
        {
            protocol::Suggestion* sug =
                    reinterpret_cast<protocol::Suggestion*>(act);
            processSuggestion(sug);
        }
        else if (type == protocol::ACCUSATION)
        {
            protocol::Accusation* acc =
                    reinterpret_cast<protocol::Accusation*>(act);
            processAccusation(acc);
        }
        else if (type == protocol::REFUTATION)
        {
            protocol::Refutation* ref =
                    reinterpret_cast<protocol::Refutation*>(act);
            processRefutation(ref);
        }
        else if (type == protocol::INITIALIZATION)
        {
            protocol::Initialization* init =
                    reinterpret_cast<protocol::Initialization*>(act);
            processInitialization(init);
        }
        else if (type == protocol::PLAYER_CONNECT)
        {
            protocol::PlayerConnect* con =
                    reinterpret_cast<protocol::PlayerConnect*>(act);
            processPlayerConnect(con);
        }
        else if (type == protocol::CHANGE_TURN)
        {
            protocol::ChangeTurn* turn =
                    reinterpret_cast<protocol::ChangeTurn*>(act);
            processChangeTurn(turn);
        }
    }
}

bool ClientManager::movedForSuggestion()
{
    return m_movedForSuggestion;
}

bool ClientManager::refutedThisTurn()
{
    return m_refuted;
}

void ClientManager::initMsgBoxes()
{
    m_sugMsgBox = new QMessageBox();
    m_sugMsgBox->setModal(false);
    m_sugNotRefBox = new QMessageBox();
    m_sugNotRefBox->setModal(false);
    m_refMsgBox = new QMessageBox();
    m_refMsgBox->setModal(false);
    m_accMsgBox = new QMessageBox();
    m_accMsgBox->setModal(false);
    m_accResultMsgBox = new QMessageBox();
    m_accResultMsgBox->setModal(false);
}

void ClientManager::destroyMsgBoxes()
{
    if (m_sugMsgBox != NULL)
    {
        delete m_sugMsgBox;
        m_sugMsgBox = NULL;
    }
    if (m_sugNotRefBox != NULL)
    {
        delete m_sugNotRefBox;
        m_sugNotRefBox = NULL;
    }
    if (m_refMsgBox != NULL)
    {
        delete m_refMsgBox;
        m_refMsgBox = NULL;
    }
    if (m_accMsgBox != NULL)
    {
        delete m_accMsgBox;
        m_accMsgBox = NULL;
    }
    if (m_accResultMsgBox != NULL)
    {
        delete m_accResultMsgBox;
        m_accResultMsgBox = NULL;
    }
}

void ClientManager::closeApplication()
{
    //notifies user of closure
    QString msg = "Connection with server was lost. Closing application.";
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();

    //closes the client window
    m_clientWindow->close();
}

//---------------------------------------------------------------
//Private:
void ClientManager::processMovement(protocol::Movement* mov)
{
    //moves the player and updates the UI
    Player* player = Board::getInstance()->getPlayer(mov->playerSource);
    BoardElement* elem = Board::getInstance()->getBoardElement(mov->location);
    player->move(elem);
    m_clientWindow->updateUI();

    //deletes pointer to prevent memory leak
    delete mov;
}

void ClientManager::processSuggestion(protocol::Suggestion* sug)
{
    //tracks who made a suggestion
    m_suggestor = sug->playerSource;

    //gets the suggested cards
    Card* pCard = Board::getInstance()->getCard(sug->playerSuggested);
    Card* wCard = Board::getInstance()->getCard(sug->weapon);
    Card* rCard = Board::getInstance()->getCard(sug->location);
    PlayerCard* playerCard = dynamic_cast<PlayerCard*>(pCard);
    WeaponCard* weaponCard = dynamic_cast<WeaponCard*>(wCard);
    RoomCard* roomCard = dynamic_cast<RoomCard*>(rCard);

    //moves suggested player
    Player* suggested = Board::getInstance()->getPlayerForCard(playerCard);
    Room* suggestedRoom = Board::getInstance()->getRoomForCard(roomCard);
    suggested->move(suggestedRoom);

    //shows message box describing the action
    QString msg = Board::getInstance()->
            getPlayerStringFromEnum(sug->playerSource) +
            QString( " suggests ") +
            pCard->getCardName() + QString(" did it with the ") +
            wCard->getCardName() + QString(" in the ") +
            rCard->getCardName() + QString(".");
    m_sugMsgBox->setText(msg);
    m_sugMsgBox->show();

    //determines if the suggestor can be refuted
    Player* suggestor = Board::getInstance()->getPlayer(m_suggestor);
    Player* refutor =
            getRefutationPlayer(suggestor, weaponCard, playerCard, roomCard);
    if (refutor == suggestor)
    {
        //player could not be refuted
        QString resultMsg = Board::getInstance()->
                getPlayerStringFromEnum(sug->playerSource) +
                QString(" cannot be refuted!");
        m_sugNotRefBox->setText(resultMsg);
        m_sugNotRefBox->show();
    }

    //sets suggestion cards in the refutation dialog
    RefutationDialog::setSuggestionCards(weaponCard, roomCard, playerCard);

    //tracks if current player was moved for a suggestion
    if (suggested->getPlayerNum() == m_currentPlayer)
    {
        m_movedForSuggestion = true;
    }

    //deletes pointer to prevent memory leak
    delete sug;
}

void ClientManager::processAccusation(protocol::Accusation* acc)
{
    //gets the suggested cards
    Card* pCard = Board::getInstance()->getCard(acc->playerAccused);
    Card* wCard = Board::getInstance()->getCard(acc->weapon);
    Card* rCard = Board::getInstance()->getCard(acc->location);

    //shows message box describing the action
    QString msg = Board::getInstance()->
            getPlayerStringFromEnum(acc->playerSource) +
            QString( " claims ") +
            pCard->getCardName() + QString(" did it with the ") +
            wCard->getCardName() + QString(" in the ") +
            rCard->getCardName() + QString(".");
    m_accMsgBox->setText(msg);
    m_accMsgBox->show();

    //determines if the accusor wins or loses
    Envelope env;
    PlayerCard* playerCard = dynamic_cast<PlayerCard*>(pCard);
    WeaponCard* weaponCard = dynamic_cast<WeaponCard*>(wCard);
    RoomCard* roomCard = dynamic_cast<RoomCard*>(rCard);
    env.setPlayerCard(playerCard);
    env.setWeaponCard(weaponCard);
    env.setRoomCard(roomCard);
    if (Board::getInstance()->getHiddenEnvelope()->isAccusationCorrect(&env))
    {
        //player was correct, the game is over and closing
        QString resultMsg = Board::getInstance()->
                getPlayerStringFromEnum(acc->playerSource) +
                QString(" wins the game! The game will now close. "
                        "Thanks for playing!");
        m_accResultMsgBox->setText(resultMsg);
        m_accResultMsgBox->show();
        m_clientWindow->close();
    }
    else
    {
        //player was wrong and are now tracked as lost
        Player* deadPlayer = Board::getInstance()->getPlayer(acc->playerSource);
        QString resultMsg = Board::getInstance()->
                getPlayerStringFromEnum(acc->playerSource) +
                QString(" has lost the game.");
        m_accResultMsgBox->setText(resultMsg);
        m_accResultMsgBox->show();
        deadPlayer->playerLost();
    }

    //deletes pointer to prevent memory leak
    delete acc;

    //ends game if all players are dead :(
    if (playersDead())
    {
        QMessageBox gameOver;
        gameOver.setText("All  players have lost! The game is now closing.");
        gameOver.exec();
        m_sugMsgBox->close();
        m_sugNotRefBox->close();
        m_refMsgBox->close();
        m_accMsgBox->close();
        m_accResultMsgBox->close();
        m_clientWindow->close();
    }
}

void ClientManager::processRefutation(protocol::Refutation* ref)
{
    //gets the refuted card
    Card* card = Board::getInstance()->getCard(ref->card);

    if (m_currentPlayer == m_suggestor)
    {
        m_refuted = true;
    }

    //shows message box describing the action
    QString msg = Board::getInstance()->
            getPlayerStringFromEnum(ref->playerSource) +
            QString( " refuted ") +
            Board::getInstance()->
            getPlayerStringFromEnum(ref->playerRefuted) +
            QString("'s suggestion with the ") +
            card->getCardName() + QString(" card.");
    m_refMsgBox->setText(msg);
    m_refMsgBox->show();

    //deletes pointer to prevent memory leak
    delete ref;
}

void ClientManager::processInitialization(protocol::Initialization* init)
{
    //sets the number of players connected
    m_numberOfPlayers = init->numConnected;
    m_currentPhase = MOVE;

    //gets players for updating hands
    Player* p1 = Board::getInstance()->getPlayer(MISS_SCARLET);
    Player* p2 = Board::getInstance()->getPlayer(COL_MUSTARD);
    Player* p3 = Board::getInstance()->getPlayer(MRS_WHITE);
    Player* p4 = Board::getInstance()->getPlayer(MR_GREEN);
    Player* p5 = Board::getInstance()->getPlayer(MRS_PEACOCK);
    Player* p6 = Board::getInstance()->getPlayer(PROF_PLUM);

    //gets hidden cards
    WeaponCard* wCard = dynamic_cast<WeaponCard*>(
                Board::getInstance()->getCard(init->hiddenWeapon));
    PlayerCard* pCard = dynamic_cast<PlayerCard*>(
                Board::getInstance()->getCard(init->hiddenSuspect));
    RoomCard* rCard = dynamic_cast<RoomCard*>(
                Board::getInstance()->getCard(init->hiddenRoom));
    Envelope* hiddenEnv = Board::getInstance()->getHiddenEnvelope();
    hiddenEnv->setWeaponCard(wCard);
    hiddenEnv->setPlayerCard(pCard);
    hiddenEnv->setRoomCard(rCard);

    //sets the player cards
    p1->giveCard(Board::getInstance()->getCard(init->p1Card1));
    p1->giveCard(Board::getInstance()->getCard(init->p1Card2));
    p1->giveCard(Board::getInstance()->getCard(init->p1Card3));
    p1->giveCard(Board::getInstance()->getCard(init->p1Card4));
    p1->giveCard(Board::getInstance()->getCard(init->p1Card5));
    p1->giveCard(Board::getInstance()->getCard(init->p1Card6));
    p2->giveCard(Board::getInstance()->getCard(init->p2Card1));
    p2->giveCard(Board::getInstance()->getCard(init->p2Card2));
    p2->giveCard(Board::getInstance()->getCard(init->p2Card3));
    p2->giveCard(Board::getInstance()->getCard(init->p2Card4));
    p2->giveCard(Board::getInstance()->getCard(init->p2Card5));
    p2->giveCard(Board::getInstance()->getCard(init->p2Card6));
    p3->giveCard(Board::getInstance()->getCard(init->p3Card1));
    p3->giveCard(Board::getInstance()->getCard(init->p3Card2));
    p3->giveCard(Board::getInstance()->getCard(init->p3Card3));
    p3->giveCard(Board::getInstance()->getCard(init->p3Card4));
    p3->giveCard(Board::getInstance()->getCard(init->p3Card5));
    p3->giveCard(Board::getInstance()->getCard(init->p3Card6));
    p4->giveCard(Board::getInstance()->getCard(init->p3Card1));
    p4->giveCard(Board::getInstance()->getCard(init->p3Card2));
    p4->giveCard(Board::getInstance()->getCard(init->p3Card3));
    p4->giveCard(Board::getInstance()->getCard(init->p3Card4));
    p5->giveCard(Board::getInstance()->getCard(init->p5Card1));
    p5->giveCard(Board::getInstance()->getCard(init->p5Card2));
    p5->giveCard(Board::getInstance()->getCard(init->p5Card3));
    p6->giveCard(Board::getInstance()->getCard(init->p6Card1));
    p6->giveCard(Board::getInstance()->getCard(init->p6Card2));
    p6->giveCard(Board::getInstance()->getCard(init->p6Card3));

    //sets players not playing as lost
    if (m_numberOfPlayers == 3)
    {
        Board::getInstance()->getPlayer(MR_GREEN)->playerLost();
        Board::getInstance()->getPlayer(MRS_PEACOCK)->playerLost();
        Board::getInstance()->getPlayer(PROF_PLUM)->playerLost();
    }
    else if (m_numberOfPlayers == 4)
    {
        Board::getInstance()->getPlayer(MRS_PEACOCK)->playerLost();
        Board::getInstance()->getPlayer(PROF_PLUM)->playerLost();
    }
    else if (m_numberOfPlayers == 5)
    {
        Board::getInstance()->getPlayer(PROF_PLUM)->playerLost();
    }

    //updates the UI
    m_clientWindow->moveToGameBoardView();
    m_clientWindow->updateUI();

    //deletes pointer to prevent memory leak
    delete init;
}

void ClientManager::processPlayerConnect(protocol::PlayerConnect* con)
{
    //sets the current client player
    m_currentPlayer = con->playerAssignment;
    m_clientWindow->updateUI();

    //deletes pointer to prevent memory leak
    delete con;
}

void ClientManager::processChangeTurn(protocol::ChangeTurn* turn)
{
    //updates the active player and the game phase
    m_currentPlayerTurn = turn->activePlayer;
    m_currentPhase = turn->gamePhase;
    m_clientWindow->updateUI();

    //deletes pointer to prevent memory leak
    delete turn;
}

Player* ClientManager::getNextPlayer(Player* player)
{
    //determines current player
    if (player->getPlayerNum() == MISS_SCARLET)
    {
        //gets the next player
        Player* next = Board::getInstance()->getPlayer(COL_MUSTARD);

        //determines if the player is still in the game
        if (next->playerStillInGame())
        {
            return next;
        }
        else
        {
            return getNextPlayer(next);
        }
    }
    else if (player->getPlayerNum() == COL_MUSTARD)
    {
        //gets the next player
        Player* next = Board::getInstance()->getPlayer(MRS_WHITE);

        //determines if the player is still in the game
        if (next->playerStillInGame())
        {
            return next;
        }
        else
        {
            return getNextPlayer(next);
        }
    }
    else if (player->getPlayerNum() == MRS_WHITE)
    {
        //gets the next player
        Player* next = NULL;
        if (m_numberOfPlayers == 3)
        {
            next = Board::getInstance()->getPlayer(MISS_SCARLET);
        }
        else
        {
            next = Board::getInstance()->getPlayer(MR_GREEN);
        }

        //determines if the player is still in the game
        if (next->playerStillInGame())
        {
            return next;
        }
        else
        {
            return getNextPlayer(next);
        }

    }
    else if (player->getPlayerNum() == MR_GREEN)
    {
        //gets the next player
        Player* next = NULL;
        if (m_numberOfPlayers == 4)
        {
            next = Board::getInstance()->getPlayer(MISS_SCARLET);
        }
        else
        {
            next = Board::getInstance()->getPlayer(MRS_PEACOCK);
        }

        //determines if the player is still in the game
        if (next->playerStillInGame())
        {
            return next;
        }
        else
        {
            return getNextPlayer(next);
        }
    }
    else if (player->getPlayerNum() == MRS_PEACOCK)
    {
        //gets the next player
        Player* next = NULL;
        if (m_numberOfPlayers == 5)
        {
            next = Board::getInstance()->getPlayer(MISS_SCARLET);
        }
        else
        {
            next = Board::getInstance()->getPlayer(PROF_PLUM);
        }

        //determines if the player is still in the game
        if (next->playerStillInGame())
        {
            return next;
        }
        else
        {
            return getNextPlayer(next);
        }
    }
    else
    {
        //gets the next player
        Player* next = Board::getInstance()->getPlayer(MISS_SCARLET);

        //determines if the player is still in the game
        if (next->playerStillInGame())
        {
            return next;
        }
        else
        {
            return getNextPlayer(next);
        }
    }
}

bool ClientManager::refutable(Player* player, WeaponCard* wCard,
                              PlayerCard* pCard, RoomCard* rCard)
{
    //gets the player card lists
    QList<WeaponCard*> weaponCardList = player->getWeaponCards();
    QList<RoomCard*> roomCardList = player->getRoomCards();
    QList<PlayerCard*> playerCardList = player->getPlayerCards();

    //checks if the player has the weapon card
    if (weaponCardList.contains(wCard))
    {
        //the cards are refutable
        return true;
    }

    //checks if the player has the room card
    if (roomCardList.contains(rCard))
    {
        //the cards are refutable
        return true;
    }

    //checks if the player has the player card
    if (playerCardList.contains(pCard))
    {
        //the cards are refutable
        return true;
    }

    //the cards are not refutable
    return false;
}

Player* ClientManager::getRefutationPlayer(Player* player, WeaponCard* wCard,
                                           PlayerCard* pCard, RoomCard* rCard)
{
    //tracks if a player is found
    bool playerFound = false;
    Player* foundPlayer = player;

    //loops until a player is found or complete circle is made
    while(!playerFound)
    {
        //gets next player
        foundPlayer = getNextPlayerIncludingDead(foundPlayer);

        //checks if the player can refute
        if (foundPlayer == player ||
            refutable(foundPlayer, wCard, pCard, rCard))
        {
            playerFound = true;
        }
    }

    return foundPlayer;
}

Player* ClientManager::getNextPlayerIncludingDead(Player* player)
{
    //determines current player
    if (player->getPlayerNum() == MISS_SCARLET)
    {
        //gets the next player
        Player* next = Board::getInstance()->getPlayer(COL_MUSTARD);
        return next;
    }
    else if (player->getPlayerNum() == COL_MUSTARD)
    {
        //gets the next player
        Player* next = Board::getInstance()->getPlayer(MRS_WHITE);
        return next;
    }
    else if (player->getPlayerNum() == MRS_WHITE)
    {
        //gets the next player
        Player* next = NULL;
        if (m_numberOfPlayers == 3)
        {
            next = Board::getInstance()->getPlayer(MISS_SCARLET);
        }
        else
        {
            next = Board::getInstance()->getPlayer(MR_GREEN);
        }

        return next;

    }
    else if (player->getPlayerNum() == MR_GREEN)
    {
        //gets the next player
        Player* next = NULL;
        if (m_numberOfPlayers == 4)
        {
            next = Board::getInstance()->getPlayer(MISS_SCARLET);
        }
        else
        {
            next = Board::getInstance()->getPlayer(MRS_PEACOCK);
        }

        return getNextPlayer(next);
    }
    else if (player->getPlayerNum() == MRS_PEACOCK)
    {
        //gets the next player
        Player* next = NULL;
        if (m_numberOfPlayers == 5)
        {
            next = Board::getInstance()->getPlayer(MISS_SCARLET);
        }
        else
        {
            next = Board::getInstance()->getPlayer(PROF_PLUM);
        }

        return getNextPlayer(next);
    }
    else
    {
        //gets the next player
        Player* next = Board::getInstance()->getPlayer(MISS_SCARLET);
        return next;
    }
}

bool ClientManager::playersDead()
{
    //gets a list of all the players
    QList<Player*> pList = Board::getInstance()->getAllPlayers();

    //checks if any player is still alive
    for (int i = 0; i < pList.size(); ++i)
    {
        //check if someone is still playing
        if (pList.at(i)->playerStillInGame())
        {
            return false;
        }
    }

    //everyone has lost :(
    return true;
}
