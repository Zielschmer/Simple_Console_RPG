#ifndef ITEM
#define ITEM

#include "..\utils.h"

class Item {
public:
	Item(ID& nextID, std::string name, std::string desc, std::string compset);
	ID& getID();
	std::string& getName();
	std::string& getDesc();
	bool chk_comp(CompList comp);
	bool add_comp(CompList comp);
private:
	ID m_ID;
	std::string m_name;
	std::string m_desc;
	CompSet m_compset;
};

#endif
