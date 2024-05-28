#pragma once

#include "entity.h"

std::vector<Info> infoComponents;
std::vector<AbilityScore> abilityScoreComponents;
std::vector<Armor> armorComponents;
std::vector<MainHand> mainHandComponents;
std::vector<SecondHand> secondHandComponents;
std::vector<Cast> castComponents;

Info& getInfoComponent(int componentID);

AbilityScore& getAbilityScoreComponent(int componentID);

Armor& getArmorComponent(int componentID);

MainHand& getMainHandComponent(int componentID);

SecondHand& getSecondHandComponent(int componentID);

Cast& getCastComponent(int componentID);