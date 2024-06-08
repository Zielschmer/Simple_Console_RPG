#include "..\blueprint_list.h"

const ID& createShortSword(ID& nextID, const ID& ownerID) {

    Blueprint blueprint;

    //Register Attack Component
    auto compAttack = std::make_unique<CompAttack>(nextID);
    compAttack->m_range = 1u;
    compAttack->m_mod = FINESSE;
    blueprint.registerComponent(std::move(compAttack));

    //Register Damage Component
    auto compDamage = std::make_unique<CompDamage>(nextID);
    compDamage->m_dmgDice = D4;
    compDamage->m_dmgType = SLASHING;
    blueprint.registerComponent(std::move(compDamage));

    //Register Equipable Component
    auto compEquipable = std::make_unique<CompEquipable>(nextID);
    compEquipable->m_light = false;
    compEquipable->m_twoHand = false;
    blueprint.registerComponent(std::move(compEquipable));

    Item_ptr item = blueprint.instantiateItem(nextID, ownerID, "Shortsword", "A small sword, very sharp");

    auto itemID = item->m_ID;

    itemContainer.emplace(itemID, std::move(item));

    return itemID;
}