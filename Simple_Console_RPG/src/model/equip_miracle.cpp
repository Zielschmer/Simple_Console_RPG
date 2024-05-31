#include "includes\equip-miracle.h"

bool checkKnowsMiracle(int characterID, MiracleList miracleChoice) {

	for (auto miracle : getCastComponent(characterID).m_spells) {
		if (miracle.m_name == miracleLibrary(miracleChoice)) {
			return false;
		}
		return true;
	}

}

void equipMiracle(Entity& equippingCharacter, MiracleList miracleChoice) {

	if (getMainHandComponent(equippingCharacter.getID()).m_name == "Rosary" ||
		getSecondHandComponent(equippingCharacter.getID()).m_name == "Rosary")
	{
		if (checkKnowsMiracle(equippingCharacter.getID(), miracleChoice)) {
			getCastComponent(equippingCharacter.getID()).m_miracles.emplace_back(getMiracle(miracleChoice));
		}
	}

}