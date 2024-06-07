#ifndef ENTITY
#define ENTITY

#include <memory>

#include "..\utils.h"

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
public:
	Entity(CompSet& compset, ID& nextID);
	ID& getID();
	CompSet& getCompset();
	bool chk_comp(CompList compList);
	bool add_comp(CompList compList);
	bool rmv_comp(CompList compList);
private:
	ID m_ID;
	CompSet m_compset;
};

using Entity_ptr = std::unique_ptr<Entity>;

#endif