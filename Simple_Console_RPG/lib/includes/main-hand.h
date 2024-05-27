#pragma once

#include <iostream>

struct MainHand {

	int m_ownerID;
	std::string m_name;
	int m_baseAttack;
	int m_attackModifier;
	bool m_twoHanded;
	bool m_ranged;
	bool m_intelligenceAdvantage;
	bool m_faithAdvantage;
	bool m_luckAdvantage;

};