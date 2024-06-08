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
    compDamage->m_dmgDice = D4;
    compDamage->m_dmgType = SLASHING;
    blueprint.registerComponent(std::move(compDamage));
    blueprint.addComponent(DAMAGE_COMP);

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(ITEM_ID);
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));
    blueprint.addComponent(EQUIPABLE_COMP);

    Item_ptr item = blueprint.instantiateItem(ownerID, "Shortsword", "A small sword, very sharp");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}