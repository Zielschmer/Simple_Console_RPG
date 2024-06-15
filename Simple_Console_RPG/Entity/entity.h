#ifndef ENTITY
#define ENTITY

#include <memory>

#include "..\..\..\utilities\utils.h"

class Entity {
public:
	Entity(ID& nextID, CompSet& compset);

	const ID m_ID;
	bool chk_comp(CompList compList);
	bool add_comp(CompList compList);
	bool rmv_comp(CompList compList);
private:
	CompSet m_compset;
};

using Entity_ptr = std::unique_ptr<Entity>;

#endif