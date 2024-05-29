#pragma once

#include "entity.h"
#include "..\..\..\lib\includes\monster.h"

std::vector<Entity> entityControl;

std::vector<Info> infoComponents;
std::vector<AbilityScore> abilityScoreComponents;
std::vector<int> levelComponents;
std::vector<HitPoints> hitPointsComponents;
std::vector<SpellSlots> spellSlotsComponents;
std::vector<Armor> armorComponents;
std::vector<MainHand> mainHandComponents;
std::vector<SecondHand> secondHandComponents;
std::vector<Cast> castComponents;
std::vector<NaturalArmor> naturalArmorComponents;
std::vector<NaturalWeapons> naturalWeaponsComponents;

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