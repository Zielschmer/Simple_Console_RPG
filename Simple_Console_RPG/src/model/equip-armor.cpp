#include "includes\equip-armor.h"

void equipArmor(Entity& equippingCharacter, int armorChoice) {

	if (equippingCharacter.checkComponent(5)) {
		switch (armorChoice) {
		case 0:
			equippingCharacter.removeComponent(5);
			deleteArmorComponent(equippingCharacter.getID());
			break;
		case 1:
			getArmorComponent(equippingCharacter.getID()).m_name = "Robe";
			getArmorComponent(equippingCharacter.getID()).m_baseArmor = 8;
			getArmorComponent(equippingCharacter.getID()).m_armorModifier = 0;
			getArmorComponent(equippingCharacter.getID()).m_fastCast = true;
			getArmorComponent(equippingCharacter.getID()).m_dexterityDebuff = false;
			break;
		case 2:
			getArmorComponent(equippingCharacter.getID()).m_name = "Leather Armor";
			getArmorComponent(equippingCharacter.getID()).m_baseArmor = 10;
			getArmorComponent(equippingCharacter.getID()).m_armorModifier = 2;
			getArmorComponent(equippingCharacter.getID()).m_fastCast = false;
			getArmorComponent(equippingCharacter.getID()).m_dexterityDebuff = false;
			break;
		case 3:
			getArmorComponent(equippingCharacter.getID()).m_name = "Ring Mail";
			getArmorComponent(equippingCharacter.getID()).m_baseArmor = 12;
			getArmorComponent(equippingCharacter.getID()).m_armorModifier = 0;
			getArmorComponent(equippingCharacter.getID()).m_fastCast = false;
			getArmorComponent(equippingCharacter.getID()).m_dexterityDebuff = false;
			break;
		case 4:
			getArmorComponent(equippingCharacter.getID()).m_name = "Chain Mail";
			getArmorComponent(equippingCharacter.getID()).m_baseArmor = 14;
			getArmorComponent(equippingCharacter.getID()).m_armorModifier = 1;
			getArmorComponent(equippingCharacter.getID()).m_fastCast = false;
			getArmorComponent(equippingCharacter.getID()).m_dexterityDebuff = true;
			break;
		default:
			break;
		}
	}
	else {

		equippingCharacter.addComponent(5);
		Armor* armor = new Armor;
		armor->m_ownerID = equippingCharacter.getID();

		switch (armorChoice) {

		case 1:
			armor->m_name = "Robe";
			armor->m_baseArmor = 8;
			armor->m_armorModifier = 0;
			armor->m_fastCast = true;
			armor->m_dexterityDebuff = false;
			break;
		case 2:
			armor->m_name = "Leather Armor";
			armor->m_baseArmor = 10;
			armor->m_armorModifier = 2;
			armor->m_fastCast = false;
			armor->m_dexterityDebuff = false;
			break;
		case 3:
			armor->m_name = "Ring Mail";
			armor->m_baseArmor = 12;
			armor->m_armorModifier = 0;
			armor->m_fastCast = false;
			armor->m_dexterityDebuff = false;
			break;
		case 4:
			armor->m_name = "Chain Mail";
			armor->m_baseArmor = 14;
			armor->m_armorModifier = 1;
			armor->m_fastCast = false;
			armor->m_dexterityDebuff = true;
			break;
		default:
			break;
		}

		std::unique_ptr<Armor> armorPointer (armor);
		armorComponents.push_back(std::move(armorPointer));

	}
}