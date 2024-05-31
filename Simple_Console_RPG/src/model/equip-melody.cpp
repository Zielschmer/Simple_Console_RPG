#include "includes\equip-melody.h"

bool checkKnowsMelody(int characterID, MelodyList melodyChoice) {

	for (auto melody : getCastComponent(characterID).m_spells) {
		if (melody.m_name == melodyLibrary(melodyChoice)) {
			return false;
		}
		return true;
	}

}

void equipMelody(Entity& equippingCharacter, MelodyList melodyChoice) {

	if (getMainHandComponent(equippingCharacter.getID()).m_name == "Harp")
	{
		if (checkKnowsMelody(equippingCharacter.getID(), melodyChoice)) {
			getCastComponent(equippingCharacter.getID()).m_melodies.emplace_back(getMelody(melodyChoice));
		}
	}

}