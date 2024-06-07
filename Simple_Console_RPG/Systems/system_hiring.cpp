#include "includes\system_hiring.h"

#include "..\..\lib\includes\lib_entity.h"
#include "..\control\includes\choose-option.h"
#include "..\control\includes\choose-bool.h"
#include "includes\system_components.h"

extern ID nextID;

void hireMercenaries() {

	Party mercForHire;
	int mercenaryIndex = 0;

	for (int i = 0; i < 10; i++) {
		mercForHire.push_back(createPlayable(nextID, MERC));
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
		for (auto member : mercForHire) {
			std::cout << "[" << static_cast<char>(charIndex) << "]" << getInfoComp(member)->m_name;
			std::cout << "[" << getArmorComp(member)->m_name << "]";
			std::cout << "[" << getRHandComp(member)->m_name << "]";
			if (getEntity(member)->chk_comp(LHAND)) {
				std::cout << "[" << getLHandComp(member)->m_name << "]";
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
		std::cout << "Name: " << getInfoComp(mercForHire[options])->m_name << std::endl;
		std::cout << "Description: " << getInfoComp(mercForHire[options])->m_desc << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Strength:		" << getScoreComp(mercForHire[options])->m_str << std::endl;
		std::cout << "Dexterity:		" << getScoreComp(mercForHire[options])->m_dex << std::endl;
		std::cout << "Constitution:		" << getScoreComp(mercForHire[options])->m_con << std::endl;
		std::cout << "Inteligence:		" << getScoreComp(mercForHire[options])->m_int << std::endl;
		std::cout << "Faith:			" << getScoreComp(mercForHire[options])->m_fth << std::endl;
		std::cout << "Luck:			" << getScoreComp(mercForHire[options])->m_lck << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Hit Points: " << getPointsComp(mercForHire[options])->m_currentHP << "/" << getPointsComp(mercForHire[options])->m_maxHP << std::endl;
		std::cout << "Spell Slots: " << getPointsComp(mercForHire[options])->m_currentSP << "/" << getPointsComp(mercForHire[options])->m_maxSP << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Armor: " << getArmorComp(mercForHire[options])->m_name << std::endl;
		std::cout << "Main Hand: " << getRHandComp(mercForHire[options])->m_name << std::endl;
		if (getEntity(mercForHire[options])->chk_comp(LHAND)) {
			std::cout << "Second Hand: " << getLHandComp(mercForHire[options])->m_name << std::endl;
		}
		if (getEntity(mercForHire[options])->chk_comp(CAST)) {
			if (getCastComp(mercForHire[options])->m_spells.size() > 0) {
				for (int j = 0; j < getCastComp(mercForHire[options])->m_spells.size(); j++) {
					std::cout << "Spell: " << getCastComp(mercForHire[options])->m_spells[j].m_name << std::endl;
				}
			}
			if (getCastComp(mercForHire[options])->m_prays.size() > 0) {
				for (int j = 0; j < getCastComp(mercForHire[options])->m_prays.size(); j++) {
					std::cout << "Prays: " << getCastComp(mercForHire[options])->m_prays[j].m_name << std::endl;
				}
			}
			if (getCastComp(mercForHire[options])->m_songs.size() > 0) {
				for (int j = 0; j < getCastComp(mercForHire[options])->m_songs.size(); j++) {
					std::cout << "Songs: " << getCastComp(mercForHire[options])->m_songs[j].m_name << std::endl;
				}
			}
		}

		std::cout << "\nHire? [Y/N]: ";
		if (validBoolInput()) {
			partyID.push_back(mercForHire[options]);
			mercForHire.erase(mercForHire.begin()+options);
			validOptions.erase(validOptions.end() - 3);
		}

	}
}

