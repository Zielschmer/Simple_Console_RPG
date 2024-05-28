#include <cstdlib>
#include <time.h>

#include "includes\roll-dice.h"

int rollDice(int dice, int numDice) {

	int resultDice = 0;

	for (int i = 0; i < numDice; i++) {
		srand(time(NULL));
		resultDice =+ (rand() % dice + 1);
	}

	return resultDice;

}