#pragma once

#include <stdint.h>
#include <bitset>

#include "..\..\lib\includes\info.h"
#include "..\..\lib\includes\ability-score.h"
#include "..\..\lib\includes\armor.h"
#include "..\..\lib\includes\main-hand.h"
#include "..\..\lib\includes\second-hand.h"
#include "..\..\lib\includes\magic.h"

class Entity {

	int m_id;
	std::bitset<6> m_bitset;

public:
	Entity(std::string bitset, int& currentID);

	bool checkComponent(int i);
	void addComponent(int i);
	void removeComponent(int i);
	std::bitset<6>& checkBitset();
	int getID();

};