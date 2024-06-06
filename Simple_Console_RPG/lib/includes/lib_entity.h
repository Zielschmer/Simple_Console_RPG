#pragma once

#include <memory>

#include "lib_primitives.h"

enum CompList {

	SCORE,
	INFO,
	LEVEL,
	POINTS,
	STATS,
	ARMOR,
	RHAND,
	LHAND,
	CAST,
	NAT_ARMOR,
	NAT_WEAPON

};

class Entity {

	ID m_ID;
	CompSet m_comp;

public:
	Entity(CompSet& compSet, ID& nextID);
	Entity() {};

	int getID();

	CompSet& getCompSet();
	bool chk_comp(CompList compList);
	bool add_comp(CompList compList);
	bool rmv_comp(CompList compList);

};

typedef std::unique_ptr<Entity> Entity_ptr;