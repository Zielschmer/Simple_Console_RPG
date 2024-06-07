#include "includes\combat_initiative.h"

#include <algorithm>

#include "..\..\lib\includes\lib_entity.h"
#include "includes\system_components.h"
#include "includes\system_dice.h"

std::vector<int> turnOrder;

void getInitative(Party& partyID, Party& enemiesID) {	

	for (auto member : partyID) {
		turnOrder.emplace_back(member);
	}

	for (auto member : enemiesID) {
		turnOrder.emplace_back(member);
	}

	std::vector<int> initiativeRolls;

	for (auto member : turnOrder) {
		initiativeRolls.emplace_back(getDice(D20, 1, NORMAL, getScoreMod(member, DEX)));
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