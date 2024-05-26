#pragma once

#include <iostream>

struct Spell {

	std::string m_name;
	std::string m_description;
	bool m_isTeleport = false;
	bool m_isPortal = false;
	bool m_isArea = false;
	bool m_isAll = false;
	uint8_t m_damageType = 0;
	uint8_t m_cost = 0;

};

struct Flare : public Spell {

	std::string m_name = "Flare";
	std::string m_description = "Set one enemy ablaze.";
	uint8_t m_damageType = 0;
	uint8_t m_cost = 1;

	static Spell& get();

};

struct Freeze : public Spell {

	std::string m_name = "Freeze";
	std::string m_description = "Freeze one enemy.";
	uint8_t m_damageType = 1;
	uint8_t m_cost = 1;

	static Spell& get();

};

struct Shock : public Spell {

	std::string m_name = "Shock";
	std::string m_description = "Eletroctute one enemy.";
	uint8_t m_damageType = 2;
	uint8_t m_cost = 1;

	static Spell& get();

};
/*
struct Teleport : public Spell {

	std::string m_name = "Teleport";
	std::string m_description = "Escape the dungeon.";
	bool m_isTeleport = true;
	uint8_t m_cost = 1;

	Spell& get() override;

};

struct Flame : public Spell {

	std::string m_name = "Flame";
	std::string m_description = "Set one enemy and adjacents ablaze.";
	bool m_isArea = true;
	uint8_t m_damageType = 0;
	uint8_t m_cost = 2;

	Spell& get() override;

};

struct Ice : public Spell {

	std::string m_name = "Flame";
	std::string m_description = "Freeze one enemy and adjacents.";
	bool m_isArea = true;
	uint8_t m_damageType = 1;
	uint8_t m_cost = 2;

	Spell& get() override;

};

struct Lightining : public Spell {

	std::string m_name = "Lightining";
	std::string m_description = "Eletrocute one enemy and adjacents.";
	bool m_isArea = true;
	uint8_t m_damageType = 2;
	uint8_t m_cost = 2;

	Spell& get() override;

};

struct Portal : public Spell {

	std::string m_name = "Portal";
	std::string m_description = "Create a portal to the city and back.";
	bool m_isPortal = true;
	uint8_t m_cost = 2;

	Spell& get() override;

};

struct Inferno : public Spell {

	std::string m_name = "Inferno";
	std::string m_description = "Set all enemies ablaze.";
	bool m_isAll = true;
	uint8_t m_damageType = 0;
	uint8_t m_cost = 3;

	Spell& get() override;

};

struct Cocitus : public Spell {

	std::string m_name = "Cocitus";
	std::string m_description = "Freeze all enemies.";
	bool m_isAll = true;
	uint8_t m_damageType = 1;
	uint8_t m_cost = 3;

	Spell& get() override;

};

struct Tempest : public Spell {

	std::string m_name = "Tempest";
	std::string m_description = "Eletroctute all enemies.";
	bool m_isAll = true;
	uint8_t m_damageType = 2;
	uint8_t m_cost = 3;

	Spell& get() override;

};*/