#include "includes\equip_pray.h"

#include "includes\system_components.h"

bool chkPray(ID entityID, PrayList pray) {

	for (auto member : getCastComp(entityID)->m_prays) {
		if (member.m_name == prayLibrary(pray)) {
			return false;
		}
		return true;
	}

}

void equipPray(Entity& entity, PrayList pray) {

	if (getRHandComp(entity.getID())->m_name == "Rosary" ||
		getLHandComp(entity.getID())->m_name == "Rosary")
	{
		if (chkPray(entity.getID(), pray)) {
			getCastComp(entity.getID())->m_prays.emplace_back(getPray(pray));
		}
	}

}