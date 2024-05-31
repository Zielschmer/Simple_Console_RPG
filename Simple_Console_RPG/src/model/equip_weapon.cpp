#include "includes\equip-weapon.h"

void equipMainHand(Entity& equippingCharacter, int weaponChoice) {

	switch (weaponChoice) {
	case 0:
	{
		equippingCharacter.removeComponent(6);
		deleteArmorComponent(equippingCharacter.getID());
		break;
	}
	case 1:
	{
		getMainHandComponent(equippingCharacter.getID()).m_name = "Sword";
		getMainHandComponent(equippingCharacter.getID()).m_baseAttack = 6;
		getMainHandComponent(equippingCharacter.getID()).m_attackModifier = 1;
		getMainHandComponent(equippingCharacter.getID()).m_twoHanded = false;
		getMainHandComponent(equippingCharacter.getID()).m_ranged = false;
		getMainHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_luckAdvantage = false;
		break;
	}
	case 2:
	{
		getMainHandComponent(equippingCharacter.getID()).m_name = "Dagger";
		getMainHandComponent(equippingCharacter.getID()).m_baseAttack = 4;
		getMainHandComponent(equippingCharacter.getID()).m_attackModifier = 2;
		getMainHandComponent(equippingCharacter.getID()).m_twoHanded = false;
		getMainHandComponent(equippingCharacter.getID()).m_ranged = false;
		getMainHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_luckAdvantage = false;
		break;
	}
	case 3:
	{
		getMainHandComponent(equippingCharacter.getID()).m_name = "Mace";
		getMainHandComponent(equippingCharacter.getID()).m_baseAttack = 6;
		getMainHandComponent(equippingCharacter.getID()).m_attackModifier = 1;
		getMainHandComponent(equippingCharacter.getID()).m_twoHanded = false;
		getMainHandComponent(equippingCharacter.getID()).m_ranged = false;
		getMainHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_luckAdvantage = false;
		break;
	}
	case 4:
		getMainHandComponent(equippingCharacter.getID()).m_name = "Hammer";
		getMainHandComponent(equippingCharacter.getID()).m_baseAttack = 8;
		getMainHandComponent(equippingCharacter.getID()).m_attackModifier = 1;
		getMainHandComponent(equippingCharacter.getID()).m_twoHanded = true;
		getMainHandComponent(equippingCharacter.getID()).m_ranged = false;
		getMainHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_luckAdvantage = false;
		break;
	case 5:
	{
		getMainHandComponent(equippingCharacter.getID()).m_name = "Bow";
		getMainHandComponent(equippingCharacter.getID()).m_baseAttack = 6;
		getMainHandComponent(equippingCharacter.getID()).m_attackModifier = 2;
		getMainHandComponent(equippingCharacter.getID()).m_twoHanded = true;
		getMainHandComponent(equippingCharacter.getID()).m_ranged = true;
		getMainHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_luckAdvantage = false;
		break;
	}
	case 6:
	{
		getMainHandComponent(equippingCharacter.getID()).m_name = "Staff";
		getMainHandComponent(equippingCharacter.getID()).m_baseAttack = 0;
		getMainHandComponent(equippingCharacter.getID()).m_attackModifier = 0;
		getMainHandComponent(equippingCharacter.getID()).m_twoHanded = false;
		getMainHandComponent(equippingCharacter.getID()).m_ranged = false;
		getMainHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = true;
		getMainHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_luckAdvantage = false;
		break;
	}
	case 7:
	{
		getMainHandComponent(equippingCharacter.getID()).m_name = "Rosary";
		getMainHandComponent(equippingCharacter.getID()).m_baseAttack = 0;
		getMainHandComponent(equippingCharacter.getID()).m_attackModifier = 0;
		getMainHandComponent(equippingCharacter.getID()).m_twoHanded = false;
		getMainHandComponent(equippingCharacter.getID()).m_ranged = false;
		getMainHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_faithAdvantage = true;
		getMainHandComponent(equippingCharacter.getID()).m_luckAdvantage = false;
		break;
	}
	case 8:
	{
		getMainHandComponent(equippingCharacter.getID()).m_name = "Harp";
		getMainHandComponent(equippingCharacter.getID()).m_baseAttack = 0;
		getMainHandComponent(equippingCharacter.getID()).m_attackModifier = 0;
		getMainHandComponent(equippingCharacter.getID()).m_twoHanded = true;
		getMainHandComponent(equippingCharacter.getID()).m_ranged = false;
		getMainHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		getMainHandComponent(equippingCharacter.getID()).m_luckAdvantage = true;
		break;
	}
	default:
		break;
	}

}

void equipSecondHand(Entity& equippingCharacter, int weaponChoice) {

	switch (weaponChoice) {
	case 0:
	{
		equippingCharacter.removeComponent(7);
		deleteArmorComponent(equippingCharacter.getID());
		break;
	}
	case 1:
	{
		getSecondHandComponent(equippingCharacter.getID()).m_name = "Sword";
		getSecondHandComponent(equippingCharacter.getID()).m_baseAttack = 6;
		getSecondHandComponent(equippingCharacter.getID()).m_attackModifier = 1;
		getSecondHandComponent(equippingCharacter.getID()).m_baseArmor = 0;
		getSecondHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getSecondHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		break;
	}
	case 2:
	{
		getSecondHandComponent(equippingCharacter.getID()).m_name = "Dagger";
		getSecondHandComponent(equippingCharacter.getID()).m_baseAttack = 4;
		getSecondHandComponent(equippingCharacter.getID()).m_attackModifier = 2;
		getSecondHandComponent(equippingCharacter.getID()).m_baseArmor = 0;
		getSecondHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getSecondHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		break;
	}
	case 3:
	{
		getSecondHandComponent(equippingCharacter.getID()).m_name = "Mace";
		getSecondHandComponent(equippingCharacter.getID()).m_baseAttack = 6;
		getSecondHandComponent(equippingCharacter.getID()).m_attackModifier = 1;
		getSecondHandComponent(equippingCharacter.getID()).m_baseArmor = 0;
		getSecondHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getSecondHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		break;
	}
	case 6:
	{
		getSecondHandComponent(equippingCharacter.getID()).m_name = "Staff";
		getSecondHandComponent(equippingCharacter.getID()).m_baseAttack = 0;
		getSecondHandComponent(equippingCharacter.getID()).m_attackModifier = 0;
		getSecondHandComponent(equippingCharacter.getID()).m_baseArmor = 0;
		getSecondHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = true;
		getSecondHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		break;
	}
	case 7:
	{
		getSecondHandComponent(equippingCharacter.getID()).m_name = "Rosary";
		getSecondHandComponent(equippingCharacter.getID()).m_baseAttack = 0;
		getSecondHandComponent(equippingCharacter.getID()).m_attackModifier = 0;
		getSecondHandComponent(equippingCharacter.getID()).m_baseArmor = 0;
		getSecondHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getSecondHandComponent(equippingCharacter.getID()).m_faithAdvantage = true;
		break;
	}
	case 9:
	{
		getSecondHandComponent(equippingCharacter.getID()).m_name = "Shield";
		getSecondHandComponent(equippingCharacter.getID()).m_baseAttack = 0;
		getSecondHandComponent(equippingCharacter.getID()).m_attackModifier = 0;
		getSecondHandComponent(equippingCharacter.getID()).m_baseArmor = 2;
		getSecondHandComponent(equippingCharacter.getID()).m_intelligenceAdvantage = false;
		getSecondHandComponent(equippingCharacter.getID()).m_faithAdvantage = false;
		break;
	}
	default:
		break;
	}

}

void equipWeapon(Entity& equippingCharacter, WeaponList weaponChoice) {

	if (equippingCharacter.checkComponent(6) && equippingCharacter.checkComponent(7)) {
		switch (weaponChoice)
		{
		case 0:
			if (validOptionInput(UNEQUIP)) {
				equippingCharacter.removeComponent(6);
				deleteMainHandComponent(equippingCharacter.getID());
			}
			else
			{
				equippingCharacter.removeComponent(7);
				deleteSecondHandComponent(equippingCharacter.getID());
			}
			break;
		case 4:	case 5:	case 8:
			if (validBoolInput(TWOHAND_DELETE_R_L)) {
				equipMainHand(equippingCharacter, weaponChoice);
				equippingCharacter.removeComponent(7);
				deleteSecondHandComponent(equippingCharacter.getID());
			}
			else {
				break;
			}
			break;
		case 9:
			equipSecondHand(equippingCharacter, weaponChoice);
			break;
		default:
			if (validOptionInput(EQUIP_HAND)) {
				equipSecondHand(equippingCharacter, weaponChoice);
			}
			else
			{
				equipMainHand(equippingCharacter, weaponChoice);
			}
			break;
		}
	}
	else if (!equippingCharacter.checkComponent(6) && equippingCharacter.checkComponent(7)) {
		switch (weaponChoice)
		{
		case 0:
			equippingCharacter.removeComponent(7);
			deleteSecondHandComponent(equippingCharacter.getID());
			break;
		case 4: case 5: case 8:
			if (validBoolInput(TWOHAND_DELETE_L)) {
				equippingCharacter.addComponent(6);
				MainHand* mainHand = new MainHand;
				mainHand->m_ownerID = equippingCharacter.getID();
				std::unique_ptr<MainHand> mainHandPointer(mainHand);
				mainHandComponents.push_back(std::move(mainHandPointer));
				equipMainHand(equippingCharacter, weaponChoice);
				equippingCharacter.removeComponent(7);
				deleteSecondHandComponent(equippingCharacter.getID());
			}
			else {
				break;
			}
		case 9:
			break;
		default:
			equippingCharacter.addComponent(6);
			MainHand* mainHand = new MainHand;
			mainHand->m_ownerID = equippingCharacter.getID();
			std::unique_ptr<MainHand> mainHandPointer(mainHand);
			mainHandComponents.push_back(std::move(mainHandPointer));
			equipMainHand(equippingCharacter, weaponChoice);
			break;
		}
	}
	else if (equippingCharacter.checkComponent(6) && !equippingCharacter.checkComponent(7)) {

		switch (weaponChoice)
		{
		case 0:
		{
			equippingCharacter.removeComponent(6);
			deleteMainHandComponent(equippingCharacter.getID());
			break;
		}
		case 4: case 5: case 8:
			if (validBoolInput(TWOHAND_DELETE_R)) {
				equipMainHand(equippingCharacter, weaponChoice);
			}
			else {
				break;
			}
			break;
		default:
		{
			if (getMainHandComponent(equippingCharacter.getID()).m_twoHanded) {
				if (validBoolInput(ONEHAND_DELETE_TWOHAND)) {
					equipMainHand(equippingCharacter, weaponChoice);
				}
				else {
					break;
				}
			}
			else
			{
				equippingCharacter.addComponent(7);
				SecondHand* secondHand = new SecondHand;
				secondHand->m_ownerID = equippingCharacter.getID();
				std::unique_ptr<SecondHand> secondHandPointer(secondHand);
				secondHandComponents.push_back(std::move(secondHandPointer));
				equipSecondHand(equippingCharacter, weaponChoice);
			}
			break;
		}
		}
		return;
	}
	else {
		switch (weaponChoice)
		{
		case 0:
			break;
		case 9:
		{
			equippingCharacter.addComponent(7);
			SecondHand* secondHand = new SecondHand;
			secondHand->m_ownerID = equippingCharacter.getID();
			std::unique_ptr<SecondHand> secondHandPointer(secondHand);
			secondHandComponents.push_back(std::move(secondHandPointer));
			equipSecondHand(equippingCharacter, weaponChoice);
			break;
		}
		default:
		{
			equippingCharacter.addComponent(6);
			MainHand* mainHand = new MainHand;
			mainHand->m_ownerID = equippingCharacter.getID();
			std::unique_ptr<MainHand> mainHandPointer(mainHand);
			mainHandComponents.push_back(std::move(mainHandPointer));
			equipMainHand(equippingCharacter, weaponChoice);
			break;
		}
		}
	}

	if (!equippingCharacter.checkComponent(8)) {
		if (equippingCharacter.checkComponent(6)) {
			if (getMainHandComponent(equippingCharacter.getID()).m_name == "Staff" ||
				getMainHandComponent(equippingCharacter.getID()).m_name == "Rosary" ||
				getMainHandComponent(equippingCharacter.getID()).m_name == "Harp")
			{
				equippingCharacter.addComponent(8);
				Cast* cast = new Cast;
				cast->m_ownerID = equippingCharacter.getID();
				std::unique_ptr<Cast> castPointer(cast);
				castComponents.push_back(std::move(castPointer));
			}
		}
		if (equippingCharacter.checkComponent(7)) {
			if (getSecondHandComponent(equippingCharacter.getID()).m_name == "Staff" ||
				getSecondHandComponent(equippingCharacter.getID()).m_name == "Rosary")
			{
				equippingCharacter.addComponent(8);
				Cast* cast = new Cast;
				cast->m_ownerID = equippingCharacter.getID();
				std::unique_ptr<Cast> castPointer(cast);
				castComponents.push_back(std::move(castPointer));
			}
		}

	}
	else {
		bool stage1 = true;
		if (equippingCharacter.checkComponent(6)) {
			if (getMainHandComponent(equippingCharacter.getID()).m_name == "Staff" ||
				getMainHandComponent(equippingCharacter.getID()).m_name == "Rosary" ||
				getMainHandComponent(equippingCharacter.getID()).m_name == "Harp")
			{
				stage1 = false;
			}
		}
		if (equippingCharacter.checkComponent(7)) {
			if (stage1 == true &&
				getSecondHandComponent(equippingCharacter.getID()).m_name == "Staff" ||
				getSecondHandComponent(equippingCharacter.getID()).m_name == "Rosary")
			{
				stage1 = false;
			}
		}
		if (stage1) {
			equippingCharacter.removeComponent(8);
			deleteCastComponent(equippingCharacter.getID());
		}
	}

}