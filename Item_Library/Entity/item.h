#ifndef ITEM
#define ITEM

#include "..\utils.h"

class Item {
public:
	const ID m_ID;

	Item(ID& nextID, const ID& ownerID, CompSet& compSet, std::string name, std::string desc);
	void add_comp(ItemCompList comp);
	bool chk_comp(ItemCompList comp);
	std::string chk_name();
private:
	ID m_ownerID;
	CompSet m_compSet;
	std::string m_name;
	std::string m_desc;
};

using Item_ptr = std::unique_ptr<Item>;

#endif
