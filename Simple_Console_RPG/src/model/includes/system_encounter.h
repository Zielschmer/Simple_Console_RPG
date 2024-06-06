#pragma once

#include "creation_enemy.h"

enum EncounterDifficulty {

	EASY,
	MEDIUM,
	HARD,
	DEADLY

};

void createEncounter(Party& partyID, Party& enemyID);
