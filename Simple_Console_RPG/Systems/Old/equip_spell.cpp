#include "includes\equip_spell.h"

#include "includes\system_components.h"

bool chkSpell(ID entityID, SpellList spell) {

	for (auto member : getCastComp(entityID)->m_spells) {
		if (member.m_name == spellLibrary(spell)) {
			return false;
		}
		return true;
	}

}

void equipSpell(Entity& entity, SpellList spell) {

	if (getRHandComp(entity.getID())->m_name == "Staff" ||
		getLHandComp(entity.getID())->m_name == "Staff")
	{
		if (chkSpell(entity.getID(), spell)) {
			getCastComp(entity.getID())->m_spells.emplace_back(getSpell(spell));
		}
	}

}