/**
  * @file BoardEnums.h
  */
#ifndef GAMEPHASEENUMS_H
#define GAMEPHASEENUMS_H

/**
 * @brief The GamePhase enum
 */
enum GamePhaseEnum
{
    MOVE = 0,
    SUGGESTION,
    ACCUSATION,
    REFUTATION,
    START_GAME,
    GAME_LOBBY,
    WIN_GAME
};

#endif // GAMEPHASEENUMS_H
