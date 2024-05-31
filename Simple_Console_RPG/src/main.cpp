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
#include "model\includes\roll-dice.h"

int currentID = 0;
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

void instantiateMercenaries(int numMercenaries) {

	std::vector<Entity> mercenaries;

	for (int i = 0; i < numMercenaries; i++) {
		mercenaries.push_back(mercenaryCreation(currentID));
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
		std::cout << "Hit Points: " << getHitPointsComponent(mercenaries[i].getID()).m_currentHP << "/" << getHitPointsComponent(mercenaries[i].getID()).m_maxHP << std::endl;
		std::cout << "Spell Slots: " << getSpellSlotsComponent(mercenaries[i].getID()).m_currentSpellSlots << "/" << getSpellSlotsComponent(mercenaries[i].getID()).m_maxSpellSlots << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Armor: " << getArmorComponent(mercenaries[i].getID()).m_name << std::endl;
		std::cout << "Main Hand: " << getMainHandComponent(mercenaries[i].getID()).m_name << std::endl;
		if (mercenaries[i].checkComponent(7)) {
			std::cout << "Second Hand: " << getSecondHandComponent(mercenaries[i].getID()).m_name << std::endl;
		}
		if (mercenaries[i].checkComponent(8)) {
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

void instantiateEnemies() {

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
		std::cout << "Hit Points: " << getHitPointsComponent(monsters[i].getID()).m_currentHP << "/" << getHitPointsComponent(monsters[i].getID()).m_maxHP << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Armor Class: " << getNaturalArmorComponent(monsters[i].getID()).m_armorClass << std::endl;
		for (int j = 0; j < getNaturalWeaponsComponent(monsters[i].getID()).m_naturalWeapons.size(); j++) {
			std::cout << "Natural Weapon: " << getNaturalWeaponsComponent(monsters[i].getID()).m_naturalWeapons[j].m_name << std::endl;
		}
		std::cout << "\n\n";
	}

}

int main() {

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

	if (getCastComponent(entityControl.at(0)->getID()).m_spells.size() > 0) {
		for (auto spell : getCastComponent(entityControl.at(0)->getID()).m_spells) {
			std::cout << "Spell: " << spell.m_name << std::endl;
		}
	}

	equipWeapon(*entityControl.at(0), ROSARY);

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

	equipMiracle(*entityControl.at(0), HEAL);

	if (getCastComponent(entityControl.at(0)->getID()).m_miracles.size() > 0) {
		for (auto miracle : getCastComponent(entityControl.at(0)->getID()).m_miracles) {
			std::cout << "Miracle: " << miracle.m_name << std::endl;
		}
	}

	equipWeapon(*entityControl.at(0), HARP);

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

	equipMelody(*entityControl.at(0), DANCE);

	if (getCastComponent(entityControl.at(0)->getID()).m_melodies.size() > 0) {
		for (auto melody : getCastComponent(entityControl.at(0)->getID()).m_melodies) {
			std::cout << "Melody: " << melody.m_name << std::endl;
		}
	}
	
}