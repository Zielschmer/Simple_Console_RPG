#include "includes\attack-action.h"

bool isDead(int& creatureID, int& damage) {

	getHitPointsComponent(creatureID).m_currentHP -= damage;

	if (getHitPointsComponent(creatureID).m_currentHP < 1){
		std::cout << getInfoComponent(creatureID).m_name << " is dead" << std::endl;
		return true;
	}
	std::cout << getInfoComponent(creatureID).m_name << " HP: " << getHitPointsComponent(creatureID).m_currentHP << "|" << getHitPointsComponent(creatureID).m_maxHP << std::endl;
	return false;

}

void calculateArmoClass(int& targetID, int& armorClass) {

	if (getEntity(targetID).checkComponent(5)) {

		armorClass = getArmorComponent(targetID).m_baseArmor + getEntity(targetID).getModifier(getArmorComponent(targetID).m_armorModifier);
	
	}
	else if (getEntity(targetID).checkComponent(9)) {

		armorClass = getNaturalArmorComponent(targetID).m_armorClass;
		
	}

	if (getEntity(targetID).checkComponent(7)) {
		armorClass += getSecondHandComponent(targetID).m_baseArmor;
	}

}

void makeAttack(int& attackerID, int& targetID) {

	int damage = 0;
	int attackRoll = 0;
	int armorClass = 0;
	
	calculateArmoClass(targetID, armorClass);

	//Main Hand attack
	if(getEntity(attackerID).checkComponent(6)) {
		if (getMainHandComponent(attackerID).m_name == "Bow") {
			if (!inventory.useArrow()) {
				std::cout << getInfoComponent(attackerID).m_name << " doesn't have more arrows" << std::endl;
				return;
			}
			else {
				std::cout << getInfoComponent(attackerID).m_name << " used one arrow" << std::endl;
			}
		}

		std::cout << getInfoComponent(attackerID).m_name << " attacks " << getInfoComponent(targetID).m_name << std::endl;

		attackRoll = rollDice(20, 1, NORMAL, getEntity(attackerID).getModifier(getMainHandComponent(attackerID).m_attackModifier));

		std::cout << getInfoComponent(attackerID).m_name << " rolled " << attackRoll << std::endl;

		if(attackRoll > armorClass) {
			damage = rollDice(getMainHandComponent(attackerID).m_baseAttack, 1, NORMAL);
			std::cout << getInfoComponent(targetID).m_name << " took " << damage << " damage" << std::endl;
			if (isDead(targetID, damage)) {
				return;
			}
		}
		else {
			std::cout << "Attack missed" << std::endl;
		}

	}

	//Second Hand attack
	if (getEntity(attackerID).checkComponent(7)) {

		if (getSecondHandComponent(attackerID).m_name == "Shield") {
			return;
		}

		std::cout << getInfoComponent(attackerID).m_name << " attacks " << getInfoComponent(targetID).m_name << std::endl;

		if (getEntity(attackerID).checkComponent(6)) {
			attackRoll = rollDice(20, 1, DISADVANTAGE, getSecondHandComponent(attackerID).m_attackModifier);
		}
		else {
			attackRoll = rollDice(20, 1, NORMAL, getSecondHandComponent(attackerID).m_attackModifier);
		}

		std::cout << getInfoComponent(attackerID).m_name << " rolled " << attackRoll << std::endl;

		if (attackRoll > armorClass) {
			damage = rollDice(getMainHandComponent(attackerID).m_baseAttack, 1, NORMAL);
			std::cout << getInfoComponent(targetID).m_name << " took " << damage << " damage" << std::endl;
			if (isDead(targetID, damage)) {
				return;
			}
		}
		else {
			std::cout << "Attack missed" << std::endl;
		}

	}
	//Natural Weapon Attack
	else if (getEntity(attackerID).checkComponent(9)) {

		std::cout << getInfoComponent(attackerID).m_name << " attacks " << getInfoComponent(targetID).m_name << std::endl;

		attackRoll = rollDice(20, 1, NORMAL);

		std::cout << getInfoComponent(attackerID).m_name << " rolled " << attackRoll << std::endl;

		damage = 1;

		if (attackRoll > armorClass) {
			std::cout << getInfoComponent(targetID).m_name << " took " << damage << " damage" << std::endl;
			if (isDead(targetID, damage)) {
				return;
			}
		}
		else {
			std::cout << "Attack missed" << std::endl;
		}
	}

}