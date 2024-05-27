#include <iostream>

#include "model\includes\entity.h"
#include "..\lib\includes\spell.h"
#include "..\lib\includes\miracle.h"
#include "..\lib\includes\melody.h"
#include "model\includes\character-creation.h"

int main() {

	Entity guts = characterCreation();

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