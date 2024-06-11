#ifndef SYSTEM_DICE
#define SYSTEM_DICE

#include "..\..\utils.h"

Roll rollDice(DiceList dice);

Roll rollDice(DiceList dice, Mod mod);

Roll getDice(DiceList dice, uint16_t num);

Roll getDice(DiceList dice, uint16_t num, ID& entityID, ScoreList score);

Roll getDice(ID& entityID, RollType type, ScoreList score);

#endif