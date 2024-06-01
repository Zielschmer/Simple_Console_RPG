#include "includes\turn-order.h"

std::vector<int> turnOrder;

void combatInitative(std::vector<int>& partyID, std::vector<int>& enemies) {	

	for (auto member : partyID) {
		turnOrder.emplace_back(member);
	}

	for (auto member : enemies) {
		turnOrder.emplace_back(member);
	}

	std::vector<int> initiativeRolls;

	for (auto combatant : turnOrder) {
		initiativeRolls.emplace_back(rollDice(20, 1, getEntity(combatant).getModifier(2)));
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