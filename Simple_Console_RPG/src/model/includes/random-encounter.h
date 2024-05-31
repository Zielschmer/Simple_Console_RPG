#pragma once

#include "enemy-creation.h"

enum EncounterDifficulty {

	EASY,
	MEDIUM,
	HARD,
	DEADLY

};

void randomEncounter(std::vector<int>& party, std::vector<int>& enemyParty);
