#include "Containers.h"

#include "..\..\Entity\item.h"
#include "..\..\Components\comp_consumable.h"
#include "..\..\Components\comp_points-regen.h"
#include "..\..\Components\comp_equipable.h"
#include "..\..\Components\comp_attack.h"
#include "..\..\Components\comp_damage.h"
#include "..\..\Components\comp_defense.h"
#include "..\..\Components\comp_ammunition.h"
#include "..\..\Components\comp_ammo.h"
#include "..\..\Components\comp_throwable.h"
#include "..\..\Components\comp_cast-focus.h"
#include "..\..\Components\comp_saving.h"
#include "..\..\Components\comp_conditions.h"

Container<Item_ptr> itemContainer;
Container<Consumable_ptr> consumableContainer;
Container<PointsRegen_ptr> pointsRegenContainer;
Container<Attack_ptr> attackContainer;
Container<Defense_ptr> defenseContainer;
Container<Equipable_ptr> equipableContainer;
Container<Damage_ptr> damageContainer;
Container<Ammunition_ptr> ammunitionContainer;
Container<Ammo_ptr> ammoContainer;
Container<Throwable_ptr> throwableContainer;
Container<CastFocus_ptr> castFocusContainer;
Container<Saving_ptr> savingContainer;
Container<Conditions_ptr> conditionsContainer;

CompSet& getCompSet(ID itemID) {
	auto it = itemContainer.find(itemID);
	return it->second->get_comp();
}
std::string& getName(ID itemID) {
	auto it = itemContainer.find(itemID);
	return it->second->get_name();
}
std::string& getDesc(ID itemID) {
	auto it = itemContainer.find(itemID);
	return it->second->get_desc();
}

//Component Consumable
TargetList& getConsumableTarget(ID itemID) {
	auto it = consumableContainer.find(itemID);
	return it->second.get()->m_target;
}

//Component Points Regen
HP& getHPRegen(ID itemID) {
	auto it = pointsRegenContainer.find(itemID);
	return it->second.get()->m_regenHP;
}
SP& getSPRegen(ID itemID) {
	auto it = pointsRegenContainer.find(itemID);
	return it->second.get()->m_regenSP;
}

//Component Attack
Range& getRange(ID itemID) {
	auto it = attackContainer.find(itemID);
	return it->second.get()->m_range;
}
ScoreList& getMod(ID itemID) {
	auto it = attackContainer.find(itemID);
	return it->second.get()->m_mod;
}

//Component Defense
AC& getAC(ID itemID) {
	auto it = defenseContainer.find(itemID);
	return it->second.get()->m_AC;
}
ScoreList& getDefMod(ID itemID) {
	auto it = defenseContainer.find(itemID);
	return it->second.get()->m_mod;
}
bool& getDefHeavy(ID itemID) {
	auto it = defenseContainer.find(itemID);
	return it->second.get()->m_heavy;
}
Weakness& getWeak(ID itemID) {
	auto it = defenseContainer.find(itemID);
	return it->second.get()->m_weak;
}
Resistance& getResist(ID itemID) {
	auto it = defenseContainer.find(itemID);
	return it->second.get()->m_resist;
}

//Component Equipable
bool& getEquiped(ID itemID) {
	auto it = equipableContainer.find(itemID);
	return it->second.get()->m_equiped;
}
EquipType& getType(ID itemID) {
	auto it = equipableContainer.find(itemID);
	return it->second.get()->m_type;
}
bool& getTwoHand(ID itemID) {
	auto it = equipableContainer.find(itemID);
	return it->second.get()->m_twoHand;
}
bool& getLight(ID itemID) {
	auto it = equipableContainer.find(itemID);
	return it->second.get()->m_light;
}
ScoreList& getWeaponMod(ID itemID) {
	auto it = attackContainer.find(itemID);
	return it->second.get()->m_mod;
}

//Component Damage
DiceList& getDmgDice(ID itemID) {
	auto it = damageContainer.find(itemID);
	return it->second.get()->m_dmgDice;
}
DamageList& getDmgType(ID itemID) {
	auto it = damageContainer.find(itemID);
	return it->second.get()->m_dmgType;
}

//Component Ammunition
AmmoList& getAmmo(ID itemID) {
	auto it = ammunitionContainer.find(itemID);
	return it->second.get()->m_ammo;
}
bool& getLoading(ID itemID) {
	auto it = ammunitionContainer.find(itemID);
	return it->second.get()->m_loading;
}

//Component Ammo
AmmoList& getAmmoType(ID itemID) {
	auto it = ammoContainer.find(itemID);
	return it->second.get()->m_ammoType;
}

//Component Throwable
DiceList& getThrowDmgDice(ID itemID) {
	auto it = throwableContainer.find(itemID);
	return it->second.get()->m_dmgDice;
}
DamageList& getThrowDmgType(ID itemID) {
	auto it = throwableContainer.find(itemID);
	return it->second.get()->m_dmgType;
}
ScoreList& getThrowMod(ID itemID) {
	auto it = throwableContainer.find(itemID);
	return it->second.get()->m_mod;
}
Range& getThrowRange(ID itemID) {
	auto it = throwableContainer.find(itemID);
	return it->second.get()->m_range;
}

//Component Cast Focus
bool& getSpellFocus(ID itemID) {
	auto it = castFocusContainer.find(itemID);
	return it->second->m_spell;
}
bool& getPrayFocus(ID itemID) {
	auto it = castFocusContainer.find(itemID);
	return it->second->m_pray;
}
bool& getSongFocus(ID itemID) {
	auto it = castFocusContainer.find(itemID);
	return it->second->m_song;
}

//Component Saving Throw
ScoreList& getSavScore(ID itemID) {
	auto it = savingContainer.find(itemID);
	return it->second->m_mod;
}
DC& getSavDC(ID itemID) {
	auto it = savingContainer.find(itemID);
	return it->second->m_DC;
}
bool& getSavFail(ID itemID) {
	auto it = savingContainer.find(itemID);
	return it->second->m_fail;
}

//Component Conditions
std::vector<Condition>& getConditions(ID itemID) {
	auto it = conditionsContainer.find(itemID);
	return it->second->m_conditions;
}