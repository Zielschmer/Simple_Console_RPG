#pragma once

#include "entity.h"

std::vector<Info> infoComponents;
std::vector<AbilityScore> abilityScoreComponents;
std::vector<Armor> armorComponents;
std::vector<MainHand> mainHandComponents;
std::vector<SecondHand> secondHandComponents;
std::vector<Magic> magicComponents;

Info& getInfoComponent(int componentID);

AbilityScore& getAbilityScoreComponent(int componentID);

Armor& getArmorComponent(int componentID);

MainHand& getMainHandComponent(int componentID);

SecondHand& getSecondHandComponent(int componentID);

Magic& getMagicComponent(int componentID);