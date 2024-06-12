#include "combat_initiative.h"

#include <algorithm>

#include "..\System_Containers\Containers.h"
#include "..\System_Dice\system_dice.h"

std::vector<ID> turnOrder;

void getInitative(Party& partyID, Party& enemiesID) {	

	for (auto member : partyID) {
		turnOrder.emplace_back(member);
	}

	for (auto member : enemiesID) {
		turnOrder.emplace_back(member);
	}

	std::vector<Roll> initiativeRolls;

	for (auto member : turnOrder) {
		initiativeRolls.emplace_back(rollDice(D20, getMod(member, DEX)));
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < initiativeRolls.size()-1; j++) {
			for (int k = j + 1; k < initiativeRolls.size(); k++) {
				if (initiativeRolls[j] < initiativeRolls[k]) {
					std::swap(initiativeRolls[j], initiativeRolls[k]);
					std::swap(turnOrder[j], turnOrder[k]);
				}

			}
		}
	}

}