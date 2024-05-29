#include "includes\entity.h"

AbilityScore& getAbilityScoreComponent(int componentID);

Entity::Entity(std::string bitset, int& currentID) {
	m_id = currentID;
	currentID++;
	m_bitset = std::bitset<COMPONENTS_NUM>(bitset);
}

int Entity::getID() {
	return m_id;
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

int Entity::getModifier(int whatModifier) {

	if (this->m_bitset.test(0)) {
		int modifier = 0;
		switch (whatModifier)
		{
		case 1:
			modifier = floor(((getAbilityScoreComponent(this->m_id).m_strength - 10) / 2));
			break;
		case 2:
			modifier = floor(((getAbilityScoreComponent(this->m_id).m_dexterity - 10) / 2));
			break;
		case 3:
			modifier = floor(((getAbilityScoreComponent(this->m_id).m_constitution - 10) / 2));
			break;
		case 4:
			modifier = floor(((getAbilityScoreComponent(this->m_id).m_intelligence - 10) / 2));
			break;
		case 5:
			modifier = floor(((getAbilityScoreComponent(this->m_id).m_faith - 10) / 2));
			break;
		case 6:
			modifier = floor(((getAbilityScoreComponent(this->m_id).m_luck - 10) / 2));
			break;
		default:
			break;
		}
		return modifier;
	}

}