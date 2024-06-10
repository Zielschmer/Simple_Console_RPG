#include "entity.h"

Entity::Entity(ID& nextID, CompSet& compset) : m_ID(nextID), m_compset(compset) { nextID++; }

bool Entity::chk_comp(CompList compList) {
	return m_compset.test(compList);
}

bool Entity::add_comp(CompList compList) {
	m_compset.set(compList);
	return true;
}

bool Entity::rmv_comp(CompList compList) {
	m_compset.reset(compList);
	return true;
}