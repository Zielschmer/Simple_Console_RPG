#include "generate_components.h"
#include "..\System_Containers\Containers.h"

#include "..\..\..\Item_Library\Item_Interface.h"

OffHand_ptr generateOffHand(ID entityID) {
	OffHand_ptr newOffHand(new CompOffHand(entityID));

	if (getItemName(getComponent<CompArmor>(entityID, ARMOR)->m_armor) == "Robe") {
		if (chkScore(entityID, INT) > chkScore(entityID, FTH)) {
			newOffHand->m_weapon = createStaff(entityID);
		}
		else {
			newOffHand->m_weapon = createRosary(entityID);
		}
	}
	else if (getItemName(getComponent<CompMainHand>(entityID, MAINHAND)->m_weapon) == "Mace") {
		newOffHand->m_weapon = createRosary(entityID);
	}
	else {
		newOffHand->m_weapon = createShield(entityID);
	}

	return std::move(newOffHand);
}