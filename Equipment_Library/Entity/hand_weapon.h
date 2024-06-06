#pragma once

enum WeaponList {

	NOWEAPON,
	SWORD,
	DAGGER,
	MACE,
	HAMMER,
	BOW,
	STAFF,
	ROSARY,
	HARP,
	SHIELD

};

struct Weapon {

	std::string m_name;
	int m_diceAtk;
	int m_savingThrow;
	int m_DC;
	int m_extraDice;
	bool m_passEffect;

};