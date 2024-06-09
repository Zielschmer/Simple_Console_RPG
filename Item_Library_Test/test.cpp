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

TEST(BlueprintTest, Dart) {

	ID owner = 1;
	auto item = createDart(owner);

	//Assert
	EXPECT_EQ(item, 1002);
	EXPECT_EQ(testComponent(item, CONSUMABLE_COMP), true);
	EXPECT_EQ(testComponent(item, THROWABLE_COMP), true);
	EXPECT_EQ(getItemName(item), "Dart");
	/*EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP)->m_regenHP, 5);
	EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP).use_count(), 1);
	EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);
	EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Arrow) {

	ID owner = 1;
	auto item = createArrow(owner);

	//Assert
	EXPECT_EQ(item, 1003);
	EXPECT_EQ(testComponent(item, AMMO_COMP), true);
	EXPECT_EQ(getItemName(item), "Arrow");
	/*EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP)->m_regenHP, 5);
	EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP).use_count(), 1);
	EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);
	EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Bolt) {

	ID owner = 1;
	auto item = createBolt(owner);

	//Assert
	EXPECT_EQ(item, 1004);
	EXPECT_EQ(testComponent(item, AMMO_COMP), true);
	EXPECT_EQ(getItemName(item), "Bolt");
	/*EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP)->m_regenHP, 5);
	EXPECT_EQ(item->getComponent<CompPointsRegen>(POINTSREGEN_COMP).use_count(), 1);
	EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);
	EXPECT_EQ(item->getComponent<CompConsumable>(CONSUMABLE_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, ShortSword) {

	ID owner = 1;
	auto item = createShortSword(owner);

	//Assert

	EXPECT_EQ(item, 1005);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, ATTACK_COMP), true);
	EXPECT_EQ(testComponent(item, DAMAGE_COMP), true);
	EXPECT_EQ(getItemName(item), "Shortsword");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Dagger) {

	ID owner = 1;
	auto item = createDagger(owner);

	//Assert

	EXPECT_EQ(item, 1006);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, ATTACK_COMP), true);
	EXPECT_EQ(testComponent(item, DAMAGE_COMP), true);
	EXPECT_EQ(testComponent(item, THROWABLE_COMP), true);
	EXPECT_EQ(getItemName(item), "Dagger");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Mace) {

	ID owner = 1;
	auto item = createMace(owner);

	//Assert

	EXPECT_EQ(item, 1007);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, ATTACK_COMP), true);
	EXPECT_EQ(testComponent(item, DAMAGE_COMP), true);
	EXPECT_EQ(getItemName(item), "Mace");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Hammer) {

	ID owner = 1;
	auto item = createHammer(owner);

	//Assert

	EXPECT_EQ(item, 1008);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, ATTACK_COMP), true);
	EXPECT_EQ(testComponent(item, DAMAGE_COMP), true);
	EXPECT_EQ(getItemName(item), "Hammer");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Bow) {

	ID owner = 1;
	auto item = createBow(owner);

	//Assert

	EXPECT_EQ(item, 1009);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, ATTACK_COMP), true);
	EXPECT_EQ(testComponent(item, DAMAGE_COMP), true);
	EXPECT_EQ(testComponent(item, AMMUNITION_COMP), true);
	EXPECT_EQ(getItemName(item), "Short Bow");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Staff) {

	ID owner = 1;
	auto item = createStaff(owner);

	//Assert

	EXPECT_EQ(item, 1010);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, ATTACK_COMP), true);
	EXPECT_EQ(testComponent(item, DAMAGE_COMP), true);
	EXPECT_EQ(testComponent(item, CAST_FOCUS_COMP), true);
	EXPECT_EQ(getItemName(item), "Staff");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Rosary) {

	ID owner = 1;
	auto item = createRosary(owner);

	//Assert

	EXPECT_EQ(item, 1011);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, ATTACK_COMP), true);
	EXPECT_EQ(testComponent(item, DAMAGE_COMP), true);
	EXPECT_EQ(testComponent(item, CAST_FOCUS_COMP), true);
	EXPECT_EQ(getItemName(item), "Rosary");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Harp) {

	ID owner = 1;
	auto item = createHarp(owner);

	//Assert

	EXPECT_EQ(item, 1012);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, ATTACK_COMP), true);
	EXPECT_EQ(testComponent(item, DAMAGE_COMP), true);
	EXPECT_EQ(testComponent(item, CAST_FOCUS_COMP), true);
	EXPECT_EQ(getItemName(item), "Harp");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Shield) {

	ID owner = 1;
	auto item = createShield(owner);

	//Assert

	EXPECT_EQ(item, 1013);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, DEFENSE_COMP), true);
	EXPECT_EQ(getItemName(item), "Shield");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Robe) {

	ID owner = 1;
	auto item = createRobe(owner);

	//Assert

	EXPECT_EQ(item, 1014);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, DEFENSE_COMP), true);
	EXPECT_EQ(getItemName(item), "Robe");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, LeatherArmor) {

	ID owner = 1;
	auto item = createLeatherArmor(owner);

	//Assert

	EXPECT_EQ(item, 1015);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, DEFENSE_COMP), true);
	EXPECT_EQ(getItemName(item), "Leather Armor");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, RingMail) {

	ID owner = 1;
	auto item = createRingMail(owner);

	//Assert

	EXPECT_EQ(item, 1016);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, DEFENSE_COMP), true);
	EXPECT_EQ(getItemName(item), "Ring Mail");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, ChainMail) {

	ID owner = 1;
	auto item = createChainMail(owner);

	//Assert

	EXPECT_EQ(item, 1017);
	EXPECT_EQ(testComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(testComponent(item, DEFENSE_COMP), true);
	EXPECT_EQ(getItemName(item), "Chain Mail");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}