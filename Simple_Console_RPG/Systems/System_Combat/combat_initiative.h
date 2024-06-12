#ifndef COMBAT_INITIATIVE
#define COMBAT_INITIATIVE

#include "..\..\utils.h"

extern std::vector<Roll> turnOrder;

void getInitative(Party& partyID, Party& enemiesID);

#endif