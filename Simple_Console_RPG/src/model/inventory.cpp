#include "includes\inventory.h"

bool Inventory::buyPotion(int howMany) {
	if (howMany * 50 < m_coins) {
		m_potions += howMany;
		m_coins -= howMany * 50;
		return true;
	}
	return false;
}

bool Inventory::buyArrows(int howMany) {
	if (howMany * 10 < m_coins) {
		m_arrows += howMany * 20;
		m_coins -= howMany * 10;
		return true;
	}
	return false;
}

bool Inventory::buyDarts(int howMany) {
	if (howMany < m_coins) {
		m_darts += howMany * 2;
		m_coins -= howMany;
		return true;
	}
	return false;
}

int Inventory::checkPotion() {
	return m_potions;
}
int Inventory::checkArrows() {
	return m_arrows;
}
int Inventory::checkDarts() {
	return m_darts;
}
int Inventory::checkCoins() {
	return m_coins;
}

void Inventory::usePotion() {
	m_potions--;
}

bool Inventory::useArrow() {
	if (m_arrows > 0) {
		m_arrows--;
		return true;
	}
	return false;
}

void Inventory::useDart() {
	m_darts--;
}