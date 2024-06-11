#ifndef COMP_STATS
#define COMP_STATS

#include "..\utils.h"
#include "Component.h"
#include "..\Systems\System_Conditions\CondEffect.h"

struct CompStats : public Component {
	using Component::Component;
	std::unordered_map<ScoreList, RollAdv> m_scrRoll;
	std::unordered_map<ScoreList, RollAdv> m_svgRoll;
	RollAdv m_atkRoll;
	RollAdv m_ACRoll;
	std::unordered_map<ConditionList, CondEffect> m_conditions;
};

using Stats_ptr = std::unique_ptr<CompStats>;

#endif