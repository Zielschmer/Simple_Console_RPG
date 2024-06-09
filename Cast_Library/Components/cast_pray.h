#pragma once

#include <string>

struct Pray {

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

enum PrayList {

	TEND,
	HEAL,
	CURE,
	REVIVE,
	PRAY,
	MASS_HEAL,
	MASS_CURE,
	SMITE,
	RESTORE,
	REINCARNATE,
	JUDGMENT

};

Pray getPray(PrayList prayList);

std::string prayLibrary(PrayList prayList);