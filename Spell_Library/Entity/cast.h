#ifndef CAST
#define CAST

#include "..\utils.h"

class Cast {
public:
	Cast(ID& nextID, std::string compset);
	ID& getID();
	CompSet& getCompset();
private:
	ID m_id;
	CompSet m_compset;
};

#endif
