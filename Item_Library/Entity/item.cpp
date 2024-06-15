#include "item.h"

Item::Item(ID& nextID, const ID& ownerID, CompSet& compSet, std::string name, std::string desc)
	: m_ID(nextID), m_ownerID(ownerID), m_compSet(compSet), m_name(name), m_desc(desc) {}

CompSet& Item::get_comp() {
	return m_compSet;
}

std::string& Item::get_name() {
	return m_name;
}

std::string& Item::get_desc() {
	return m_desc;
}