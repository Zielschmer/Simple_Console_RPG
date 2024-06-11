#include "includes\combat_attack.h"

#include <iostream>

#include "includes\system_components.h"
#include "includes\system_dice.h"

bool isDead(ID& entityID, ID& damage) {

	getPointsComp(entityID)->m_currentHP -= damage;

	if (getPointsComp(entityID)->m_currentHP < 1){
		std::cout << getInfoComp(entityID)->m_name << " is dead" << std::endl;
		return true;
	}
	std::cout << getInfoComp(entityID)->m_name << " HP: " << getPointsComp(entityID)->m_currentHP << "|" << getPointsComp(entityID)->m_maxHP << std::endl;
	return false;

}

void getArmoClass(int& targetID, int& armorClass) {

	if (getEntity(targetID)->chk_comp(ARMOR)) {

		armorClass = getArmorComp(targetID)->m_baseArmor + getScoreMod(targetID, getArmorComp(targetID)->m_armorMod);
	
	}
	else if (getEntity(targetID)->chk_comp(NAT_ARMOR)) {

		armorClass = getNatArmorComp(targetID)->m_armorClass;
		
	}

	if (getEntity(targetID)->chk_comp(LHAND)) {
		armorClass += getLHandComp(targetID)->m_armorClass;
	}

}

void actionAttack(ID& attackerID, ID& targetID) {

	int damage = 0;
	int attackRoll = 0;
	int armorClass = 0;
	
	getArmoClass(targetID, armorClass);

	//Main Hand attack
	if(getEntity(attackerID)->chk_comp(RHAND)) {
		if (getRHandComp(attackerID)->m_name == "Bow") {
			if (!inventory.useArrow()) {
				std::cout << getInfoComp(attackerID)->m_name << " doesn't have more arrows" << std::endl;
				return;
			}
			else {
				std::cout << getInfoComp(attackerID)->m_name << " used one arrow" << std::endl;
			}
		}

		std::cout << getInfoComp(attackerID)->m_name << " attacks " << getInfoComp(targetID)->m_name << std::endl;

		attackRoll = getDice(D20, 1, NORMAL, getScoreMod(attackerID, getRHandComp(attackerID)->m_atkMod));

		std::cout << getInfoComp(attackerID)->m_name << " rolled " << attackRoll << std::endl;

		if(attackRoll > armorClass) {
			damage = getDice(getRHandComp(attackerID)->m_diceAtk, 1, NORMAL);
			std::cout << getInfoComp(targetID)->m_name << " took " << damage << " damage" << std::endl;
			if (isDead(targetID, damage)) {
				return;
			}
		}
		else {
			std::cout << "Attack missed" << std::endl;
		}

	}

	//Second Hand attack
	if (getEntity(attackerID)->chk_comp(LHAND)) {

		if (getLHandComp(attackerID)->m_name == "Shield") {
			return;
		}

		std::cout << getInfoComp(attackerID)->m_name << " attacks " << getInfoComp(targetID)->m_name << std::endl;

		if (getEntity(attackerID)->chk_comp(RHAND)) {
			attackRoll = getDice(D20, 1, DISADVANTAGE, getLHandComp(attackerID)->m_atkMod);
		}
		else {
			attackRoll = getDice(D20, 1, NORMAL, getLHandComp(attackerID)->m_atkMod);
		}

		std::cout << getInfoComp(attackerID)->m_name << " rolled " << attackRoll << std::endl;

		if (attackRoll > armorClass) {
			damage = getDice(getRHandComp(attackerID)->m_diceAtk, 1, NORMAL);
			std::cout << getInfoComp(targetID)->m_name << " took " << damage << " damage" << std::endl;
			if (isDead(targetID, damage)) {
				return;
			}
		}
		else {
			std::cout << "Attack missed" << std::endl;
		}

	}
	//Natural Weapon Attack
	else if (getEntity(attackerID)->chk_comp(NAT_ARMOR)) {

		std::cout << getInfoComp(attackerID)->m_name << " attacks " << getInfoComp(targetID)->m_name << std::endl;

		attackRoll = getDice(D20, 1, NORMAL);

		std::cout << getInfoComp(attackerID)->m_name << " rolled " << attackRoll << std::endl;

		damage = 1;

		if (attackRoll > armorClass) {
			std::cout << getInfoComp(targetID)->m_name << " took " << damage << " damage" << std::endl;
			if (isDead(targetID, damage)) {
				return;
			}
		}
		else {
			std::cout << "Attack missed" << std::endl;
		}
	}

}