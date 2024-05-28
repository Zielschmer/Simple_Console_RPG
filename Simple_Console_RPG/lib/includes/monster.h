#pragma once

#include "..\..\src\model\includes\entity.h"

struct NaturalArmor {

	int m_ownerID;
	int m_armorClass;

};

struct NaturalWeapon {

	std::string m_name;
	int m_baseAttack;
	int m_savingThrow;
	int m_difficultClass;
	int m_extraDamage;
	bool m_passEffect;

};

struct NaturalWeapons {

	int m_ownerID;
	std::vector<NaturalWeapon> m_naturalWeapons;

};
