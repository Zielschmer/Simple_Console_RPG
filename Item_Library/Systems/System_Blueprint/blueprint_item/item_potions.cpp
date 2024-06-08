#include "..\blueprint_list.h"

#include "..\blueprint.h"
#include "..\..\Components\comp_consumable.h"
#include "..\..\Components\comp_points-regen.h"
#include "..\..\Components\comp_equipable.h"
#include "..\..\Components\comp_attack.h"
#include "..\..\Components\comp_damage.h"
#include "..\..\Components\comp_defense.h"
#include "..\..\Components\comp_ammunition.h"
#include "..\..\Components\comp_cast-focus.h"
#include "..\..\Components\comp_conditions.h"

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