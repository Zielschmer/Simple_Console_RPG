#pragma once

#include <iostream>

struct MainHand {

	std::string m_name;
	uint8_t m_baseAttack;
	uint8_t m_attackModifier;
	bool m_twoHanded;
	bool m_ranged;
	bool m_intelligenceAdvantage;
	bool m_faithAdvantage;
	bool m_luckAdvantage;

};