#include <iostream>

#include "model\includes\entity.h"
#include "model\includes\components-handling.h"
#include "model\includes\character-creation.h"
#include "model\includes\mercenary-creation.h"
#include "model\includes\enemy-creation.h"


int currentID = 0;

int main() {

	Entity monsters[3];

	for (int i = 0; i < 3; i++) {
		monsters[i] = enemyCreation(currentID, i);
		currentID++;

		std::cout << "ID: " << monsters[i].getID() << std::endl;
		std::cout << "Name: " << getInfoComponent(monsters[i].getID()).m_name << std::endl;
		std::cout << "Description: " << getInfoComponent(monsters[i].getID()).m_description << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Strength:		" << getAbilityScoreComponent(monsters[i].getID()).m_strength << std::endl;
		std::cout << "Dexterity:		" << getAbilityScoreComponent(monsters[i].getID()).m_dexterity << std::endl;
		std::cout << "Constitution:		" << getAbilityScoreComponent(monsters[i].getID()).m_constitution << std::endl;
		std::cout << "Inteligence:		" << getAbilityScoreComponent(monsters[i].getID()).m_intelligence << std::endl;
		std::cout << "Faith:			" << getAbilityScoreComponent(monsters[i].getID()).m_faith << std::endl;
		std::cout << "Luck:			" << getAbilityScoreComponent(monsters[i].getID()).m_luck << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Armor Class: " << getNaturalArmorComponent(monsters[i].getID()).m_armorClass << std::endl;
		for (int j = 0; j < getNaturalWeaponsComponent(monsters[i].getID()).m_naturalWeapons.size(); j++) {
			std::cout << "Natural Weapon: " << getNaturalWeaponsComponent(monsters[i].getID()).m_naturalWeapons[j].m_name << std::endl;
		}
		std::cout << "\n\n";
	}


}


