#ifndef CAST
#define CAST

#include "..\..\..\utilities\utils.h"

class Cast {
public:
	const ID m_ID;
	const CastType m_type;

	Cast(ID& nextID, const ID& ownerID, CompSet& compSet, CastType type, std::string name, std::string desc);
	CompSet& get_comp();
	std::string& get_name();
	std::string& get_desc();
private:
	ID m_ownerID;
	CompSet m_compSet;
	std::string m_name;
	std::string m_desc;
};

using Cast_ptr = std::unique_ptr<Cast>;

#endif
