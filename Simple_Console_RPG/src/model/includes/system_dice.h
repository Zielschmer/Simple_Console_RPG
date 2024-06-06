#pragma once

#include <cstdlib>
#include <time.h>

enum Dice {

	D0 = 0,
	D4 = 4,
	D6 = 6,
	D8 = 8,
	D10 = 10,
	D12 = 12,
	D20 = 20,
	D100 = 100

};

enum TypeRoll {

	DISADVANTAGE,
	NORMAL,
	ADVANTAGE

};

int getDice(Dice dice, int numDice, TypeRoll typeRoll);

int getDice(Dice dice, int numDice, TypeRoll typeRoll, int mod);