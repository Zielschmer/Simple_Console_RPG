#ifndef SYSTEM_ITEM_CONTAINER
#define SYSTEM_ITEM_CONTAINER

#include "..\..\..\utilities\utils.h"

//Entity 
CompSet& getCompSet(ID itemID);
std::string& getName(ID itemID);
std::string& getDesc(ID itemID);

//Component Consumable
TargetList& getConsumableTarget(ID itemID);

//Component Points Regen
HP& getHPRegen(ID itemID);
SP& getSPRegen(ID itemID);

//Component Attack
Range& getRange(ID itemID);
ScoreList& getMod(ID itemID);

//Component Defense
AC& getAC(ID itemID);
ScoreList& getDefMod(ID itemID);
bool& getDefHeavy(ID itemID);
Weakness& getWeak(ID itemID);
Resistance& getResist(ID itemID);

//Component Equipable
bool& getEquiped(ID itemID);
EquipType& getType(ID itemID);
bool& getTwoHand(ID itemID);
bool& getLight(ID itemID);
ScoreList& getWeaponMod(ID itemID);

//Component Damage
DiceList& getDmgDice(ID itemID);
DamageList& getDmgType(ID itemID);

//Component Ammunition
AmmoList& getAmmo(ID itemID);
bool& getLoading(ID itemID);

//Component Ammo
AmmoList& getAmmoType(ID itemID);

//Component Throwable
DiceList& getThrowDmgDice(ID itemID);
DamageList& getThrowDmgType(ID itemID);
ScoreList& getThrowMod(ID itemID);
Range& getThrowRange(ID itemID);

//Component Cast Focus
bool& getSpellFocus(ID itemID);
bool& getPrayFocus(ID itemID);
bool& getSongFocus(ID itemID);

//Component Saving Throw
ScoreList& getSavScore(ID itemID);
DC& getSavDC(ID itemID);
bool& getSavFail(ID itemID);

//Component Conditions
std::vector<Condition>& getConditions(ID itemID);

#endif