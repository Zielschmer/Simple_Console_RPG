#include "includes\entity.h"

Entity::Entity(std::bitset<20> bitset) {
	m_id = currentID;
	currentID++;
	m_bitset = bitset;
}

bool Entity::checkComponent(int i) {
	return m_bitset[i];
}

void Entity::addComponent(int i) {
	m_bitset[1] = 1;
}

void Entity::removeComponent(int i) {
	m_bitset[1] = 0;
}
