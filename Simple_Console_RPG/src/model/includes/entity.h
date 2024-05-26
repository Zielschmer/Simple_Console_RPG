#pragma once

#include <stdint.h>
#include <bitset>

static uint16_t currentID = 0;

class Entity {

	uint16_t m_id;
	std::bitset<20> m_bitset;

public:
	Entity(std::bitset<20> bitset);

	bool checkComponent(int i);
	void addComponent(int i);
	void removeComponent(int i);

};