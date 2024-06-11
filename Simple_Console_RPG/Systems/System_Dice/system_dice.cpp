#include "system_dice.h"

#include "..\..\utils.h"
#include "..\System_Containers\Containers.h"

Roll rollDice(DiceList dice) {
	srand(time(NULL) + rand() % 100);
	return (rand() & dice) + 1;
}

Roll rollDice(DiceList dice, Mod mod) {
	srand(time(NULL) + rand() % 100);
	return ((rand() & dice) + 1)+mod;
}

Roll getDice(DiceList dice, uint16_t num) {
	Roll roll = 0;
	for(int i = 0; i < num; i++) {
		roll += rollDice(dice);
	}
	return roll;
}

Roll getDice(DiceList dice, uint16_t num, ID& entityID, ScoreList score) {
	Roll roll = 0;
	for (int i = 0; i < num; i++) {
		roll += rollDice(dice, getMod(entityID, score));
	}
	return roll;
}

Roll getDice(ID& entityID, RollType type, ScoreList score) {
	RollAdv adv = getRollAdv(entityID, type, score);
	Mod mod = getMod(entityID, score);
	Roll roll = rollDice(D20, mod);
	switch (adv)
	{
	case DISROLL:
		Roll roll2 = rollDice(D20, mod);
		if (roll > roll2) {
			return roll2;
		}
		return roll;
		break;
	case NMLROLL:
		return roll;
		break;
	case ADVROLL:
		Roll roll2 = rollDice(D20, mod);
		if (roll > roll2) {
			return roll;
		}
		return roll2;
		break;
	}
}