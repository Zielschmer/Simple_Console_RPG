#pragma once

#include <iostream>
#include <vector>

struct Spell {

	std::string m_name;
	std::string m_description;
	bool m_isTeleport;
	bool m_isPortal;
	bool m_isArea;
	bool m_isAll;
	int m_damageType;
	int m_cost;

};

struct Miracle {

	std::string m_name;
	std::string m_description;
	bool m_isRevive;
	bool m_isHeal;
	bool m_isCure;
	bool m_isRestore;
	bool m_isArea;
	bool m_isAll;
	int m_cost;

};

struct Melody {

	std::string m_name;
	std::string m_description;
	bool m_isAlly;
	bool m_isAll;
	int m_type;
	int m_cost;

};

struct Cast {

	int m_ownerID;
	std::vector<Spell> m_spells;
	std::vector<Miracle> m_miracles;
	std::vector<Melody> m_melodies;

};