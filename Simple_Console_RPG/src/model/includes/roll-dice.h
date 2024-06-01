#pragma once

#include <cstdlib>
#include <time.h>

enum TypeRoll {

	DISADVANTAGE,
	NORMAL,
	ADVANTAGE

};

int rollDice(int dice, int numDice, TypeRoll typeRoll);

int rollDice(int dice, int numDice, TypeRoll typeRoll, int modifier);