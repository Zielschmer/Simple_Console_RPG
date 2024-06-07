#include "cast.h"

Cast::Cast(ID& nextID, std::string compset) : m_id(nextID), m_compset(compset)  {}

ID& Cast::getID() { return m_id; }

CompSet& Cast::getCompset() { return m_compset; }