#pragma once

#include <math.h>

#include "entity.h"

std::vector<Info> infoComponents;
std::vector<AbilityScore> abilityScoreComponents;
std::vector<Armor> armorComponents;
std::vector<MainHand> mainHandComponents;
std::vector<SecondHand> secondHandComponents;
std::vector<Magic> magicComponents;

int pickScore(std::vector<int>& scoreOrder);

int calculateExtra(int& extraPoints);

Entity& characterCreation();

Info& getInfoComponent(int componentID);

AbilityScore& getAbilityScoreComponent(int componentID);

Armor& getArmorComponent(int componentID);

MainHand& getMainHandComponent(int componentID);

SecondHand& getSecondHandComponent(int componentID);

Magic& getMagicComponent(int componentID);