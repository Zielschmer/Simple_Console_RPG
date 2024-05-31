#include "includes\melody.h"

Melody getMelody(MelodyList melodyList) {

	Melody newMelody;

	switch (melodyList)
	{
	case INSPIRATION:
		newMelody.m_name = "Inspiration";
		newMelody.m_description = "Increase allies rolls.";
		newMelody.m_isAlly = true;
		newMelody.m_isAll = true;
		newMelody.m_type = 6;
		newMelody.m_cost = 0;
		break;
	case HASTE:
		newMelody.m_name = "Haste";
		newMelody.m_description = "Increase speed and AC to one ally.";
		newMelody.m_isAlly = true;
		newMelody.m_isAll = false;
		newMelody.m_type = 0;
		newMelody.m_cost = 1;
		break;
	case MIGHTY:
		newMelody.m_name = "Mighty";
		newMelody.m_description = "Give an advantage on damage roll to one ally.";
		newMelody.m_isAlly = true;
		newMelody.m_isAll = false;
		newMelody.m_type = 1;
		newMelody.m_cost = 1;
		break;
	case PRECISION:
		newMelody.m_name = "Precision";
		newMelody.m_description = "Give an advantage on attack roll to one ally.";
		newMelody.m_isAlly = true;
		newMelody.m_isAll = false;
		newMelody.m_type = 2;
		newMelody.m_cost = 1;
		break;
	case BULLSEYE:
		newMelody.m_name = "Bullseye";
		newMelody.m_description = "Give an advantage on magic roll to one ally.";
		newMelody.m_isAlly = true;
		newMelody.m_isAll = false;
		newMelody.m_type = 3;
		newMelody.m_cost = 1;
		break;
	case SLOW:
		newMelody.m_name = "Slow";
		newMelody.m_description = "Decrease speed, and DC of one enemy.";
		newMelody.m_isAlly = false;
		newMelody.m_isAll = false;
		newMelody.m_type = 0;
		newMelody.m_cost = 1;
		break;
	case WITHER:
		newMelody.m_name = "Wither";
		newMelody.m_description = "Give a disadvantage on damage roll to one enemy.";
		newMelody.m_isAlly = false;
		newMelody.m_isAll = false;
		newMelody.m_type = 1;
		newMelody.m_cost = 1;
		break;
	case BLIND:
		newMelody.m_name = "Blind";
		newMelody.m_description = "Give a disadvantage on attack roll to one enemy.";
		newMelody.m_isAlly = false;
		newMelody.m_isAll = false;
		newMelody.m_type = 2;
		newMelody.m_cost = 1;
		break;
	case SILENCE:
		newMelody.m_name = "Silence";
		newMelody.m_description = "Give silence condition to one enemy.";
		newMelody.m_isAlly = false;
		newMelody.m_isAll = false;
		newMelody.m_type = 3;
		newMelody.m_cost = 1;
		break;
	case HYPNOTIZE:
		newMelody.m_name = "Hypnotize";
		newMelody.m_description = "The hypnotized enemy will attack its allies.";
		newMelody.m_isAlly = false;
		newMelody.m_isAll = false;
		newMelody.m_type = 4;
		newMelody.m_cost = 2;
		break;
	case DANCE:
		newMelody.m_name = "Dance";
		newMelody.m_description = "All enemies will spend their turn dancing.";
		newMelody.m_isAlly = false;
		newMelody.m_isAll = true;
		newMelody.m_type = 5;
		newMelody.m_cost = 3;
		break;
	default:
		break;
	}

	return newMelody;

}

std::string melodyLibrary(MelodyList melodyList) {

	switch (melodyList)
	{
	case INSPIRATION:
		return "Inspiration";
		break;
	case HASTE:
		return "Haste";
		break;
	case MIGHTY:
		return "Mighty";
		break;
	case PRECISION:
		return "Precision";
		break;
	case BULLSEYE:
		return "Bullseye";
		break;
	case SLOW:
		return "Slow";
		break;
	case WITHER:
		return "Wither";
		break;
	case BLIND:
		return "Blind";
		break;
	case SILENCE:
		return "Silence";
		break;
	case HYPNOTIZE:
		return "Hypnotize";
		break;
	case DANCE:
		return "Dance";
		break;
	default:
		break;
	}

}