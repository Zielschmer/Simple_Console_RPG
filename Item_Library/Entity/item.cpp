#include "item.h"

Item::Item(ID& nextID, const ID& ownerID, std::string name, std::string desc)
	: m_ID(nextID), m_name(name), m_desc(desc), m_ownerID(ownerID) {}