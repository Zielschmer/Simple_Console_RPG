#include "generate_components.h"
#include "..\System_Containers\Containers.h"

#include "..\..\..\Item_Library\Item_Interface.h"
#include "..\..\..\Cast_Library\Cast_Interface.h"

Cast_ptr generateCast(ID entityID) {
	Cast_ptr newCast(new CompCast(entityID));
	if (getItemName(getComponent<CompMainHand>(entityID, MAINHAND)->m_weapon) == "Staff") {
		newCast->m_spells.emplace_back(createAcidSplash(entityID));
	}
	else if (getItemName(getComponent<CompMainHand>(entityID, MAINHAND)->m_weapon) == "Rosary") {

	}
	else if (getItemName(getComponent<CompMainHand>(entityID, MAINHAND)->m_weapon) == "Harp") {
		
	}

	if (testComponent(entityID, OFFHAND)) {
		if (getItemName(getComponent<CompMainHand>(entityID, MAINHAND)->m_weapon) == "Staff") {
			
		}
		else if (getItemName(getComponent<CompMainHand>(entityID, MAINHAND)->m_weapon) == "Rosary") {
			
		}
	}

	return std::move(newCast);
}