#include <iostream>

#include "..\lib\includes\lib_entity.h"
#include "model\includes\system_inventory.h"
#include "model\includes\system_components.h"
#include "model\includes\creation_playable.h"
#include "model\includes\creation_enemy.h"
#include "model\includes\equip_armor.h"
#include "model\includes\equip_weapon.h"
#include "model\includes\equip_spell.h"
#include "model\includes\equip_pray.h"
#include "model\includes\equip_song.h"
#include "model\includes\system_hiring.h"
#include "model\includes\system_encounter.h"
#include "model\includes\combat_map.h"
#include "model\includes\combat_initiative.h"
#include "control\includes\choose-coordinate.h"
#include "model\includes\combat_attack.h"
#include "model\includes\system_dice.h"

Inventory inventory;
int nextID = 1;
Party partyID;

void printInventory() {

	std::cout << "Coins: " << inventory.checkCoins() << std::endl;
	std::cout << "----------------------" << std::endl;
	if (inventory.checkPotion() > 0) {
		std::cout << "Potions: x" << inventory.checkPotion() << std::endl;
	}
	if (inventory.checkArrows() > 0) {
		std::cout << "Arrows: x" << inventory.checkArrows() << std::endl;
	}
	if (inventory.checkDarts() > 0) {
		std::cout << "Darts: x" << inventory.checkDarts() << std::endl;
	}

}

void instantiatePlayer() {
	ID player = createPlayable(nextID, PLAYER);
	
	nextID++;

	std::cout << std::endl;
	std::cout << "Name: " << getInfoComp(player)->m_name << std::endl;
	std::cout << "Description: " << getInfoComp(player)->m_desc << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "Strength:		" << getScoreComp(player)->m_str << std::endl;
	std::cout << "Dexterity:		" << getScoreComp(player)->m_dex << std::endl;
	std::cout << "Constitution:		" << getScoreComp(player)->m_con << std::endl;
	std::cout << "Inteligence:		" << getScoreComp(player)->m_int << std::endl;
	std::cout << "Faith:			" << getScoreComp(player)->m_fth << std::endl;
	std::cout << "Luck:			" << getScoreComp(player)->m_lck << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "Hit Points: " << getPointsComp(player)->m_currentHP << "/" << getPointsComp(player)->m_maxHP << std::endl;
	std::cout << "Spell Slots: " << getPointsComp(player)->m_currentSP << "/" << getPointsComp(player)->m_maxSP << std::endl;
}

void instantiateEnemies() {

	ID monsters[3];

	for (int i = 0; i < 3; i++) {
		monsters[i] = createEnemy(nextID, static_cast<EnemyList>(i));
		nextID++;

		std::cout << "ID: " << monsters[i] << std::endl;
		std::cout << "Name: " << getInfoComp(monsters[i])->m_name << std::endl;
		std::cout << "Description: " << getInfoComp(monsters[i])->m_desc << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Strength:		" << getScoreComp(monsters[i])->m_str << std::endl;
		std::cout << "Dexterity:		" << getScoreComp(monsters[i])->m_dex << std::endl;
		std::cout << "Constitution:		" << getScoreComp(monsters[i])->m_con << std::endl;
		std::cout << "Inteligence:		" << getScoreComp(monsters[i])->m_int << std::endl;
		std::cout << "Faith:			" << getScoreComp(monsters[i])->m_fth << std::endl;
		std::cout << "Luck:			" << getScoreComp(monsters[i])->m_lck << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Hit Points: " << getPointsComp(monsters[i])->m_currentHP << "/" << getPointsComp(monsters[i])->m_maxHP << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Armor Class: " << getNatArmorComp(monsters[i])->m_armorClass << std::endl;
		for (int j = 0; j < getNatWeaponComp(monsters[i])->m_weapons.size(); j++) {
			std::cout << "Natural Weapon: " << getNatWeaponComp(monsters[i])->m_weapons[j].m_name << std::endl;
		}
		std::cout << "\n\n";
	}

}

void equipTest() {

	instantiatePlayer();

	equipWeapon(*entityContainer.at(0), STAFF);

	std::cout << std::endl;
	if (entityContainer.at(0).get()->chk_comp(RHAND)) {
		std::cout << "Main Hand: " << getRHandComp(0)->m_name << std::endl;
	}
	if (entityContainer.at(0).get()->chk_comp(LHAND)) {
		std::cout << "Second Hand: " << getLHandComp(0)->m_name << std::endl;
	}
	if (entityContainer.at(0).get()->chk_comp(CAST)) {
		std::cout << "Caster" << std::endl;
	}

	equipSpell(*entityContainer.at(0), FLARE);
}

void drawCombatArea() {
	char column = 65;
	std::cout << "\n\n    1   2   3   4   5   6  " << std::endl;
	std::cout << "  +---+---+---+---+---+---+" << std::endl;
	for (auto axysY : map) {
		std::cout << column <<" |";
		for (auto axysX : axysY) {
			if (axysX == NULL) {
				std::cout << "   |";
			}
			else {
				if (axysX < 10) {
					std::cout << " " << axysX << " |";
				}
				else {
					std::cout << axysX << " |";
				}
			}
		}
		column++;
		std::cout << std::endl;
		std::cout << "  +---+---+---+---+---+---+" << std::endl;
	}
}

int main() {

	hireMercenaries();

	system("cls");
	std::cout << "Party:\n" << std::endl;
	for(auto partyIndex : partyID)	{
		std::cout << "- " << getInfoComp(partyIndex)->m_name << std::endl;
	}

	std::vector<int> enemyParty;
	createEncounter(partyID, enemyParty);

	std::cout << "\nEnemies:\n" << std::endl;
	for (auto partyIndex : enemyParty) {
		std::cout << "- " << getInfoComp(partyIndex)->m_name << std::endl;
	}

	mapSetup(partyID, enemyParty);

	drawCombatArea();

	if (moveCharacter(partyID[0], validCoordinateInput(), getSpeed(partyID[0]))) {
		drawCombatArea();
	}
	else {
		std::cout << "\n\nInvalid Input!" << std::endl;
	}

	std::vector<int> inRangeTargets;
	if (checkRange(partyID[0], getRHandComp(partyID[0])->m_range, enemyParty, inRangeTargets)) {
		std::cout << "\nTarget:\n" << std::endl;
		for (auto target : inRangeTargets) {
			std::cout << "- " << getInfoComp(target)->m_name << std::endl;
		}
	}

	std::cout << std::endl;
	actionAttack(partyID[0], enemyParty[0]);


}