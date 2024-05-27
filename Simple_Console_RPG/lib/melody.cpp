#include "includes\melody.h"

Melody::Melody(std::string name, std::string description, bool isAlly, bool isAll, int type, int cost) {

	this->m_name = name;
	this->m_description = description;
	this->m_isAlly = isAlly;
	this->m_isAll = isAll;
	this->m_type = type;
	this->m_cost = cost;

}

Melody& Haste::get() {
	static Haste haste(
		"Haste",
		"Increase speed and AC to one ally.",
		true,
		false,
		0,
		1
	);
	return haste;
}

Melody& Mighty::get() {
	static Mighty mighty(
		"Mighty",
		"Give an advantage on damage roll to one ally.",
		true,
		false,
		1,
		1
	);
	return mighty;
}

Melody& Precision::get() {
	static Precision precision(
		"Precision",
		"Give an advantage on attack roll to one ally.",
		true,
		false,
		2,
		1
	);
	return precision;
}

Melody& Bullseye::get() {
	static Bullseye bullseye(
		"Bullseye",
		"Give an advantage on magic roll to one ally.",
		true,
		false,
		3,
		1
	);
	return bullseye;
}

Melody& Slow::get() {
	static Slow slow(
		"Slow",
		"Decrease speed, and DC of one enemy.",
		false,
		false,
		0,
		1
	);
	return slow;
}

Melody& Wither::get() {
	static Wither wither(
		"Wither",
		"Give a disadvantage on damage roll to one enemy.",
		false,
		false,
		1,
		1
	);
	return wither;
}

Melody& Blind::get() {
	static Blind blind(
		"Blind",
		"Give a disadvantage on attack roll to one enemy.",
		false,
		false,
		2,
		1
	);
	return blind;
}

Melody& Silence::get() {
	static Silence silence(
		"Silence",
		"Give silence condition to one enemy.",
		false,
		false,
		3,
		1
	);
	return silence;
}

Melody& Hypnotize::get() {
	static Hypnotize hypnotize(
		"Hypnotize",
		"The hypnotized enemy will attack its allies.",
		false,
		false,
		4,
		2
	);
	return hypnotize;
}

Melody& Dance::get() {
	static Dance dance(
		"Dance",
		"All enemies will spend their turn dancing.",
		false,
		false,
		5,
		3
	);
	return dance;
}