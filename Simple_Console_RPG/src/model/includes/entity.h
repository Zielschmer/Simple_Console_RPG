#pragma once

#include <stdint.h>
#include <bitset>

#include "..\..\lib\includes\info.h"
#include "..\..\lib\includes\ability-score.h"
#include "..\..\lib\includes\armor.h"
#include "..\..\lib\includes\main-hand.h"
#include "..\..\lib\includes\second-hand.h"
#include "..\..\lib\includes\cast.h"

#define COMPONENTS_NUM 8

class Entity {

	int m_id;
	std::bitset<COMPONENTS_NUM> m_bitset;

public:
	Entity(std::string bitset, int& currentID);
	Entity() {};

	bool checkComponent(int i);
	void addComponent(int i);
	void removeComponent(int i);
	std::bitset<COMPONENTS_NUM>& checkBitset();
	int getID();

};