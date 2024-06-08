#include "item.h"

Item::Item(ID& nextID, const ID& ownerID, CompSet& compSet, std::string name, std::string desc)
	: m_ID(nextID), m_ownerID(ownerID), m_compSet(compSet), m_name(name), m_desc(desc) {}

void Item::add_comp(CompList comp) {
	m_compSet.set(static_cast<int>(comp));
}

bool Item::chk_comp(CompList comp) {
	return m_compSet.test(comp);
}

std::string Item::chk_name() {
	return m_name;
}