#include "pch.h"
#include "..\Item_Library\Systems\System_Blueprint\blueprint_list.h"

TEST(BlueprintTest, HealingPotion) {
	
	ID owner = 1;
	auto item = createHealingPotion(ITEM_ID, owner);
	
	//Assert
	EXPECT_EQ(item, 1001);
	/*EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP)->m_regenHP, 5);
	EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP).use_count(), 1);
	EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);
	EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, ShortSword) {

	ID owner = 1;
	auto item = createShortSword(ITEM_ID, owner);

	//Assert
	EXPECT_EQ(item, 1002);
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}