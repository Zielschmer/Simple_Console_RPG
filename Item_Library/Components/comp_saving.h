#ifndef COMP_SAVING
#define COMP_SAVING

#include "..\..\..\utilities\utils.h"
#include "Component.h"

struct CompSaving : public Component {
	using Component::Component;
	ScoreList m_mod;
	DC m_DC;
	bool m_fail;
};

using Saving_ptr = std::unique_ptr<CompSaving>;

#endif