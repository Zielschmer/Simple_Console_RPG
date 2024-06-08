#include "..\blueprint_list.h"

const ID& createHealingPotion(ID& nextID, const ID& ownerID) {

    Blueprint blueprint;

    //Register ConsumableComponent
    auto compConsumable = std::make_unique<CompConsumable>(nextID);
    compConsumable->m_target = TARGET_ALLY;
    blueprint.registerComponent(std::move(compConsumable));

    //Register PointsRegenComponent
    auto compPointsRegen = std::make_unique<CompPointsRegen>(nextID);
    compPointsRegen->m_regenHP = 5u;
    compPointsRegen->m_regenSP = 0u;
    blueprint.registerComponent(std::move(compPointsRegen));

    Item_ptr item = blueprint.instantiateItem(nextID, ownerID, "Healing Potion", "Heals 5 HP");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}