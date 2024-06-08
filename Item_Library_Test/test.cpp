#include "pch.h"
#include "..\Item_Library\Systems\healing_potion.h"

TEST(BlueprintTest, HealingPotion) {

  ID nextID = 1u;

  Blueprint blueprint = createHealingPotion();

  Item_ptr item = blueprint.createItem(nextID, "Healing Potion", "Heals 5 HP");

  //Assert
  EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP)->m_target, TARGET_ALLY);
  EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP)->m_regenHP, 5);
  EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP).use_count(), 1);
  EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);
  EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);

}