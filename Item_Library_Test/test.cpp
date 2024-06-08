#include "pch.h"
#include "..\Item_Library\Systems\Item_Interface.h"

TEST(BlueprintTest, HealingPotion) {
	
	ID owner = 1;
	auto item = createHealingPotion(owner);
	
	//Assert
	EXPECT_EQ(item, 1001);
	EXPECT_EQ(testComponent(item, CONSUMABLE_COMP), true);
	EXPECT_EQ(testComponent(item, POINTSREGEN_COMP), true);
	EXPECT_EQ(getItemName(item), "Healing Potion");
	/*EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP)->m_regenHP, 5);
	EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP).use_count(), 1);
	EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);
	EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, ShortSword) {

	ID owner = 2;
	auto item2 = createShortSword(owner);

	//Assert

	EXPECT_EQ(item2, 1002);
	EXPECT_EQ(testComponent(item2, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item2, ATTACK_COMP), true);
	EXPECT_EQ(testComponent(item2, DAMAGE_COMP), true);
	EXPECT_EQ(getItemName(item2), "Shortsword");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}