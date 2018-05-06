#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "BoardEnums.h"
#include "BoardElement.h"
#include "Envelope.h"
#include "Card.h"
#include "GamePhaseEnums.h"

//Foward Declarations
class Player;
class ClientWindow;

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
     * @return
     */
    bool makeSuggestion(RoomCard *room, PlayerCard *player, WeaponCard *weapon);

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
     * @return
     */
    bool makeAccusation(RoomCard* room, PlayerCard* player, WeaponCard* weapon);

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
     * @brief connectToServer
     */
    void connectToServer();

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

};

#endif // CLIENTMANAGER_H
