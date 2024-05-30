#include <vector>

#include "includes\entity.h"
#include "..\..\lib\includes\monster.h"

extern std::vector<std::unique_ptr<Info>> infoComponents;
extern std::vector<std::unique_ptr<AbilityScore>> abilityScoreComponents;
extern std::vector<std::unique_ptr<int>> levelComponents;
extern std::vector<std::unique_ptr<HitPoints>> hitPointsComponents;
extern std::vector<std::unique_ptr<SpellSlots>> spellSlotsComponents;
extern std::vector<std::unique_ptr<Armor>> armorComponents;
extern std::vector<std::unique_ptr<MainHand>> mainHandComponents;
extern std::vector<std::unique_ptr<SecondHand>> secondHandComponents;
extern std::vector<std::unique_ptr<Cast>> castComponents;
extern std::vector<std::unique_ptr<NaturalArmor>> naturalArmorComponents;
extern std::vector<std::unique_ptr<NaturalWeapons>> naturalWeaponsComponents;


Info& getInfoComponent(int componentID) {
	for (int i = 0; i < infoComponents.size(); i++) {
		if (infoComponents[i]->m_ownerID == componentID) {
			return *infoComponents[i];
		}
	}
}

AbilityScore& getAbilityScoreComponent(int componentID) {
	for (int i = 0; i < abilityScoreComponents.size(); i++) {
		if (abilityScoreComponents[i]->m_ownerID == componentID) {
			return *abilityScoreComponents[i];
		}
	}
}

int& getLevelComponent(int componentID) {
	int i = 0;
	return *levelComponents[i];
}

HitPoints& getHitPointsComponent(int componentID) {
	for (int i = 0; i < hitPointsComponents.size(); i++) {
		if (hitPointsComponents[i]->m_ownerID == componentID) {
			return *hitPointsComponents[i];
		}
	}
}

SpellSlots& getSpellSlotsComponent(int componentID) {
	for (int i = 0; i < spellSlotsComponents.size(); i++) {
		if (spellSlotsComponents[i]->m_ownerID == componentID) {
			return *spellSlotsComponents[i];
		}
	}
}

Armor& getArmorComponent(int componentID) {
	for (int i = 0; i < armorComponents.size(); i++) {
		if (armorComponents[i]->m_ownerID == componentID) {
			return *armorComponents[i];
		}
	}
}

MainHand& getMainHandComponent(int componentID) {
	for (int i = 0; i < mainHandComponents.size(); i++) {
		if (mainHandComponents[i]->m_ownerID == componentID) {
			return *mainHandComponents[i];
		}
	}
}

SecondHand& getSecondHandComponent(int componentID) {
	for (int i = 0; i < secondHandComponents.size(); i++) {
		if (secondHandComponents[i]->m_ownerID == componentID) {
			return *secondHandComponents[i];
		}
	}
}

Cast& getCastComponent(int componentID) {
	for (int i = 0; i < castComponents.size(); i++) {
		if (castComponents[i]->m_ownerID == componentID) {
			return *castComponents[i];
		}
	}
}

NaturalArmor& getNaturalArmorComponent(int componentID) {
	for (int i = 0; i < naturalArmorComponents.size(); i++) {
		if (naturalArmorComponents[i]->m_ownerID == componentID) {
			return *naturalArmorComponents[i];
		}
	}
}


NaturalWeapons& getNaturalWeaponsComponent(int componentID) {
	for (int i = 0; i < naturalWeaponsComponents.size(); i++) {
		if (naturalWeaponsComponents[i]->m_ownerID == componentID) {
			return *naturalWeaponsComponents[i];
		}
	}
}

void deleteArmorComponent(int ownerID) {
	for (auto it = armorComponents.begin(); it != armorComponents.end(); it++) {
		if (it->get()->m_ownerID == ownerID) {
			armorComponents.erase(it);
			return;
		}
	}
}

void deleteMainHandComponent(int ownerID) {
	for (auto it = mainHandComponents.begin(); it != mainHandComponents.end(); it++) {
		if (it->get()->m_ownerID == ownerID) {
			mainHandComponents.erase(it);
			return;
		}
	}
}

void deleteSecondHandComponent(int ownerID) {
	for (auto it = secondHandComponents.begin(); it != secondHandComponents.end(); it++) {
		if (it->get()->m_ownerID == ownerID) {
			secondHandComponents.erase(it);
			return;
		}
	}
}

void deleteCastComponent(int ownerID) {
	for (auto it = castComponents.begin(); it != castComponents.end(); it++) {
		if (it->get()->m_ownerID == ownerID) {
			castComponents.erase(it);
			return;
		}
	}
}