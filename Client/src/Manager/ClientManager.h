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
     * @brief movePlayer moves player to new location
     * @param loc destination location
     */
    void movePlayer(BoardElement destination, BoardElement location);

    /**
     * @brief makeSuggestion
     * @param room
     * @param player
     * @param weapon
     * @param env
     * @return true if game is won and false if suggestion was wrong
     */
    bool makeSuggestion(CardEnum room, CardEnum player, CardEnum weapon, Envelope env);

    /**
     * @brief refuteSuggestion
     * @param card
     */
    void refuteSuggestion();

    /**
     * @brief makeAccusation
     * @param env
     */
    bool makeAccusation(CardEnum room, CardEnum player, CardEnum weapon, Envelope env);

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
