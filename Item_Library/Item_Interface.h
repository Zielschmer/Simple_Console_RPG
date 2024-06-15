#ifndef ITEM_INTERFACE
#define ITEM_INTERFACE

#include "..\..\..\utilities\utils.h"

//Entity 
CompSet chkComponent(ID itemID, ItemCompList comp);
std::string chkItemName(ID itemID);
std::string chkItemDesc(ID itemID);

//Component Consumable
TargetList chkConsumableTarget(ID itemID);

//Component Points Regen
HP chkHPRegen(ID itemID);
SP chkSPRegen(ID itemID);

//Component Attack
Range chkRange(ID itemID);
ScoreList chkMod(ID itemID);

//Component Defense
AC chkAC(ID itemID);
ScoreList chkDefMod(ID itemID);
bool chkDefHeavy(ID itemID);
Weakness chkWeak(ID itemID);
Resistance chkResist(ID itemID);

//Component Equipable
bool chkEquiped(ID itemID);
EquipType chkType(ID itemID);
bool chkTwoHand(ID itemID);
bool chkLight(ID itemID);
ScoreList chkWeaponMod(ID itemID);

//Component Damage
DiceList chkDmgDice(ID itemID);
DamageList chkDmgType(ID itemID);

//Component Ammunition
AmmoList chkAmmo(ID itemID);
bool chkLoading(ID itemID);

//Component Ammo
AmmoList chkAmmoType(ID itemID);

//Component Throwable
DiceList chkThrowDmgDice(ID itemID);
DamageList chkThrowDmgType(ID itemID);
ScoreList chkThrowMod(ID itemID);
Range chkThrowRange(ID itemID);

//Component Cast Focus
bool chkSpellFocus(ID itemID);
bool chkPrayFocus(ID itemID);
bool chkSongFocus(ID itemID);

//Component Saving Throw
ScoreList chkSavScore(ID itemID);
DC chkSavDC(ID itemID);
bool chkSavFail(ID itemID);

//Component Conditions
std::vector<Condition> chkConditions(ID itemID);

ID getWeapon(ID ownerID, WeaponList weapon);
ID getArmor(ID ownerID, ArmorList armor);
ID getConsumable(ID ownerID, ConsumableList consumable);

#endif
