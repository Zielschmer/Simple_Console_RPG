#include "includes\lib_entity.h"

Entity::Entity(CompSet& compSet, ID& nextID) {
	m_ID = nextID;
	nextID++;
	m_comp = compSet;
}

int Entity::getID() {
	return m_ID;
}

CompSet& Entity::getCompSet() {
	return m_comp;
}

bool Entity::chk_comp(CompList compList) {
	return m_comp.test(compList);
}

bool Entity::add_comp(CompList compList) {
	m_comp.set(compList);
	return true;
}

bool Entity::rmv_comp(CompList compList) {
	m_comp.reset(compList);
	return true;
}