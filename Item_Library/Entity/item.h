#ifndef ITEM
#define ITEM

#include "..\..\..\utilities\utils.h"

class Item {
public:
	const ID m_ID;

	Item(ID& nextID, const ID& ownerID, CompSet& compSet, std::string name, std::string desc);
	CompSet& get_comp();
	std::string& get_name();
	std::string& get_desc();
private:
	ID m_ownerID;
	CompSet m_compSet;
	std::string m_name;
	std::string m_desc;
};

using Item_ptr = std::unique_ptr<Item>;

#endif
