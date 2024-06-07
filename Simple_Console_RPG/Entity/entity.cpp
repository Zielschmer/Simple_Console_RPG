#include "entity.h"

Entity::Entity(CompSet& compset, ID& nextID) : m_ID(nextID), m_compset(compset) { nextID++; }

ID& Entity::getID() { return m_ID; }

CompSet& Entity::getCompset() {	return m_compset; }

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