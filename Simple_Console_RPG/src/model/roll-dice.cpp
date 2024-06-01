#include "includes\roll-dice.h"

int rollDice(int dice, int numDice, TypeRoll typeRoll) {

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

int rollDice(int dice, int numDice, TypeRoll typeRoll, int modifier) {

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
			return resultDice2 + modifier;
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
			return resultDice2 + modifier;
		}
		break;
	}
	}

	return resultDice+modifier;

}