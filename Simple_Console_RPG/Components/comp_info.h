#ifndef COMP_INFO
#define COMP_INFO

#include <string>
#include <memory>

#include "..\utils.h"

struct Info_Comp {

	ID m_ownerID;
	std::string m_name;
	std::string m_desc;

};

using Info_ptr = std::unique_ptr<Info_Comp>;

#endif