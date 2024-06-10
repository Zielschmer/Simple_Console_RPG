#ifndef COMP_STATS
#define COMP_STATS

#include "..\utils.h"
#include "Component.h"
#include "..\Systems\System_Conditions\CondEffect.h"

struct CompStats : public Component {
	using Component::Component;
	std::unordered_map<ScoreList, RollType> m_scrRoll;
	std::unordered_map<ScoreList, RollType> m_svgRoll;
	RollType m_atkRoll;
	RollType m_AC;
	std::unordered_map<ConditionList, CondEffect> m_conditions;
};

using Stats_ptr = std::unique_ptr<CompStats>;

#endif