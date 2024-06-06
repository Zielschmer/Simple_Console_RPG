#include "includes\equip_armor.h"

#include "includes\system_components.h"

void equipArmor(Entity& entity, ArmorList armor) {

	if (entity.chk_comp(RHAND)) {

		switch (armor) {
		case NOWEAPON:
			entity.rmv_comp(RHAND);
			delArmorComp(entity.getID());
			break;
		case ROBE:
			getArmorComp(entity.getID())->m_name = "Robe";
			getArmorComp(entity.getID())->m_baseArmor = 8;
			getArmorComp(entity.getID())->m_armorMod = NOMOD;
			getArmorComp(entity.getID())->m_fastCast = true;
			getArmorComp(entity.getID())->m_dexterityDebuff = false;
			break;
		case LEATHER_ARMOR:
			getArmorComp(entity.getID())->m_name = "Leather Armor";
			getArmorComp(entity.getID())->m_baseArmor = 10;
			getArmorComp(entity.getID())->m_armorMod = DEX;
			getArmorComp(entity.getID())->m_fastCast = false;
			getArmorComp(entity.getID())->m_dexterityDebuff = false;
			break;
		case RING_MAIL:
			getArmorComp(entity.getID())->m_name = "Ring Mail";
			getArmorComp(entity.getID())->m_baseArmor = 12;
			getArmorComp(entity.getID())->m_armorMod = NOMOD;
			getArmorComp(entity.getID())->m_fastCast = false;
			getArmorComp(entity.getID())->m_dexterityDebuff = false;
			break;
		case CHAIN_MAIL:
			getArmorComp(entity.getID())->m_name = "Chain Mail";
			getArmorComp(entity.getID())->m_baseArmor = 14;
			getArmorComp(entity.getID())->m_armorMod = CON;
			getArmorComp(entity.getID())->m_fastCast = false;
			getArmorComp(entity.getID())->m_dexterityDebuff = true;
			break;
		}

	}
	else {

		entity.add_comp(RHAND);
		Armor_ptr newArmor(new Armor_Comp);
		newArmor->m_ownerID = entity.getID();

		switch (armor) {

		case ROBE:
			newArmor->m_name = "Robe";
			newArmor->m_baseArmor = 8;
			newArmor->m_armorMod = NOMOD;
			newArmor->m_fastCast = true;
			newArmor->m_dexterityDebuff = false;
			break;
		case LEATHER_ARMOR:
			newArmor->m_name = "Leather Armor";
			newArmor->m_baseArmor = 10;
			newArmor->m_armorMod = DEX;
			newArmor->m_fastCast = false;
			newArmor->m_dexterityDebuff = false;
			break;
		case RING_MAIL:
			newArmor->m_name = "Ring Mail";
			newArmor->m_baseArmor = 12;
			newArmor->m_armorMod = NOMOD;
			newArmor->m_fastCast = false;
			newArmor->m_dexterityDebuff = false;
			break;
		case CHAIN_MAIL:
			newArmor->m_name = "Chain Mail";
			newArmor->m_baseArmor = 14;
			newArmor->m_armorMod = CON;
			newArmor->m_fastCast = false;
			newArmor->m_dexterityDebuff = true;
			break;
		}

		armorContainer.push_back(std::move(newArmor));

	}
}