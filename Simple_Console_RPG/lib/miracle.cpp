#include "includes\miracle.h"

Miracle::Miracle(std::string name, std::string description, bool isRevive, bool isHeal, bool isCure, bool isRestore, bool isArea, bool isAll, int cost) {

	this->m_name = name;
	this->m_description = description;
	this->m_isRevive = isRevive;
	this->m_isHeal = isHeal;
	this->m_isCure = isCure;
	this->m_isRestore = isRestore;
	this->m_isArea = isArea;
	this->m_isAll = isAll;
	this->m_cost = cost;

}

Miracle& Heal::get() {
	static Heal heal(
		"Heal",
		"Restore one ally's hit points.",
		false,
		true,
		false,
		false,
		false,
		false,
		1
	);
	return heal;
}

Miracle& Cure::get() {
	static Cure cure(
		"Cure",
		"Cure one ally's conditions.",
		false,
		false,
		true,
		false,
		false,
		false,
		1
	);
	return cure;
}

Miracle& Revive::get() {
	static Revive revive(
		"Revive",
		"Revive one ally.",
		true,
		false,
		false,
		false,
		false,
		false,
		2
	);
	return revive;
}

Miracle& Pray::get() {
	static Pray pray(
		"Pray",
		"Ask for divine punishment upon one enemy.",
		false,
		false,
		false,
		false,
		false,
		false,
		1
	);
	return pray;
}

Miracle& MassHeal::get() {
	static MassHeal massHeal(
		"Mass Heal",
		"Restore all allies's hit points.",
		false,
		true,
		false,
		false,
		false,
		true,
		2
	);
	return massHeal;
}

Miracle& MassCure::get() {
	static MassCure massCure(
		"Mass Cure",
		"Cure all allies's conditions.",
		false,
		false,
		true,
		false,
		false,
		true,
		1
	);
	return massCure;
}

Miracle& Smite::get() {
	static Smite smite(
		"Smite",
		"Ask for divine punishment upon one enemy and adjacents.",
		false,
		false,
		false,
		false,
		true,
		false,
		2
	);
	return smite;
}

Miracle& Restore::get() {
	static Restore restore(
		"Restore",
		"Fully restore one allies's hit points.",
		false,
		false,
		false,
		true,
		false,
		false,
		3
	);
	return restore;
}

Miracle& Reincarnate::get() {
	static Reincarnate reincarnate(
		"Reincarnate",
		"Revive one ally and fully restore their hit points.",
		true,
		false,
		false,
		true,
		false,
		false,
		4
	);
	return reincarnate;
}

Miracle& Judgment::get() {
	static Judgment judgment(
		"Judgment",
		"Ask for divine judgment upon all enemies.",
		false,
		false,
		false,
		false,
		false,
		true,
		3
	);
	return judgment;
}
