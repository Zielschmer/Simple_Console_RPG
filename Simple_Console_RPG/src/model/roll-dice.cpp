#include <cstdlib>
#include <time.h>

#include "includes\roll-dice.h"

int rollDice(int dice, int numDice) {

	int resultDice = 0;

	srand(time(NULL) + rand() % 100);

	for (int i = 0; i < numDice; i++) {
		resultDice += (rand() % dice + 1);
	}

	return resultDice;

}

int rollDice(int dice, int numDice, int modifier) {

	int resultDice = 0;

	srand(time(NULL) + rand() % 100);

	for (int i = 0; i < numDice; i++) {
		resultDice += (rand() % dice + 1);
	}

	return resultDice+modifier;

}