#ifndef CAST
#define CAST

#include "..\utils.h"

class Cast {
public:
	const ID m_ID;
	const CastType m_type;

	Cast(ID& nextID, const ID& ownerID, CompSet& compSet, CastType type, std::string name, std::string desc);
	void add_comp(CastCompList comp);
	bool chk_comp(CastCompList comp);
	std::string chk_name();
private:
	ID m_ownerID;
	CompSet m_compSet;
	std::string m_name;
	std::string m_desc;
};

using Cast_ptr = std::unique_ptr<Cast>;

#endif
