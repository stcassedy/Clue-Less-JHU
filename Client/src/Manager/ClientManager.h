#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "BoardEnums.h"
#include "BoardElement.h"
#include "Envelope.h"
#include "Card.h"

class ClientManager
{
private:
    PlayerEnum currentPlayer;
    bool currentPlayerTurn;


public:

    /**
     * @brief ClientManager consturctor
     */
    explicit ClientManager();

    /**
     * @brief ~ClientManager() destructor
     */
    ~ClientManager();

    /**
     * @brief movePlayer
     * @param destination
     * @param location
     */
    void movePlayer(BoardElement* destination, BoardElement* location);

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

};

#endif // CLIENTMANAGER_H
