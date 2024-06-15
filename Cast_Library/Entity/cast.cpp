#include "cast.h"

Cast::Cast(ID& nextID, const ID& ownerID, CompSet& compSet, CastType type, std::string name, std::string desc)
	: m_ID(nextID), m_ownerID(ownerID), m_compSet(compSet), m_type(type), m_name(name), m_desc(desc) {}

CompSet& Cast::get_comp() {
	return m_compSet;
}

std::string& Cast::get_name() {
	return m_name;
}

std::string& Cast::get_desc() {
	return m_desc;
}