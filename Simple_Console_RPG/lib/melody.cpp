#include "includes\cast.h"

Melody getHaste () {

	Melody newMelody;

	newMelody.m_name = "Haste";
	newMelody.m_description = "Increase speed and AC to one ally.";
	newMelody.m_isAlly = true;
	newMelody.m_isAll = false;
	newMelody.m_type = 0;
	newMelody.m_cost = 1;

	return newMelody;

}

Melody getMighty() {

	Melody newMelody;

	newMelody.m_name = "Mighty";
	newMelody.m_description = "Give an advantage on damage roll to one ally.";
	newMelody.m_isAlly = true;
	newMelody.m_isAll = false;
	newMelody.m_type = 1;
	newMelody.m_cost = 1;

	return newMelody;

}

Melody getPrecision() {

	Melody newMelody;

	newMelody.m_name = "Precision";
	newMelody.m_description = "Give an advantage on attack roll to one ally.";
	newMelody.m_isAlly = true;
	newMelody.m_isAll = false;
	newMelody.m_type = 2;
	newMelody.m_cost = 1;

	return newMelody;

}

Melody getBullseye() {

	Melody newMelody;

	newMelody.m_name = "Bullseye";
	newMelody.m_description = "Give an advantage on magic roll to one ally.";
	newMelody.m_isAlly = true;
	newMelody.m_isAll = false;
	newMelody.m_type = 3;
	newMelody.m_cost = 1;

	return newMelody;

}

Melody getSlow() {

	Melody newMelody;

	newMelody.m_name = "Slow";
	newMelody.m_description = "Decrease speed, and DC of one enemy.";
	newMelody.m_isAlly = false;
	newMelody.m_isAll = false;
	newMelody.m_type = 0;
	newMelody.m_cost = 1;

	return newMelody;

}

Melody getWither() {

	Melody newMelody;

	newMelody.m_name = "Wither";
	newMelody.m_description = "Give a disadvantage on damage roll to one enemy.";
	newMelody.m_isAlly = false;
	newMelody.m_isAll = false;
	newMelody.m_type = 1;
	newMelody.m_cost = 1;

	return newMelody;

}

Melody getBlind() {

	Melody newMelody;

	newMelody.m_name = "Blind";
	newMelody.m_description = "Give a disadvantage on attack roll to one enemy.";
	newMelody.m_isAlly = false;
	newMelody.m_isAll = false;
	newMelody.m_type = 2;
	newMelody.m_cost = 1;

	return newMelody;

}

Melody getSilence() {

	Melody newMelody;

	newMelody.m_name = "Silence";
	newMelody.m_description = "Give silence condition to one enemy.";
	newMelody.m_isAlly = false;
	newMelody.m_isAll = false;
	newMelody.m_type = 3;
	newMelody.m_cost = 1;

	return newMelody;

}

Melody getHypnotize() {

	Melody newMelody;

	newMelody.m_name = "Hypnotize";
	newMelody.m_description = "The hypnotized enemy will attack its allies.";
	newMelody.m_isAlly = false;
	newMelody.m_isAll = false;
	newMelody.m_type = 4;
	newMelody.m_cost = 2;

	return newMelody;

}

Melody getDance() {

	Melody newMelody;

	newMelody.m_name = "Dance";
	newMelody.m_description = "All enemies will spend their turn dancing.";
	newMelody.m_isAlly = false;
	newMelody.m_isAll = true;
	newMelody.m_type = 5;
	newMelody.m_cost = 3;

	return newMelody;

}