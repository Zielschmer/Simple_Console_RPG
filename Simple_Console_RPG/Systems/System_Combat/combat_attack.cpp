#include "combat_attack.h"

#include <iostream>

#include "..\System_Containers\Containers.h"
#include "..\System_Dice\system_dice.h"
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
	if (testComponent(targetID, CompList::ARMOR)) {
		auto it = armorContainer.find(targetID)->second();
		ac += getEquipAC(it->m_armor);
	}
	else if (testComponent(targetID, CompList::NAT_ARMOR)) {
		auto it = natArmorContainer.find(targetID)->second();
		ac += it->m_AC;
	}

	if (testComponent(targetID, CompList::OFFHAND)) {
		auto it = offHandContainer.find(targetID)->second();
		if(it->m_armor);
	}
	return ac;
}

void actionAttack(ID& attackerID, ID& targetID) {
	ID weapon;
	if (testComponent(attackerID, MAINHAND)) {
		weapon = getWeapon(attackerID, MAINHAND);
	}
	else if (testComponent(attackerID, NAT_WEAPONS)) {
		weapon = getWeapon(attackerID, NAT_WEAPONS);
	}

	if (getItemName(weapon) == "Bow") {
		if(inventory.checkArrows() < 1){
			return;
		}
		inventory.useArrow();
	}

	Roll attackRoll = getDice(attackerID, ROLL_ATK, getWeaponMod(weapon));
	AC armorClass = getAC(targetID);

	if (attackRoll > armorClass) {
		takeDamage(targetID, getDice(getEquipDmg(weapon), 1));
	}


	if (testComponent(attackerID, OFFHAND)) {
		weapon = getWeapon(attackerID, OFFHAND);
		attackRoll = getDice(D20, 1);
		if (attackRoll > armorClass) {
			takeDamage(targetID, getDice(getEquipDmg(weapon), 1));
		}
	}
}