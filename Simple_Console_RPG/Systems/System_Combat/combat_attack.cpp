#include "combat_attack.h"

#include <iostream>

#include "..\System_Containers\Containers.h"
#include "..\System_Dice\system_dice.h"
#include "..\System_Inventory\system_inventory.h"
#include "..\..\..\Item_Library\Item_Interface.h"

bool isDead(ID& entityID, HP damage) {

	takeDamage(entityID, damage);

	if (chkHP(entityID) < 1){
		std::cout << getName(entityID) << " is dead" << std::endl;
		return true;
	}
	std::cout << getName(entityID) << " HP: " << chkHP(entityID) << "|" << chkMaxHP(entityID) << std::endl;
	return false;

}

AC getAC(ID targetID) {
	AC ac = 0;
	if (testComponent(targetID, CompList::ARMOR_COMP)) {
		auto it = armorContainer.find(targetID)->second.get();
		ac += getEquipAC(it->m_armor);
	}
	else if (testComponent(targetID, CompList::NAT_ARMOR_COMP)) {
		auto it = natArmorContainer.find(targetID)->second.get();
		ac += it->m_AC;
	}

	if (testComponent(targetID, CompList::OFFHAND_COMP)) {
		auto it = offHandContainer.find(targetID)->second.get();
		ac += it->m_AC;
	}
	return ac;
}

void actionAttack(ID& attackerID, ID& targetID) {
	ID weapon;
	if (testComponent(attackerID, MAINHAND_COMP)) {
		weapon = getWeapon(attackerID, MAINHAND_COMP);
	}
	else if (testComponent(attackerID, NAT_WEAPONS_COMP)) {
		weapon = getWeapon(attackerID, NAT_WEAPONS_COMP);
	}

	if (getItemName(weapon) == "Bow") {
		if (checkItem(attackerID, "Arrow") < 1) {
			return;
		}
		useItem(attackerID, "Arrow");
	}

	Roll attackRoll = getDice(attackerID, ROLL_ATK, getWeaponMod(weapon));
	AC armorClass = getAC(targetID);

	if (attackRoll > armorClass) {
		takeDamage(targetID, getDice(getEquipDmg(weapon), 1));
	}


	if (testComponent(attackerID, OFFHAND_COMP)) {
		weapon = getWeapon(attackerID, OFFHAND_COMP);
		attackRoll = getDice(D20, 1);
		if (attackRoll > armorClass) {
			takeDamage(targetID, getDice(getEquipDmg(weapon), 1));
		}
	}
}