#include <iostream>

#include "model\includes\entity.h"
#include "model\includes\inventory.h"
#include "model\includes\components-handling.h"
#include "model\includes\character-creation.h"
#include "model\includes\mercenary-creation.h"
#include "model\includes\enemy-creation.h"
#include "model\includes\equip-armor.h"
#include "model\includes\equip-weapon.h"
#include "model\includes\equip-spell.h"
#include "model\includes\equip-miracle.h"
#include "model\includes\equip-melody.h"
#include "model\includes\hire-mercenary.h"
#include "model\includes\random-encounter.h"
#include "model\includes\combat-map.h"
#include "model\includes\turn-order.h"
#include "controller\includes\choose-coordinate.h"
#include "model\includes\attack-action.h"
#include "model\includes\roll-dice.h"

Inventory inventory;

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
	Entity player = characterCreation(currentID);
	currentID++;

	std::cout << std::endl;
	std::cout << "Name: " << getInfoComponent(player.getID()).m_name << std::endl;
	std::cout << "Description: " << getInfoComponent(player.getID()).m_description << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "Strength:		" << getAbilityScoreComponent(player.getID()).m_strength << std::endl;
	std::cout << "Dexterity:		" << getAbilityScoreComponent(player.getID()).m_dexterity << std::endl;
	std::cout << "Constitution:		" << getAbilityScoreComponent(player.getID()).m_constitution << std::endl;
	std::cout << "Inteligence:		" << getAbilityScoreComponent(player.getID()).m_intelligence << std::endl;
	std::cout << "Faith:			" << getAbilityScoreComponent(player.getID()).m_faith << std::endl;
	std::cout << "Luck:			" << getAbilityScoreComponent(player.getID()).m_luck << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "Hit Points: " << getHitPointsComponent(player.getID()).m_currentHP << "/" << getHitPointsComponent(player.getID()).m_maxHP << std::endl;
	std::cout << "Spell Slots: " << getSpellSlotsComponent(player.getID()).m_currentSpellSlots << "/" << getSpellSlotsComponent(player.getID()).m_maxSpellSlots << std::endl;
}

void instantiateEnemies() {

	/*Entity monsters[3];

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
		std::cout << "Hit Points: " << getHitPointsComponent(monsters[i].getID()).m_currentHP << "/" << getHitPointsComponent(monsters[i].getID()).m_maxHP << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Armor Class: " << getNaturalArmorComponent(monsters[i].getID()).m_armorClass << std::endl;
		for (int j = 0; j < getNaturalWeaponsComponent(monsters[i].getID()).m_naturalWeapons.size(); j++) {
			std::cout << "Natural Weapon: " << getNaturalWeaponsComponent(monsters[i].getID()).m_naturalWeapons[j].m_name << std::endl;
		}
		std::cout << "\n\n";
	}*/

}

void equipTest() {
	instantiatePlayer();

	equipWeapon(*entityControl.at(0), STAFF);

	std::cout << std::endl;
	if (entityControl.at(0).get()->checkComponent(6)) {
		std::cout << "Main Hand: " << getMainHandComponent(0).m_name << std::endl;
	}
	if (entityControl.at(0).get()->checkComponent(7)) {
		std::cout << "Second Hand: " << getSecondHandComponent(0).m_name << std::endl;
	}
	if (entityControl.at(0).get()->checkComponent(8)) {
		std::cout << "Caster" << std::endl;
	}

	equipSpell(*entityControl.at(0), FLARE);
}

void drawCombatArea() {
	char column = 65;
	std::cout << "\n\n    1   2   3   4   5   6  " << std::endl;
	std::cout << "  +---+---+---+---+---+---+" << std::endl;
	for (auto axysY : combatArea) {
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

	/*instantiateMercenaries();

	system("cls");
	std::cout << "Party:\n" << std::endl;
	for(auto partyIndex : partyID)	{
		std::cout << "- " << getInfoComponent(partyIndex).m_name << std::endl;
	}

	std::vector<int> enemyParty;
	randomEncounter(partyID, enemyParty);

	std::cout << "\nEnemies:\n" << std::endl;
	for (auto partyIndex : enemyParty) {
		std::cout << "- " << getInfoComponent(partyIndex).m_name << std::endl;
	}

	combatAreaSetup(partyID, enemyParty);

	drawCombatArea();

	if (moveCharacter(partyID[0], validCoordinateInput(), getEntity(partyID[0]).getSpeed())) {
		drawCombatArea();
	}
	else {
		std::cout << "\n\nInvalid Input!" << std::endl;
	}

	std::vector<int> inRangeTargets;
	if (checkRange(partyID[0], getMainHandComponent(partyID[0]).m_range, enemyParty, inRangeTargets)) {
		std::cout << "\nTarget:\n" << std::endl;
		for (auto target : inRangeTargets) {
			std::cout << "- " << getInfoComponent(target).m_name << std::endl;
		}
	}

	std::cout << std::endl;
	makeAttack(partyID[0], enemyParty[0]);*/


}