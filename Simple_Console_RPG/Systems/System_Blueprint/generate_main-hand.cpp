#include "generate_components.h"
#include "..\System_Containers\Containers.h"

#include "..\..\..\Item_Library\Item_Interface.h"

MainHand_ptr generateMainHand(ID entityID, Blueprint blueprint) {
	MainHand_ptr newMainHand(new CompMainHand(entityID));

	if (getItemName(entityID) == "Robe") {

		if (chkScore(entityID, INT) > chkScore(entityID, FTH) &&
			chkScore(entityID, INT) > chkScore(entityID, LCK)) {

			if (chkScore(entityID, STR) < 14) {

				newMainHand->m_weapon = createStaff(entityID);

			}
			else {
				newMainHand->m_weapon = createShortSword(entityID);
			}

		}

		else if (chkScore(entityID, FTH) > chkScore(entityID, LCK)) {

			newMainHand->m_weapon = createRosary(entityID);

		}
		else {
			newMainHand->m_weapon = createHarp(entityID);
		}

	}
	else if (getItemName(entityID) == "Leather Armor") {
		if (chkScore(entityID, CON) < 11) {

			newMainHand->m_weapon = createBow(entityID);

		}
		else {
			newMainHand->m_weapon = createDagger(entityID);
		}
	}
	else if (getItemName(entityID) == "Chain Mail" &&
		chkScore(entityID, FTH) > 13) {

		newMainHand->m_weapon = createMace(entityID);

		blueprint.addComponent(OFFHAND);
	}
	else if (chkScore(entityID, STR) > 15) {

		newMainHand->m_weapon = createHammer(entityID);

	}
	else {
		newMainHand->m_weapon = createShortSword(entityID);
		blueprint.addComponent(OFFHAND);;
	}

	return std::move(newMainHand);
}