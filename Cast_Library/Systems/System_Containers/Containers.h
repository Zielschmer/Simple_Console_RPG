#ifndef SYSTEM_CONTAINER
#define SYSTEM_CONTAINER

#include "..\..\..\utilities\utils.h"

//Entity
CompSet& getCompSet(ID castID);
CastType& getType(ID castID);
std::string& getName(ID castID);
std::string& getDesc(ID castID);

//Component Casting
SP& getCost(ID castID);
TargetList& getTarget(ID castID);
Range& getRange(ID castID);
ScoreList& getMod(ID castID);
Turns& getTurns(ID castID);

//Component Upcast
uint16_t& getTimes(ID castID);
bool& getIsDmg(ID castID);
bool& getIsTargets(ID castID);

//Component Saving Throw
ScoreList& getSavScore(ID castID);
bool& getSavFail(ID castID);

//Component Damage
DiceList& getDmgDice(ID castID);
DamageList& getDmgType(ID castID);

//Component Healing
HP& getHeal(ID castID);
bool& getIsFull(ID castID);
bool& getIsRevive(ID castID);
std::vector<ConditionList>& getRmvCond(ID castID);

//Component Teleport
bool& getIsDungeon(ID castID);
bool& getIsPortal(ID castID);

//Component Conditions
std::vector<Condition>& getCond(ID castID);

//Component Range
Range& getRangedRange(ID castID);
ScoreList& getRangedMod(ID castID);

//Component Ricochet
Range& getRicochetRange(ID castID);
uint16_t& getRicochetTimes(ID castID);

#endif