#include "includes\hire-mercenary.h"

std::vector<int> partyID;

void instantiateMercenaries() {

	std::vector<int> mercenariesID;
	int mercenaryIndex = 0;

	for (int i = 0; i < 10; i++) {
		mercenariesID.push_back(currentID);
		(mercenaryCreation(currentID));
		currentID++;
	}

	{
		validOptions.push_back('a');
		validOptions.push_back('b');
		validOptions.push_back('c');
		validOptions.push_back('d');
		validOptions.push_back('e');
		validOptions.push_back('f');
		validOptions.push_back('g');
		validOptions.push_back('h');
		validOptions.push_back('i');
		validOptions.push_back('j');
		validOptions.push_back('r');
		validOptions.push_back('x');
	}

	while (true) {

		system("cls");
		int charIndex = 65;
		for (auto index : mercenariesID) {
			std::cout << "[" << static_cast<char>(charIndex) << "]" << getInfoComponent(index).m_name;
			std::cout << "[" << getArmorComponent(index).m_name << "]";
			std::cout << "[" << getMainHandComponent(index).m_name << "]";
			if (getEntity(index).checkComponent(7)) {
				std::cout << "[" << getSecondHandComponent(index).m_name << "]";
			}
			std::cout << std::endl;
			charIndex++;
		}
		std::cout << "\nChoose a mercenary: ";

		OptionInput options = validOptionInput();

		switch (options)
		{
		case OPTION_A:
			break;
		case OPTION_B:
			break;
		case OPTION_C:
			break;
		case OPTION_D:
			break;
		case OPTION_E:
			break;
		case OPTION_F:
			break;
		case OPTION_G:
			break;
		case OPTION_H:
			break;
		case OPTION_I:
			break;
		case OPTION_J:
			break;
		case RETURN:
			return;
			break;
		case EXIT:
			return;
			break;
		default:
			break;
		}

		system("cls");
		std::cout << "Name: " << getInfoComponent(mercenariesID[options]).m_name << std::endl;
		std::cout << "Description: " << getInfoComponent(mercenariesID[options]).m_description << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Strength:		" << getAbilityScoreComponent(mercenariesID[options]).m_strength << std::endl;
		std::cout << "Dexterity:		" << getAbilityScoreComponent(mercenariesID[options]).m_dexterity << std::endl;
		std::cout << "Constitution:		" << getAbilityScoreComponent(mercenariesID[options]).m_constitution << std::endl;
		std::cout << "Inteligence:		" << getAbilityScoreComponent(mercenariesID[options]).m_intelligence << std::endl;
		std::cout << "Faith:			" << getAbilityScoreComponent(mercenariesID[options]).m_faith << std::endl;
		std::cout << "Luck:			" << getAbilityScoreComponent(mercenariesID[options]).m_luck << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Hit Points: " << getHitPointsComponent(mercenariesID[options]).m_currentHP << "/" << getHitPointsComponent(mercenariesID[options]).m_maxHP << std::endl;
		std::cout << "Spell Slots: " << getSpellSlotsComponent(mercenariesID[options]).m_currentSpellSlots << "/" << getSpellSlotsComponent(mercenariesID[options]).m_maxSpellSlots << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Armor: " << getArmorComponent(mercenariesID[options]).m_name << std::endl;
		std::cout << "Main Hand: " << getMainHandComponent(mercenariesID[options]).m_name << std::endl;
		if (getEntity(mercenariesID[options]).checkComponent(7)) {
			std::cout << "Second Hand: " << getSecondHandComponent(mercenariesID[options]).m_name << std::endl;
		}
		if (getEntity(mercenariesID[options]).checkComponent(8)) {
			if (getCastComponent(mercenariesID[options]).m_spells.size() > 0) {
				for (int j = 0; j < getCastComponent(mercenariesID[options]).m_spells.size(); j++) {
					std::cout << "Spell: " << getCastComponent(mercenariesID[options]).m_spells[j].m_name << std::endl;
				}
			}
			if (getCastComponent(mercenariesID[options]).m_miracles.size() > 0) {
				for (int j = 0; j < getCastComponent(mercenariesID[options]).m_miracles.size(); j++) {
					std::cout << "Miracle: " << getCastComponent(mercenariesID[options]).m_miracles[j].m_name << std::endl;
				}
			}
			if (getCastComponent(mercenariesID[options]).m_melodies.size() > 0) {
				for (int j = 0; j < getCastComponent(mercenariesID[options]).m_melodies.size(); j++) {
					std::cout << "Melody: " << getCastComponent(mercenariesID[options]).m_melodies[j].m_name << std::endl;
				}
			}
		}

		std::cout << "\nHire? [Y/N]: ";
		if (validBoolInput()) {
			partyID.push_back(mercenariesID[options]);
			mercenariesID.erase(mercenariesID.begin()+options);
			validOptions.erase(validOptions.end() - 3);
		}

	}
}

