#include <iostream>

#include "model\includes\entity.h"
#include "model\includes\components-handling.h"
#include "model\includes\character-creation.h"
#include "model\includes\mercenary-creation.h"

int currentID = 0;

int main() {

	Entity mercenaries[10];

	for (int i = 0; i < 10; i++) {
		mercenaries[i] = mercenaryCreation(currentID);
		currentID++;

		std::cout << "ID: " << mercenaries[i].getID() << std::endl;
		std::cout << "Name: " << getInfoComponent(mercenaries[i].getID()).m_name << std::endl;
		std::cout << "Description: " << getInfoComponent(mercenaries[i].getID()).m_description << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Strength:		" << getAbilityScoreComponent(mercenaries[i].getID()).m_strength << std::endl;
		std::cout << "Dexterity:		" << getAbilityScoreComponent(mercenaries[i].getID()).m_dexterity << std::endl;
		std::cout << "Constitution:		" << getAbilityScoreComponent(mercenaries[i].getID()).m_constitution << std::endl;
		std::cout << "Inteligence:		" << getAbilityScoreComponent(mercenaries[i].getID()).m_intelligence << std::endl;
		std::cout << "Faith:			" << getAbilityScoreComponent(mercenaries[i].getID()).m_faith << std::endl;
		std::cout << "Luck:			" << getAbilityScoreComponent(mercenaries[i].getID()).m_luck << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Armor: " << getArmorComponent(mercenaries[i].getID()).m_name << std::endl;
		std::cout << "Main Hand: " << getMainHandComponent(mercenaries[i].getID()).m_name << std::endl;
		if (mercenaries[i].checkComponent(4)) {
			std::cout << "Second Hand: " << getSecondHandComponent(mercenaries[i].getID()).m_name << std::endl;
		}
		if (mercenaries[i].checkComponent(5)) {
			if (getCastComponent(mercenaries[i].getID()).m_spells.size() > 0) {
				for (int j = 0; j < getCastComponent(mercenaries[i].getID()).m_spells.size(); j++) {
					std::cout << "Spell: " << getCastComponent(mercenaries[i].getID()).m_spells[j].m_name << std::endl;
				}
			}
			if (getCastComponent(mercenaries[i].getID()).m_miracles.size() > 0) {
				for (int j = 0; j < getCastComponent(mercenaries[i].getID()).m_miracles.size(); j++) {
					std::cout << "Miracle: " << getCastComponent(mercenaries[i].getID()).m_miracles[j].m_name << std::endl;
				}
			}
			if (getCastComponent(mercenaries[i].getID()).m_melodies.size() > 0) {
				for (int j = 0; j < getCastComponent(mercenaries[i].getID()).m_melodies.size(); j++) {
					std::cout << "Melody: " << getCastComponent(mercenaries[i].getID()).m_melodies[j].m_name << std::endl;
				}
			}
		}
		std::cout << "\n\n";
	}


}


