#pragma once

#include <vector>

#include "entity.h"
#include "..\..\..\lib\includes\monster.h"

//Entity and components Data Structures
extern std::vector<std::unique_ptr<Entity>> entityControl;
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

//Get components functions
Info& getInfoComponent(int componentID);
AbilityScore& getAbilityScoreComponent(int componentID);
int& getLevelComponent(int componentID);
HitPoints& getHitPointsComponent(int componentID);
SpellSlots& getSpellSlotsComponent(int componentID);
Armor& getArmorComponent(int componentID);
MainHand& getMainHandComponent(int componentID);
SecondHand& getSecondHandComponent(int componentID);
Cast& getCastComponent(int componentID);
NaturalArmor& getNaturalArmorComponent(int componentID);
NaturalWeapons& getNaturalWeaponsComponent(int componentID);

//Delete components functions
void deleteArmorComponent(int ownerID);
void deleteMainHandComponent(int ownerID);
void deleteSecondHandComponent(int ownerID);
void deleteCastComponent(int ownerID);