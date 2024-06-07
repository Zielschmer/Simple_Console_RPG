#include "includes\system_dice.h"

#include "includes\system_components.h"

int getDice(Dice dice, int numDice, TypeRoll typeRoll) {

	if (dice == 0) {
		return 1;
	}

	int resultDice = 0;
	int resultDice2 = 0;

	srand(time(NULL) + rand() % 100);

	switch (typeRoll)
	{
	case DISADVANTAGE:
	{
		for (int i = 0; i < numDice; i++) {
			resultDice += (rand() % dice + 1);
		}

		srand(time(NULL) + rand() % 100);

		for (int i = 0; i < numDice; i++) {
			resultDice2 += (rand() % dice + 1);
		}
		if (resultDice2 < resultDice) {
			return resultDice2;
		}
		break;
	}
	case NORMAL:
	{
		for (int i = 0; i < numDice; i++) {
			resultDice += (rand() % dice + 1);
		}
		break;
	}
	case ADVANTAGE:
	{
		for (int i = 0; i < numDice; i++) {
			resultDice += (rand() % dice + 1);
		}

		srand(time(NULL) + rand() % 100);

		for (int i = 0; i < numDice; i++) {
			resultDice2 += (rand() % dice + 1);
		}
		if (resultDice2 > resultDice) {
			return resultDice2;
		}
		break;
	}
	}

	return resultDice;

}

int getDice(Dice dice, int numDice, TypeRoll typeRoll, int mod) {

	if (dice == 0) {
		return 1;
	}

	int resultDice = 0;
	int resultDice2 = 0;

	srand(time(NULL) + rand() % 100);

	switch (typeRoll)
	{
	case DISADVANTAGE:
	{
		for (int i = 0; i < numDice; i++) {
			resultDice += (rand() % dice + 1);
		}

		srand(time(NULL) + rand() % 100);

		for (int i = 0; i < numDice; i++) {
			resultDice2 += (rand() % dice + 1);
		}
		if (resultDice2 < resultDice) {
			return resultDice2 + mod;
		}
		break;
	}
	case NORMAL:
	{
		for (int i = 0; i < numDice; i++) {
			resultDice += (rand() % dice + 1);
		}
		break;
	}
	case ADVANTAGE:
	{
		for (int i = 0; i < numDice; i++) {
			resultDice += (rand() % dice + 1);
		}
		srand(time(NULL) + rand() % 100);

		for (int i = 0; i < numDice; i++) {
			resultDice2 += (rand() % dice + 1);
		}
		if (resultDice2 > resultDice) {
			return resultDice2 + mod;
		}
		break;
	}
	}

	return (resultDice+mod);

}

Roll scoreCheck(ID& entity, ScoreList score) {
	return rand() % 20 + getMod(entity, score);
}

Roll attackRoll(ID& attacker, ID& target) {
	return rand() % 20 + getMod(attacker, STR);
}

Roll damageRoll(ID& attacker, ID& target) {

}

Roll savingThrow(ID& entity) {

}