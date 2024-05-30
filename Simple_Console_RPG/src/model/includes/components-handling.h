#pragma once

#include "entity.h"
#include "..\..\..\lib\includes\monster.h"

std::vector<std::unique_ptr<Entity>> entityControl;

std::vector<std::unique_ptr<Info>> infoComponents;
std::vector<std::unique_ptr<AbilityScore>> abilityScoreComponents;
std::vector<std::unique_ptr<int>> levelComponents;
std::vector<std::unique_ptr<HitPoints>> hitPointsComponents;
std::vector<std::unique_ptr<SpellSlots>> spellSlotsComponents;
std::vector<std::unique_ptr<Armor>> armorComponents;
std::vector<std::unique_ptr<MainHand>> mainHandComponents;
std::vector<std::unique_ptr<SecondHand>> secondHandComponents;
std::vector<std::unique_ptr<Cast>> castComponents;
std::vector<std::unique_ptr<NaturalArmor>> naturalArmorComponents;
std::vector<std::unique_ptr<NaturalWeapons>> naturalWeaponsComponents;

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