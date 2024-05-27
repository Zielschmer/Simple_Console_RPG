#include <iostream>

#include "model\includes\entity.h"
#include "model\includes\components-handling.h"
#include "model\includes\character-creation.h"

int currentID = 0;

int main() {

	Entity guts = characterCreation(currentID);

	std::cout << "Name: " << getInfoComponent(guts.getID()).m_name << std::endl;
	std::cout << "Description: " << getInfoComponent(guts.getID()).m_description << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "Strength:		" << getAbilityScoreComponent(guts.getID()).m_strength << std::endl;
	std::cout << "Dexterity:		" << getAbilityScoreComponent(guts.getID()).m_dexterity << std::endl;
	std::cout << "Constitution:		" << getAbilityScoreComponent(guts.getID()).m_constitution << std::endl;
	std::cout << "Inteligence:		" << getAbilityScoreComponent(guts.getID()).m_intelligence << std::endl;
	std::cout << "Faith:			" << getAbilityScoreComponent(guts.getID()).m_faith << std::endl;
	std::cout << "Luck:			" << getAbilityScoreComponent(guts.getID()).m_luck << std::endl;

}