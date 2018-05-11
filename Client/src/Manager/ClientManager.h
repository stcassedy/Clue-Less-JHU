#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "BoardEnums.h"
#include "BoardElement.h"
#include "Envelope.h"
#include "Card.h"
#include "GamePhaseEnums.h"
#include "ServerProtocol.h"
#include <QMessageBox>

//Foward Declarations
class Player;
class ClientWindow;
class Connection;

class ClientManager
{
private:
    /**
     * @brief ClientManager consturctor
     */
    explicit ClientManager();

    /**
     * @brief ~ClientManager() destructor
     */
    ~ClientManager();

    // Member Variables
    static ClientManager m_instance;
    PlayerEnum m_currentPlayer;
    PlayerEnum m_currentPlayerTurn;
    GamePhaseEnum m_currentPhase;
    int m_numberOfPlayers;
    ClientWindow* m_clientWindow;
    bool m_serverConnection;
    Connection* m_tcpConnection;
    PlayerEnum m_suggestor;
    bool m_movedForSuggestion;
    bool m_refuted;
    QMessageBox* m_sugMsgBox;
    QMessageBox* m_sugNotRefBox;
    QMessageBox* m_refMsgBox;
    QMessageBox* m_accMsgBox;
    QMessageBox* m_accResultMsgBox;

public:
    /**
     * @brief getInstance returns pointer to the instance
     * @return ClientManager*
     */
    static ClientManager* getInstance();

    /**
     * @brief setClientWindow sets a pointer to the client window
     * @param clientWindow*
     */
    void setClientWindow(ClientWindow* clientWindow);

    /**
     * @brief getClientWindow returns a pointer to the client window
     * @return clientWindow*
     */
    ClientWindow* getClientWindow();

    /**
     * @brief startGame commands server to start the game
     */
    void startGame();

    /**
     * @brief movePlayer
     * @param destination
     */
    void movePlayer(BoardElement* destination);

    /**
     * @brief makeSuggestion
     * @param room
     * @param player
     * @param weapon
     */
    void makeSuggestion(RoomCard *room, PlayerCard *player, WeaponCard *weapon);

    /**
     * @brief refuteSuggestion
     * @param card
     */
    void refuteSuggestion(Card* card);

    /**
     * @brief makeAccusation
     * @param room
     * @param player
     * @param weapon
     */
    void makeAccusation(RoomCard* room, PlayerCard* player, WeaponCard* weapon);

    /**
     * @brief changePlayerCharacter
     * @param character
     * @param playerName
     */
    void changePlayerCharacter(PlayerEnum character, std::string playerName);

    /**
     * @brief sendGameUpdate
     * @param clientUpdate
     */
    void sendGameUpdate(std::string clientUpdate);

    /**
     * @brief receiveGameState
     * @param gameState
     */
    void receiveGameState(std::string gameState);

    /**
     * @brief endTurn handles a player choosing to end their turn
     */
    void endTurn();

    /**
     * @brief connectToServer connects to server based on inputs
     * @param host QString
     * @param port int
     */
    void connectToServer(QString host, int port);

    /**
     * @brief getCurrentPlayer returns the client player
     * @return Player*
     */
    Player* getCurrentPlayer();

    /**
     * @brief getCurrentPlayerTurn return the player whose turn it is
     * @return Player*
     */
    Player* getCurrentPlayerTurn();

    /**
     * @brief getCurrentGamePhase returns the current game phase
     * @return GamePhaseEnum
     */
    GamePhaseEnum getCurrentGamePhase();

    /**
     * @brief getNumberOfPlayers returns the number of game players
     * @return int
     */
    int getNumberOfPlayers();

    /**
     * @brief serverConnected determines if connected to the server
     * @return bool true if server is connected, false otherwise
     */
    bool serverConnected();

    /**
     * @brief processServerAction processes incoming actions from the Server
     * @param act protocol::Action*
     */
    void processServerAction(protocol::Action* act);

    /**
     * @brief movedForSuggestion determines if the player was moved for a
     * suggestion
     * @return bool true if last move was for a suggestion
     */
    bool movedForSuggestion();

    /**
     * @brief refutedThisTurn determines if a suggestion was refuted for this
     * player's turn
     * @return bool true if refuted this turn, false otherwise
     */
    bool refutedThisTurn();

    /**
     * @brief initMsgBoxes initializes the msg boxes
     */
    void initMsgBoxes();

    /**
     * @brief destroyMsgBoxes destroys the msg boxes
     */
    void destroyMsgBoxes();

    /**
     * @brief closeApplication closes the clien
     */
    void closeApplication();

private:
    /**
     * @brief processMovement process movement action from server
     * @param mov protocol::Movement*
     */
    void processMovement(protocol::Movement* mov);

    /**
     * @brief processSuggestion process suggestion action from server
     * @param sug protocol::Suggestion*
     */
    void processSuggestion(protocol::Suggestion* sug);

    /**
     * @brief processAccusation process accusation action from server
     * @param acc protocol::Accusation*
     */
    void processAccusation(protocol::Accusation* acc);

    /**
     * @brief processRefutation process refutation action from server
     * @param ref protocol::Refutation*
     */
    void processRefutation(protocol::Refutation* ref);

    /**
     * @brief processInitialization process initialization action from server
     * @param init protocol::Initialization*
     */
    void processInitialization(protocol::Initialization* init);

    /**
     * @brief processPlayerConnect process player connection action from server
     * @param con protocol::PlayerConnect*
     */
    void processPlayerConnect(protocol::PlayerConnect* con);

    /**
     * @brief processChangeTurn process turn change
     * @param turn protocol::ChangeTurn*
     */
    void processChangeTurn(protocol::ChangeTurn* turn);

    /**
     * @brief getNextPlayer determines which player takes the next action
     * @param player Player*
     * @return Player*
     */
    Player* getNextPlayer(Player* player);

    /**
     * @brief refutable determines if a player can refute a suggestion
     * @param player Player*
     * @param wCard WeaponCard*
     * @param pCard PlayerCard*
     * @param rCard RoomCard*
     * @return bool true if player can refute, false otherwise
     */
    bool refutable(Player* player, WeaponCard* wCard,
                   PlayerCard* pCard, RoomCard* rCard);

    /**
     * @brief getRefutationPlayer returns the player to refute a suggestion
     * @param player Player*
     * @param wCard WeaponCard*
     * @param pCard PlayerCard*
     * @param rCard RoomCard*
     * @return Player*
     */
    Player* getRefutationPlayer(Player* player, WeaponCard* wCard,
                                PlayerCard* pCard, RoomCard* rCard);

    /**
     * @brief getNextPlayerIncludingDead gets the next player including players
     * who have already lost
     * @param player Player*
     * @return Player*
     */
    Player* getNextPlayerIncludingDead(Player* player);

    /**
     * @brief playersDead determines if all of the players have lost
     * @return bool true if all the players have lost, false otherwise
     */
    bool playersDead();

};

#endif // CLIENTMANAGER_H
