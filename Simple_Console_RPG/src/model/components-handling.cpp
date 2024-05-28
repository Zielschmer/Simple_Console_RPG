#include <vector>

#include "includes\entity.h"
#include "..\..\lib\includes\monster.h"

extern std::vector<Info> infoComponents;
extern std::vector<AbilityScore> abilityScoreComponents;
extern std::vector<Armor> armorComponents;
extern std::vector<MainHand> mainHandComponents;
extern std::vector<SecondHand> secondHandComponents;
extern std::vector<Cast> castComponents;
extern std::vector<NaturalArmor> naturalArmorComponents;
extern std::vector<NaturalWeapons> naturalWeaponsComponents;


Info& getInfoComponent(int componentID) {
	for (int i = 0; i < infoComponents.size(); i++) {
		if (infoComponents[i].m_ownerID == componentID) {
			return infoComponents[i];
		}
	}
}

AbilityScore& getAbilityScoreComponent(int componentID) {
	for (int i = 0; i < abilityScoreComponents.size(); i++) {
		if (abilityScoreComponents[i].m_ownerID == componentID) {
			return abilityScoreComponents[i];
		}
	}
}

Armor& getArmorComponent(int componentID) {
	for (int i = 0; i < armorComponents.size(); i++) {
		if (armorComponents[i].m_ownerID == componentID) {
			return armorComponents[i];
		}
	}
}

MainHand& getMainHandComponent(int componentID) {
	for (int i = 0; i < mainHandComponents.size(); i++) {
		if (mainHandComponents[i].m_ownerID == componentID) {
			return mainHandComponents[i];
		}
	}
}

SecondHand& getSecondHandComponent(int componentID) {
	for (int i = 0; i < secondHandComponents.size(); i++) {
		if (secondHandComponents[i].m_ownerID == componentID) {
			return secondHandComponents[i];
		}
	}
}

Cast& getCastComponent(int componentID) {
	for (int i = 0; i < castComponents.size(); i++) {
		if (castComponents[i].m_ownerID == componentID) {
			return castComponents[i];
		}
	}
}

NaturalArmor& getNaturalArmorComponent(int componentID) {
	for (int i = 0; i < naturalArmorComponents.size(); i++) {
		if (naturalArmorComponents[i].m_ownerID == componentID) {
			return naturalArmorComponents[i];
		}
	}
}


NaturalWeapons& getNaturalWeaponsComponent(int componentID) {
	for (int i = 0; i < naturalWeaponsComponents.size(); i++) {
		if (naturalWeaponsComponents[i].m_ownerID == componentID) {
			return naturalWeaponsComponents[i];
		}
	}
}