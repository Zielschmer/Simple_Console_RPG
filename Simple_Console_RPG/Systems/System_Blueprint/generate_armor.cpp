#include "generate_components.h"
#include "..\System_Containers\Containers.h"

#include "..\..\..\Item_Library\Item_Interface.h"

Armor_ptr generateArmor(ID entityID, Blueprint blueprint) {
	Armor_ptr newArmor(new CompArmor(entityID));

	if (chkScore(entityID, INT) > 13 &&
		chkScore(entityID, DEX) < 15 &&
		chkScore(entityID, INT) > chkScore(entityID, FTH) &&
		chkScore(entityID, INT) > chkScore(entityID, LCK)) {

		newArmor->m_armor = createRobe(entityID);
		blueprint.addComponent(CAST);
	}
	else if (chkScore(entityID, FTH) > 13 &&
		chkScore(entityID, FTH) > chkScore(entityID, LCK)) {

		if (chkScore(entityID, STR) < 14) {
			newArmor->m_armor = createRobe(entityID);
		}
		else {
			newArmor->m_armor = createChainMail(entityID);
		}
		blueprint.addComponent(CAST);
	}
	else if (chkScore(entityID, LCK) > 13 &&
		chkScore(entityID, STR) < 14 &&
		chkScore(entityID, DEX) < 14) {

		newArmor->m_armor = createRobe(entityID);
		blueprint.addComponent(CAST);
	}
	else if (chkScore(entityID, DEX) > 13 &&
		chkScore(entityID, DEX) > chkScore(entityID, STR)) {

		newArmor->m_armor = createLeatherArmor(entityID);

	}
	else if (chkScore(entityID, DEX) < 10) {

		newArmor->m_armor = createChainMail(entityID);

	}
	else {
		newArmor->m_armor = createRingMail(entityID);
	}

	return std::move(newArmor);
}