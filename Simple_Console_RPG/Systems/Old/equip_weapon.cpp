#include "includes\equip_weapon.h"

#include "includes\system_components.h"
#include "..\control\includes\bool-input.h"
#include "..\control\includes\options-input.h"

void equipMainHand(Entity& entity, WeaponList weapon) {

	switch (weapon) {
	case 0:
	{
		entity.rmv_comp(RHAND);
		delRHandComp(entity.getID());
		break;
	}
	case 1:
	{
		getRHandComp(entity.getID())->m_name = "Sword";
		getRHandComp(entity.getID())->m_diceAtk = D6;
		getRHandComp(entity.getID())->m_atkMod = STR;
		getRHandComp(entity.getID())->m_twoHanded = false;
		getRHandComp(entity.getID())->m_range = 1;
		getRHandComp(entity.getID())->m_castSpell = false;
		getRHandComp(entity.getID())->m_castPray = false;
		getRHandComp(entity.getID())->m_castSong = false;
		break;
	}
	case 2:
	{
		getRHandComp(entity.getID())->m_name = "Dagger";
		getRHandComp(entity.getID())->m_diceAtk = D4;
		getRHandComp(entity.getID())->m_atkMod = DEX;
		getRHandComp(entity.getID())->m_twoHanded = false;
		getRHandComp(entity.getID())->m_range = 1;
		getRHandComp(entity.getID())->m_castSpell = false;
		getRHandComp(entity.getID())->m_castPray = false;
		getRHandComp(entity.getID())->m_castSong = false;
		break;
	}
	case 3:
	{
		getRHandComp(entity.getID())->m_name = "Mace";
		getRHandComp(entity.getID())->m_diceAtk = D6;
		getRHandComp(entity.getID())->m_atkMod = STR;
		getRHandComp(entity.getID())->m_twoHanded = false;
		getRHandComp(entity.getID())->m_range = 1;
		getRHandComp(entity.getID())->m_castSpell = false;
		getRHandComp(entity.getID())->m_castPray = false;
		getRHandComp(entity.getID())->m_castSong = false;
		break;
	}
	case 4:
		getRHandComp(entity.getID())->m_name = "Hammer";
		getRHandComp(entity.getID())->m_diceAtk = D8;
		getRHandComp(entity.getID())->m_atkMod = STR;
		getRHandComp(entity.getID())->m_twoHanded = true;
		getRHandComp(entity.getID())->m_range = 1;
		getRHandComp(entity.getID())->m_castSpell = false;
		getRHandComp(entity.getID())->m_castPray = false;
		getRHandComp(entity.getID())->m_castSong = false;
		break;
	case 5:
	{
		getRHandComp(entity.getID())->m_name = "Bow";
		getRHandComp(entity.getID())->m_diceAtk = D6;
		getRHandComp(entity.getID())->m_atkMod = DEX;
		getRHandComp(entity.getID())->m_twoHanded = true;
		getRHandComp(entity.getID())->m_range = 16;
		getRHandComp(entity.getID())->m_castSpell = false;
		getRHandComp(entity.getID())->m_castPray = false;
		getRHandComp(entity.getID())->m_castSong = false;
		break;
	}
	case 6:
	{
		getRHandComp(entity.getID())->m_name = "Staff";
		getRHandComp(entity.getID())->m_diceAtk = D0;
		getRHandComp(entity.getID())->m_atkMod = NOMOD;
		getRHandComp(entity.getID())->m_twoHanded = false;
		getRHandComp(entity.getID())->m_range = 1;
		getRHandComp(entity.getID())->m_castSpell = true;
		getRHandComp(entity.getID())->m_castPray = false;
		getRHandComp(entity.getID())->m_castSong = false;
		break;
	}
	case 7:
	{
		getRHandComp(entity.getID())->m_name = "Rosary";
		getRHandComp(entity.getID())->m_diceAtk = D0;
		getRHandComp(entity.getID())->m_atkMod = NOMOD;
		getRHandComp(entity.getID())->m_twoHanded = false;
		getRHandComp(entity.getID())->m_range = 1;
		getRHandComp(entity.getID())->m_castSpell = false;
		getRHandComp(entity.getID())->m_castPray = true;
		getRHandComp(entity.getID())->m_castSong = false;
		break;
	}
	case 8:
	{
		getRHandComp(entity.getID())->m_name = "Harp";
		getRHandComp(entity.getID())->m_diceAtk = D0;
		getRHandComp(entity.getID())->m_atkMod = NOMOD;
		getRHandComp(entity.getID())->m_twoHanded = true;
		getRHandComp(entity.getID())->m_range = 1;
		getRHandComp(entity.getID())->m_castSpell = false;
		getRHandComp(entity.getID())->m_castPray = false;
		getRHandComp(entity.getID())->m_castSong = true;
		break;
	}
	default:
		break;
	}

}

void equipSecondHand(Entity& entity, int weapon) {

	switch (weapon) {
	case 0:
	{
		entity.rmv_comp(LHAND);
		delLHandComp(entity.getID());
		break;
	}
	case 1:
	{
		getLHandComp(entity.getID())->m_name = "Sword";
		getLHandComp(entity.getID())->m_diceAtk = D6;
		getLHandComp(entity.getID())->m_atkMod = STR;
		getLHandComp(entity.getID())->m_armorClass = 0;
		getLHandComp(entity.getID())->m_castSpell = false;
		getLHandComp(entity.getID())->m_castPray = false;
		break;
	}
	case 2:
	{
		getLHandComp(entity.getID())->m_name = "Dagger";
		getLHandComp(entity.getID())->m_diceAtk = D4;
		getLHandComp(entity.getID())->m_atkMod = DEX;
		getLHandComp(entity.getID())->m_armorClass = 0;
		getLHandComp(entity.getID())->m_castSpell = false;
		getLHandComp(entity.getID())->m_castPray = false;
		break;
	}
	case 3:
	{
		getLHandComp(entity.getID())->m_name = "Mace";
		getLHandComp(entity.getID())->m_diceAtk = D6;
		getLHandComp(entity.getID())->m_atkMod = STR;
		getLHandComp(entity.getID())->m_armorClass = 0;
		getLHandComp(entity.getID())->m_castSpell = false;
		getLHandComp(entity.getID())->m_castPray = false;
		break;
	}
	case 6:
	{
		getLHandComp(entity.getID())->m_name = "Staff";
		getLHandComp(entity.getID())->m_diceAtk = D0;
		getLHandComp(entity.getID())->m_atkMod = NOMOD;
		getLHandComp(entity.getID())->m_armorClass = 0;
		getLHandComp(entity.getID())->m_castSpell = true;
		getLHandComp(entity.getID())->m_castPray = false;
		break;
	}
	case 7:
	{
		getLHandComp(entity.getID())->m_name = "Rosary";
		getLHandComp(entity.getID())->m_diceAtk = D0;
		getLHandComp(entity.getID())->m_atkMod = NOMOD;
		getLHandComp(entity.getID())->m_armorClass = 0;
		getLHandComp(entity.getID())->m_castSpell = false;
		getLHandComp(entity.getID())->m_castPray = true;
		break;
	}
	case 9:
	{
		getLHandComp(entity.getID())->m_name = "Shield";
		getLHandComp(entity.getID())->m_diceAtk = D0;
		getLHandComp(entity.getID())->m_atkMod = NOMOD;
		getLHandComp(entity.getID())->m_armorClass = 2;
		getLHandComp(entity.getID())->m_castSpell = false;
		getLHandComp(entity.getID())->m_castPray = false;
		break;
	}
	default:
		break;
	}

}

void equipWeapon(Entity& entity, WeaponList weapon) {

	if (entity.chk_comp(RHAND) && entity.chk_comp(LHAND)) {
		switch (weapon)
		{
		case 0:
			if (validOptionInput(UNEQUIP)) {
				entity.rmv_comp(RHAND);
				delRHandComp(entity.getID());
			}
			else
			{
				entity.rmv_comp(LHAND);
				delLHandComp(entity.getID());
			}
			break;
		case 4:	case 5:	case 8:
			if (validBoolInput(TWOHAND_DELETE_R_L)) {
				equipMainHand(entity, weapon);
				entity.rmv_comp(LHAND);
				delLHandComp(entity.getID());
			}
			else {
				break;
			}
			break;
		case 9:
			equipSecondHand(entity, weapon);
			break;
		default:
			if (validOptionInput(EQUIP_HAND)) {
				equipSecondHand(entity, weapon);
			}
			else
			{
				equipMainHand(entity, weapon);
			}
			break;
		}
	}
	else if (!entity.chk_comp(RHAND) && entity.chk_comp(LHAND)) {
		switch (weapon)
		{
		case 0:
			entity.rmv_comp(LHAND);
			delLHandComp(entity.getID());
			break;
		case 4: case 5: case 8:
			if (validBoolInput(TWOHAND_DELETE_L)) {
				entity.add_comp(RHAND);
				RHand_ptr rHand(new RHand_Comp);
				rHand->m_ownerID = entity.getID();
				rHandContainer.push_back(std::move(rHand));
				equipMainHand(entity, weapon);
				entity.rmv_comp(LHAND);
				delLHandComp(entity.getID());
			}
			else {
				break;
			}
		case 9:
			break;
		default:
			entity.add_comp(RHAND);
			RHand_ptr rHand(new RHand_Comp);
			rHand->m_ownerID = entity.getID();
			rHandContainer.push_back(std::move(rHand));
			equipMainHand(entity, weapon);
			break;
		}
	}
	else if (entity.chk_comp(RHAND) && !entity.chk_comp(LHAND)) {

		switch (weapon)
		{
		case 0:
		{
			entity.rmv_comp(RHAND);
			delRHandComp(entity.getID());
			break;
		}
		case 4: case 5: case 8:
			if (validBoolInput(TWOHAND_DELETE_R)) {
				equipMainHand(entity, weapon);
			}
			else {
				break;
			}
			break;
		default:
		{
			if (getRHandComp(entity.getID())->m_twoHanded) {
				if (validBoolInput(ONEHAND_DELETE_TWOHAND)) {
					equipMainHand(entity, weapon);
				}
				else {
					break;
				}
			}
			else
			{
				entity.add_comp(LHAND);
				LHand_ptr lHand(new LHand_Comp);
				lHand->m_ownerID = entity.getID();
				lHandContainer.push_back(std::move(lHand));
				equipSecondHand(entity, weapon);
			}
			break;
		}
		}
		return;
	}
	else {
		switch (weapon)
		{
		case 0:
			break;
		case 9:
		{
			entity.add_comp(LHAND);
			LHand_ptr lHand(new LHand_Comp);
			lHand->m_ownerID = entity.getID();
			lHandContainer.push_back(std::move(lHand));
			equipSecondHand(entity, weapon);
			break;
		}
		default:
		{
			entity.add_comp(RHAND);
			RHand_ptr rHand(new RHand_Comp);
			rHand->m_ownerID = entity.getID();
			rHandContainer.push_back(std::move(rHand));
			equipMainHand(entity, weapon);
			break;
		}
		}
	}

	if (!entity.chk_comp(CAST)) {
		if (entity.chk_comp(RHAND)) {
			if (getRHandComp(entity.getID())->m_name == "Staff" ||
				getRHandComp(entity.getID())->m_name == "Rosary" ||
				getRHandComp(entity.getID())->m_name == "Harp")
			{
				entity.add_comp(CAST);
				Cast_ptr cast(new Cast_Comp);
				cast->m_ownerID = entity.getID();
				castContainer.push_back(std::move(cast));
			}
		}
		if (entity.chk_comp(LHAND)) {
			if (getLHandComp(entity.getID())->m_name == "Staff" ||
				getLHandComp(entity.getID())->m_name == "Rosary")
			{
				entity.add_comp(CAST);
				Cast_ptr cast(new Cast_Comp);
				cast->m_ownerID = entity.getID();
				castContainer.push_back(std::move(cast));
			}
		}

	}
	else {
		bool stage1 = true;
		if (entity.chk_comp(RHAND)) {
			if (getRHandComp(entity.getID())->m_name == "Staff" ||
				getRHandComp(entity.getID())->m_name == "Rosary" ||
				getRHandComp(entity.getID())->m_name == "Harp")
			{
				stage1 = false;
			}
		}
		if (entity.chk_comp(LHAND)) {
			if (stage1 == true &&
				getLHandComp(entity.getID())->m_name == "Staff" ||
				getLHandComp(entity.getID())->m_name == "Rosary")
			{
				stage1 = false;
			}
		}
		if (stage1) {
			entity.rmv_comp(CAST);
			delCastComp(entity.getID());
		}
	}

}