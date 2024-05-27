#include "includes\entity.h"

Entity::Entity(std::string bitset, int& currentID) {
	m_id = currentID;
	currentID++;
	m_bitset = std::bitset<6>(bitset);
}

bool Entity::checkComponent(int i) {
	return m_bitset[i];
}

void Entity::addComponent(int i) {
	m_bitset[i] = 1;
}

void Entity::removeComponent(int i) {
	m_bitset[i] = 0;
}

std::bitset<6>& Entity::checkBitset() {
	return m_bitset;
}

int Entity::getID() {
	return m_id;
}