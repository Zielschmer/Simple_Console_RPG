#include "nat-weapon_blueprint.h"

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

const ID createBite(const ID& ownerID) {

    Blueprint blueprint;

    //Register Attack Component
    auto compAttack = std::make_unique<CompAttack>(ITEM_ID);
    compAttack->m_range = 1u;
    compAttack->m_mod = NOMOD;
    blueprint.registerComponent(std::move(compAttack));
    blueprint.addComponent(ATTACK_COMP);

    //Register Damage Component
    auto compDamage = std::make_unique<CompDamage>(ITEM_ID);
    compDamage->m_dmgDice = D1;
    compDamage->m_dmgType = PIERCING;
    blueprint.registerComponent(std::move(compDamage));
    blueprint.addComponent(ITEM_DMG_COMP);

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = NATWEAPON;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Bite", "A small animal bite");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createSting(const ID& ownerID) {

    Blueprint blueprint;

    //Register Attack Component
    auto compAttack = std::make_unique<CompAttack>(ITEM_ID);
    compAttack->m_range = 1u;
    compAttack->m_mod = NOMOD;
    blueprint.registerComponent(std::move(compAttack));
    blueprint.addComponent(ATTACK_COMP);

    //Register Damage Component
    auto compDamage = std::make_unique<CompDamage>(ITEM_ID);
    compDamage->m_dmgDice = D1;
    compDamage->m_dmgType = PIERCING;
    blueprint.registerComponent(std::move(compDamage));
    blueprint.addComponent(ITEM_DMG_COMP);

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = NATWEAPON;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    //Register Saving Component
    auto compSaving = std::make_unique<CompSaving>(ITEM_ID);
    compSaving->m_mod = CON;
    compSaving->m_DC = 9;
    compSaving->m_fail = true;
    blueprint.registerComponent(std::move(compSaving));
    blueprint.addComponent(ITEM_SVG_COMP);

    //Register Conditions Component
    auto compConditions = std::make_unique<CompConditions>(ITEM_ID);
    Condition poisoned;
    poisoned.m_name = POISONED;
    poisoned.m_turns = 3;
    compConditions->m_conditions.emplace_back(poisoned);
    blueprint.registerComponent(std::move(compConditions));
    blueprint.addComponent(ITEM_COND_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Sting", "Might get you poisoned");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}