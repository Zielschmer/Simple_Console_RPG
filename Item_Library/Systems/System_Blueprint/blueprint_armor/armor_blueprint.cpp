#include "armor_blueprint.h"

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

const ID createRobe(const ID& ownerID) {

    Blueprint blueprint;

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = ARMOR;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    //Register Defense Component
    auto compDefense = std::make_unique<CompDefense>(ITEM_ID);
    compDefense->m_AC = 8u;
    compDefense->m_mod = NOMOD;
    compDefense->m_heavy = false;
    blueprint.registerComponent(std::move(compDefense));
    blueprint.addComponent(DEFENSE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Robe", "Light for the casters");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createLeatherArmor(const ID& ownerID) {

    Blueprint blueprint;

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = ARMOR;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    //Register Defense Component
    auto compDefense = std::make_unique<CompDefense>(ITEM_ID);
    compDefense->m_AC = 10u;
    compDefense->m_mod = DEX;
    compDefense->m_heavy = false;
    blueprint.registerComponent(std::move(compDefense));
    blueprint.addComponent(DEFENSE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Leather Armor", "The perfect armor to move around");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createRingMail(const ID& ownerID) {

    Blueprint blueprint;

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = ARMOR;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    //Register Defense Component
    auto compDefense = std::make_unique<CompDefense>(ITEM_ID);
    compDefense->m_AC = 12u;
    compDefense->m_mod = NOMOD;
    compDefense->m_heavy = false;
    blueprint.registerComponent(std::move(compDefense));
    blueprint.addComponent(DEFENSE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Ring Mail", "Starting to getting heavy");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}

const ID createChainMail(const ID& ownerID) {

    Blueprint blueprint;

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_type = ARMOR;
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    //Register Defense Component
    auto compDefense = std::make_unique<CompDefense>(ITEM_ID);
    compDefense->m_AC = 12u;
    compDefense->m_mod = CON;
    compDefense->m_heavy = true;
    blueprint.registerComponent(std::move(compDefense));
    blueprint.addComponent(DEFENSE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Chain Mail", "A mobile(?) fortress");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}