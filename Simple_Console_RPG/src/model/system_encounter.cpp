#include "includes\system_encounter.h"

extern ID nextID;

void createEncounter(Party& partyID, Party& enemyID) {

	int enemyNumber = std::floor((partyID.size() * 50) / 10);

	if (enemyNumber > 2 && enemyNumber < 7) {
		enemyNumber = std::ceil(enemyNumber / 2);
	}
	else if (enemyNumber > 6 && enemyNumber < 11) {
		enemyNumber = std::ceil(enemyNumber / 2.5);
	}
	else if (enemyNumber > 10 && enemyNumber < 16) {
		enemyNumber = std::ceil(enemyNumber / 3);
	}
	else if (enemyNumber > 15) {
		enemyNumber = std::ceil(enemyNumber / 4);
	}

	srand(time(NULL) * rand() % 100);
	for (int i = 0; i < enemyNumber; i++) {
		enemyID.emplace_back(createEnemy(nextID, static_cast<EnemyList>(rand() % 3)));
	}

}