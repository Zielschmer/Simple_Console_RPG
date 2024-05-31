#include "includes\equip-spell.h"

bool checkKnowsSpell(int characterID, SpellList spellChoice) {

	for (auto spell : getCastComponent(characterID).m_spells) {
		if (spell.m_name == spellLibrary(spellChoice)) {
			return false;
		}
		return true;
	}

}

void equipSpell(Entity& equippingCharacter, SpellList spellChoice) {

	if (getMainHandComponent(equippingCharacter.getID()).m_name == "Staff" ||
		getSecondHandComponent(equippingCharacter.getID()).m_name == "Staff")
	{
		if (checkKnowsSpell(equippingCharacter.getID(), spellChoice)) {
			getCastComponent(equippingCharacter.getID()).m_spells.emplace_back(getSpell(spellChoice));
		}
	}

}