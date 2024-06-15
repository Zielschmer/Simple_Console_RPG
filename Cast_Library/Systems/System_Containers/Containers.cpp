#include "Containers.h"

#include "..\..\Entity\cast.h"
#include "..\..\Components\comp_casting.h"
#include "..\..\Components\comp_upcast.h"
#include "..\..\Components\comp_saving.h"
#include "..\..\Components\comp_damage.h"
#include "..\..\Components\comp_healing.h"
#include "..\..\Components\comp_teleport.h"
#include "..\..\Components\comp_conditions.h"
#include "..\..\Components\comp_range.h"
#include "..\..\Components\comp_ricochet.h"

Container<Cast_ptr> castContainer;
Container<Casting_ptr> castingContainer;
Container<Upcast_ptr> upcastContainer;
Container<Saving_ptr> savingContainer;
Container<Damage_ptr> damageContainer;
Container<Healing_ptr> healingContainer;
Container<Teleport_ptr> teleportContainer;
Container<Conditions_ptr> conditionsContainer;
Container<Range_ptr> rangeContainer;
Container<Ricochet_ptr> ricochetContainer;

//Entity
CompSet& getCompSet(ID castID) {
	auto it = castContainer.find(castID);
	return it->second->get_comp();
}
CastType getCastType(ID castID) {
	auto it = castContainer.find(castID);
	return it->second->m_type;
}
std::string& getName(ID castID) {
	auto it = castContainer.find(castID);
	return it->second->get_name();
}
std::string& getDesc(ID castID) {
	auto it = castContainer.find(castID);
	return it->second->get_desc();
}

//Component Casting
SP& getCost(ID castID) {
	auto it = castingContainer.find(castID);
	return it->second->m_cost;
}
TargetList& getTarget(ID castID) {
	auto it = castingContainer.find(castID);
	return it->second->m_target;
}
Range& getRange(ID castID) {
	auto it = castingContainer.find(castID);
	return it->second->m_range;
}
ScoreList& getMod(ID castID) {
	auto it = castingContainer.find(castID);
	return it->second->m_mod;
}
Turns& getTurns(ID castID) {
	auto it = castingContainer.find(castID);
	return it->second->m_turns;
}

//Component Upcast
uint16_t& getTimes(ID castID) {
	auto it = upcastContainer.find(castID);
	return it->second->m_times;
}
bool& getIsDmg(ID castID) {
	auto it = upcastContainer.find(castID);
	return it->second->m_damage;
}
bool& getIsTargets(ID castID) {
	auto it = upcastContainer.find(castID);
	return it->second->m_targets;
}

//Component Saving Throw
ScoreList& getSavScore(ID castID) {
	auto it = savingContainer.find(castID);
	return it->second->m_mod;
}
bool& getSavFail(ID castID) {
	auto it = savingContainer.find(castID);
	return it->second->m_fail;
}

//Component Damage
DiceList& getDmgDice(ID castID) {
	auto it = damageContainer.find(castID);
	return it->second->m_dmgDice;
}
DamageList& getDmgType(ID castID) {
	auto it = damageContainer.find(castID);
	return it->second->m_dmgType;
}

//Component Healing
HP& getHeal(ID castID) {
	auto it = healingContainer.find(castID);
	return it->second->m_regenHP;
}
bool& getIsFull(ID castID) {
	auto it = healingContainer.find(castID);
	return it->second->m_full;
}
bool& getIsRevive(ID castID) {
	auto it = healingContainer.find(castID);
	return it->second->m_revive;
}
std::vector<ConditionList>& getRmvCond(ID castID) {
	auto it = healingContainer.find(castID);
	return it->second->m_remove;
}

//Component Teleport
bool& getIsDungeon(ID castID) {
	auto it = teleportContainer.find(castID);
	return it->second->m_dugeon;
}
bool& getIsPortal(ID castID) {
	auto it = teleportContainer.find(castID);
	return it->second->m_portal;
}

//Component Conditions
std::vector<Condition>& getCond(ID castID) {
	auto it = conditionsContainer.find(castID);
	return it->second->m_conditions;
}

//Component Range
Range& getRangedRange(ID castID) {
	auto it = rangeContainer.find(castID);
	return it->second->m_range;
}
ScoreList& getRangedMod(ID castID) {
	auto it = rangeContainer.find(castID);
	return it->second->m_mod;
}

//Component Ricochet
Range& getRicochetRange(ID castID) {
	auto it = ricochetContainer.find(castID);
	return it->second->m_range;
}
uint16_t& getRicochetTimes(ID castID) {
	auto it = ricochetContainer.find(castID);
	return it->second->m_times;
}