#pragma once

#include <iostream>

struct Spell {

	std::string m_name;
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

	using Spell::Spell;

};

struct Freeze : public Spell {

	static Spell& get();

	using Spell::Spell;

};

struct Shock : public Spell {

	static Spell& get();

	using Spell::Spell;

};

struct Teleport : public Spell {

	static Spell& get();

	using Spell::Spell;

};

struct Flame : public Spell {

	static Spell& get();

	using Spell::Spell;

};

struct Ice : public Spell {

	static Spell& get();

	using Spell::Spell;

};

struct Lightning : public Spell {

	static Spell& get();

	using Spell::Spell;

};

struct Portal : public Spell {

	static Spell& get();

	using Spell::Spell;

};

struct Inferno : public Spell {

	static Spell& get();

	using Spell::Spell;

};

struct Cocitus : public Spell {

	static Spell& get();

	using Spell::Spell;

};

struct Tempest : public Spell {

	static Spell& get();

	using Spell::Spell;

};