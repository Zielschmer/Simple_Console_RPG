#include "healing_potion.h"

#include "..\Components\comp_consumable.h"
#include "..\Components\comp_points-regen.h"

Blueprint createHealingPotion() {
    Blueprint blueprint;

    // Add WeaponComponent
    auto compConsumable = std::make_shared<CompConsumable>();
    compConsumable->m_target = TARGET_ALLY;
    compConsumable->m_range = 3u;
    blueprint.registerComponent(compConsumable, CompList::CONSUMABLE_COMP);

    // register ArmorComponent
    auto compPointsRegen = std::make_shared<CompPointsRegen>();
    compPointsRegen->m_regenHP = 5u;
    compPointsRegen->m_regenSP = 0u;
    blueprint.registerComponent(compPointsRegen, CompList::POINTSREGEN_COMP);

    return blueprint;
}