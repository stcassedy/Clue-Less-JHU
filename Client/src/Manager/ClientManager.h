#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "BoardEnums.h"
#include "BoardElement.h"
#include "Envelope.h"
#include "Card.h"
#include "GamePhaseEnums.h"

//Foward Declarations
class Player;

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
    bool m_currentPlayerTurn;
    GamePhaseEnum m_currentPhase;
    int m_numberOfPlayers;

public:
    /**
     * @brief getInstance returns pointer to the instance
     * @return ClientManager*
     */
    static ClientManager* getInstance();

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
    void refuteSuggestion();

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
     * @brief startGame
     */
    void startGame();

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
     * @brief connectToServer
     */
    void connectToServer();

    /**
     * @brief getCurrentPlayer returns the client player
     * @return Player*
     */
    Player* getCurrentPlayer();

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

};

#endif // CLIENTMANAGER_H
