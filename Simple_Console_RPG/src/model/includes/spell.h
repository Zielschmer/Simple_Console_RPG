#pragma once

#include <iostream>

struct Spell {

	std::string m_name = " ";
	std::string m_description = " ";
	bool m_isTeleport = false;
	bool m_isPortal = false;
	bool m_isArea = false;
	bool m_isAll = false;
	uint8_t m_damageType = 0;
	uint8_t m_cost = 0;

	Spell(std::string name, std::string description, bool isTeleport, bool isPortal, bool isArea, bool isAll, uint8_t damageType, uint8_t cost);

};

struct Flare : public Spell {

	static Spell& get();

private:
	Flare();

};

struct Freeze : public Spell {

	static Spell& get();

};

struct Shock : public Spell {

	static Spell& get();

};

struct Teleport : public Spell {

	static Spell& get();

};

struct Flame : public Spell {

	static Spell& get();

};

struct Ice : public Spell {

	static Spell& get();

};

struct Lightning : public Spell {

	static Spell& get();

};

struct Portal : public Spell {

	static Spell& get();

};

struct Inferno : public Spell {

	static Spell& get();

};

struct Cocitus : public Spell {

	static Spell& get();

};

struct Tempest : public Spell {

	static Spell& get();

};