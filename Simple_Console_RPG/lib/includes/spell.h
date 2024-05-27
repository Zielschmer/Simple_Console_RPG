#pragma once

#include <iostream>

struct Spell {

	std::string m_name;
	std::string m_description;
	bool m_isTeleport;
	bool m_isPortal;
	bool m_isArea;
	bool m_isAll;
	int m_damageType;
	int m_cost;

	Spell(std::string name, std::string description, bool isTeleport, bool isPortal, bool isArea, bool isAll, int damageType, int cost);

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