#include "item.h"

Item::Item(ID& nextID, std::string name, std::string desc)
	: m_ID(nextID), m_name(name), m_desc(desc) {}