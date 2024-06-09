#include "..\blueprint_list.h"

#include "..\blueprint.h"
#include "..\..\..\Components\comp_consumable.h"
#include "..\..\..\Components\comp_points-regen.h"
#include "..\..\..\Components\comp_equipable.h"
#include "..\..\..\Components\comp_attack.h"
#include "..\..\..\Components\comp_damage.h"
#include "..\..\..\Components\comp_defense.h"
#include "..\..\..\Components\comp_ammunition.h"
#include "..\..\..\Components\comp_ammo.h"
#include "..\..\..\Components\comp_throwable.h"
#include "..\..\..\Components\comp_cast-focus.h"
#include "..\..\..\Components\comp_conditions.h"

const ID createHealingPotion(const ID& ownerID) {

    Blueprint blueprint;

    //Register ConsumableComponent
    auto compConsumable = std::make_unique<CompConsumable>(ITEM_ID);
    compConsumable->m_target = TARGET_ALLY;
    blueprint.registerComponent(std::move(compConsumable));
    blueprint.addComponent(CONSUMABLE_COMP);

    //Register PointsRegenComponent
    auto compPointsRegen = std::make_unique<CompPointsRegen>(ITEM_ID);
    compPointsRegen->m_regenHP = 5u;
    compPointsRegen->m_regenSP = 0u;
    blueprint.registerComponent(std::move(compPointsRegen));
    blueprint.addComponent(POINTSREGEN_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Healing Potion", "Heals 5 HP");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createDart(const ID& ownerID) {

    Blueprint blueprint;

    //Register ConsumableComponent
    auto compConsumable = std::make_unique<CompConsumable>(ITEM_ID);
    compConsumable->m_target = TARGET_ENEMY;
    blueprint.registerComponent(std::move(compConsumable));
    blueprint.addComponent(CONSUMABLE_COMP);

    //Register Throwable Component
    auto compThrowable = std::make_unique<CompThrowable>(ITEM_ID);
    compThrowable->m_dmgDice = D4;
    compThrowable->m_dmgType = PIERCING;
    compThrowable->m_mod = FINESSE;
    compThrowable->m_range = 4u;
    blueprint.registerComponent(std::move(compThrowable));
    blueprint.addComponent(THROWABLE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Dart", "A throwable projetil");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createArrow(const ID& ownerID) {

    Blueprint blueprint;

    //Register ConsumableComponent
    auto compAmmo = std::make_unique<CompAmmo>(ITEM_ID);
    compAmmo->m_ammoType = AMMO_ARROW;
    blueprint.registerComponent(std::move(compAmmo));
    blueprint.addComponent(AMMO_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Arrow", "A quiver with arrows");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createBolt(const ID& ownerID) {

    Blueprint blueprint;

    //Register ConsumableComponent
    auto compAmmo = std::make_unique<CompAmmo>(ITEM_ID);
    compAmmo->m_ammoType = AMMO_BOLT;
    blueprint.registerComponent(std::move(compAmmo));
    blueprint.addComponent(AMMO_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Bolt", "A bag of bolts");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}