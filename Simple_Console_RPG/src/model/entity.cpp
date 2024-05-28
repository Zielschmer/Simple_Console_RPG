#include "includes\entity.h"

Entity::Entity(std::string bitset, int& currentID) {
	m_id = currentID;
	currentID++;
	m_bitset = std::bitset<COMPONENTS_NUM>(bitset);
}

bool Entity::checkComponent(int i) {
	return m_bitset.test(i);
}

void Entity::addComponent(int i) {
	m_bitset.set(i);
}

void Entity::removeComponent(int i) {
	m_bitset.reset(i);
}

std::bitset<COMPONENTS_NUM>& Entity::checkBitset() {
	return m_bitset;
}

int Entity::getID() {
	return m_id;
}