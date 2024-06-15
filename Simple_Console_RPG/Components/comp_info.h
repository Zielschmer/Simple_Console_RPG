#ifndef COMP_INFO
#define COMP_INFO

#include "..\..\..\utilities\utils.h"
#include "Component.h"

struct CompInfo : public Component {
	using Component::Component;
	std::string m_name;
	std::string m_desc;
};

using Info_ptr = std::unique_ptr<CompInfo>;

#endif