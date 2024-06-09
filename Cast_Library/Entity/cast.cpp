#include "cast.h"

Cast::Cast(ID& nextID, const ID& ownerID, CompSet& compSet, std::string name, std::string desc)
	: m_ID(nextID), m_ownerID(ownerID), m_compSet(compSet), m_name(name), m_desc(desc) {}

void Cast::add_comp(CastCompList comp) {
	m_compSet.set(static_cast<int>(comp));
}

bool Cast::chk_comp(CastCompList comp) {
	return m_compSet.test(comp);
}

std::string Cast::chk_name() {
	return m_name;
}