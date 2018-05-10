#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "BoardEnums.h"
#include "BoardElement.h"
#include "Envelope.h"
#include "Card.h"
#include "GamePhaseEnums.h"
#include "ServerProtocol.h"

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
    bool m_stillPlaying;

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
     * @brief getPlayerStringFromEnum gets the player string from an enum
     * @param pEnum PlayerEnum
     * @return QString
     */
    QString getPlayerStringFromEnum(PlayerEnum pEnum);

private:
    /**
     * @brief getNextPlayer determines which player takes the next action
     * @return Player*
     */
    Player* getNextPlayer();
};

#endif // CLIENTMANAGER_H
