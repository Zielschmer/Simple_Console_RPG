#include "weapon_blueprint.h"

#include "..\blueprint.h"
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
#include "..\..\Components\comp_conditions.h"

const ID createShortSword(const ID& ownerID) {

    Blueprint blueprint;

    //Register Attack Component
    auto compAttack = std::make_unique<CompAttack>(ITEM_ID);
    compAttack->m_range = 1u;
    compAttack->m_mod = FINESSE;
    blueprint.registerComponent(std::move(compAttack));
    blueprint.addComponent(ATTACK_COMP);

    //Register Damage Component
    auto compDamage = std::make_unique<CompDamage>(ITEM_ID);
    compDamage->m_dmgDice = D6;
    compDamage->m_dmgType = SLASHING;
    blueprint.registerComponent(std::move(compDamage));
    blueprint.addComponent(ITEM_DMG_COMP);

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = WEAPON;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Shortsword", "A small sword, very sharp");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createDagger(const ID& ownerID) {

    Blueprint blueprint;

    //Register Attack Component
    auto compAttack = std::make_unique<CompAttack>(ITEM_ID);
    compAttack->m_range = 1u;
    compAttack->m_mod = DEX;
    blueprint.registerComponent(std::move(compAttack));
    blueprint.addComponent(ATTACK_COMP);

    //Register Damage Component
    auto compDamage = std::make_unique<CompDamage>(ITEM_ID);
    compDamage->m_dmgDice = D4;
    compDamage->m_dmgType = SLASHING;
    blueprint.registerComponent(std::move(compDamage));
    blueprint.addComponent(ITEM_DMG_COMP);

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = WEAPON;
    compEquipable->m_light = true;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    //Register Throwable Component
    auto compThrowable = std::make_unique<CompThrowable>(ITEM_ID);
    compThrowable->m_dmgDice = D4;
    compThrowable->m_dmgType = PIERCING;
    compThrowable->m_mod = DEX;
    compThrowable->m_range = 4u;
    blueprint.registerComponent(std::move(compThrowable));
    blueprint.addComponent(THROWABLE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Dagger", "A battle knife loved by assassins and thiefs");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createMace(const ID& ownerID) {

    Blueprint blueprint;

    //Register Attack Component
    auto compAttack = std::make_unique<CompAttack>(ITEM_ID);
    compAttack->m_range = 1u;
    compAttack->m_mod = STR;
    blueprint.registerComponent(std::move(compAttack));
    blueprint.addComponent(ATTACK_COMP);

    //Register Damage Component
    auto compDamage = std::make_unique<CompDamage>(ITEM_ID);
    compDamage->m_dmgDice = D6;
    compDamage->m_dmgType = BLUDGEONING;
    blueprint.registerComponent(std::move(compDamage));
    blueprint.addComponent(ITEM_DMG_COMP);

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = WEAPON;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Mace", "The favorite bludgeoning weapon to deal with armor");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createHammer(const ID& ownerID) {

    Blueprint blueprint;

    //Register Attack Component
    auto compAttack = std::make_unique<CompAttack>(ITEM_ID);
    compAttack->m_range = 1u;
    compAttack->m_mod = STR;
    blueprint.registerComponent(std::move(compAttack));
    blueprint.addComponent(ATTACK_COMP);

    //Register Damage Component
    auto compDamage = std::make_unique<CompDamage>(ITEM_ID);
    compDamage->m_dmgDice = D8;
    compDamage->m_dmgType = BLUDGEONING;
    blueprint.registerComponent(std::move(compDamage));
    blueprint.addComponent(ITEM_DMG_COMP);

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = WEAPON;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = true;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Hammer", "The weapon for the biggest and the mighiests");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createShortBow(const ID& ownerID) {

    Blueprint blueprint;

    //Register Attack Component
    auto compAttack = std::make_unique<CompAttack>(ITEM_ID);
    compAttack->m_range = 16u;
    compAttack->m_mod = STR;
    blueprint.registerComponent(std::move(compAttack));
    blueprint.addComponent(ATTACK_COMP);

    //Register Damage Component
    auto compDamage = std::make_unique<CompDamage>(ITEM_ID);
    compDamage->m_dmgDice = D6;
    compDamage->m_dmgType = PIERCING;
    blueprint.registerComponent(std::move(compDamage));
    blueprint.addComponent(ITEM_DMG_COMP);

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = WEAPON;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = true;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    //Register Ammunition Component
    auto compAmmunition = std::make_unique<CompAmmunition>(ITEM_ID);
    compAmmunition->m_ammo = AMMO_ARROW;
    compAmmunition->m_loading = false;
    blueprint.registerComponent(std::move(compAmmunition));
    blueprint.addComponent(AMMUNITION_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Short Bow", "Rangers trustfull ally");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createStaff(const ID& ownerID) {

    Blueprint blueprint;

    //Register Attack Component
    auto compAttack = std::make_unique<CompAttack>(ITEM_ID);
    compAttack->m_range = 1u;
    compAttack->m_mod = STR;
    blueprint.registerComponent(std::move(compAttack));
    blueprint.addComponent(ATTACK_COMP);

    //Register Damage Component
    auto compDamage = std::make_unique<CompDamage>(ITEM_ID);
    compDamage->m_dmgDice = D1;
    compDamage->m_dmgType = BLUDGEONING;
    blueprint.registerComponent(std::move(compDamage));
    blueprint.addComponent(ITEM_DMG_COMP);

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = WEAPON;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    //Register CastFocus Component
    auto compCastFocus = std::make_unique<CompCastFocus>(ITEM_ID);
    compCastFocus->m_spell = true;
    compCastFocus->m_pray = false;
    compCastFocus->m_song = false;
    blueprint.registerComponent(std::move(compCastFocus));
    blueprint.addComponent(CAST_FOCUS_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Staff", "The way for casting powerfull weapons");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createRosary(const ID& ownerID) {

    Blueprint blueprint;

    //Register Attack Component
    auto compAttack = std::make_unique<CompAttack>(ITEM_ID);
    compAttack->m_range = 1u;
    compAttack->m_mod = STR;
    blueprint.registerComponent(std::move(compAttack));
    blueprint.addComponent(ATTACK_COMP);

    //Register Damage Component
    auto compDamage = std::make_unique<CompDamage>(ITEM_ID);
    compDamage->m_dmgDice = D1;
    compDamage->m_dmgType = BLUDGEONING;
    blueprint.registerComponent(std::move(compDamage));
    blueprint.addComponent(ITEM_DMG_COMP);

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = WEAPON;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    //Register CastFocus Component
    auto compCastFocus = std::make_unique<CompCastFocus>(ITEM_ID);
    compCastFocus->m_spell = false;
    compCastFocus->m_pray = true;
    compCastFocus->m_song = false;
    blueprint.registerComponent(std::move(compCastFocus));
    blueprint.addComponent(CAST_FOCUS_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Rosary", "The most powerfull weapon to the believers");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createHarp(const ID& ownerID) {

    Blueprint blueprint;

    //Register Attack Component
    auto compAttack = std::make_unique<CompAttack>(ITEM_ID);
    compAttack->m_range = 1u;
    compAttack->m_mod = STR;
    blueprint.registerComponent(std::move(compAttack));
    blueprint.addComponent(ATTACK_COMP);

    //Register Damage Component
    auto compDamage = std::make_unique<CompDamage>(ITEM_ID);
    compDamage->m_dmgDice = D1;
    compDamage->m_dmgType = BLUDGEONING;
    blueprint.registerComponent(std::move(compDamage));
    blueprint.addComponent(ITEM_DMG_COMP);

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = WEAPON;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = true;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    //Register CastFocus Component
    auto compCastFocus = std::make_unique<CompCastFocus>(ITEM_ID);
    compCastFocus->m_spell = false;
    compCastFocus->m_pray = false;
    compCastFocus->m_song = true;
    blueprint.registerComponent(std::move(compCastFocus));
    blueprint.addComponent(CAST_FOCUS_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Harp", "Let's make the battlefield groovy");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createShield(const ID& ownerID) {

    Blueprint blueprint;

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = SHIELD;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    //Register Defense Component
    auto compDefense = std::make_unique<CompDefense>(ITEM_ID);
    compDefense->m_AC = 2u;
    compDefense->m_mod = NOMOD;
    compDefense->m_heavy = false;
    blueprint.registerComponent(std::move(compDefense));
    blueprint.addComponent(DEFENSE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Shield", "The best attack is the defense?");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}