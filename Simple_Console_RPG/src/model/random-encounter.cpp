#include "includes\random-encounter.h"

void randomEncounter(std::vector<int>& party, std::vector<int>& enemyParty) {

	int enemyNumber = std::floor((party.size() * 50) / 10);

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
		enemyParty.emplace_back(enemyCreation(currentID, rand() % 3));
		currentID++;
	}

}