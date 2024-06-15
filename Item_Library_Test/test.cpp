#include "pch.h"

#include "pch.h"
#include "..\Item_Library\Item_Interface.h"

TEST(BlueprintTest, HealingPotion) {

	ID owner = 1;
	auto item = getConsumable(owner, ITEM_HEAL_POT);

	//Assert
	EXPECT_EQ(item, 1001);
	EXPECT_EQ(chkComponent(item, CONSUMABLE_COMP), true);
	EXPECT_EQ(chkComponent(item, POINTSREGEN_COMP), true);
	EXPECT_EQ(chkItemName(item), "Healing Potion");
	EXPECT_EQ(chkHPRegen(item), 5);
	EXPECT_EQ(chkSPRegen(item), 0);
	EXPECT_EQ(chkConsumableTarget(item), TARGET_ALLY);

}

TEST(BlueprintTest, Dart) {

	ID owner = 1;
	auto item = getConsumable(owner, ITEM_DART);

	//Assert
	EXPECT_EQ(item, 1002);
	EXPECT_EQ(chkComponent(item, CONSUMABLE_COMP), true);
	EXPECT_EQ(chkComponent(item, THROWABLE_COMP), true);
	EXPECT_EQ(chkItemName(item), "Dart");
	EXPECT_EQ(chkConsumableTarget(item), TARGET_ENEMY);
	EXPECT_EQ(chkDmgDice(item), D4);
	EXPECT_EQ(chkDmgType(item), PIERCING);
	EXPECT_EQ(chkThrowMod(item), DEX);
	EXPECT_EQ(chkThrowRange(item), 20);
}

TEST(BlueprintTest, ShortSword) {

	ID owner = 1;
	auto item = getWeapon(owner, WEAPON_SHORT_SWORD);

	//Assert

	EXPECT_EQ(item, 1003);
	EXPECT_EQ(chkComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(chkComponent(item, ATTACK_COMP), true);
	EXPECT_EQ(chkComponent(item, DAMAGE_COMP), true);
	EXPECT_EQ(chkItemName(item), "Shortsword");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}

TEST(BlueprintTest, Robe) {

	ID owner = 1;
	auto item = getArmor(owner, ARMOR_ROBE);

	//Assert

	EXPECT_EQ(item, 1004);
	EXPECT_EQ(chkComponent(item, EQUIPABLE_COMP), true);
	EXPECT_EQ(chkComponent(item, DEFENSE_COMP), true);
	EXPECT_EQ(chkItemName(item), "Robe");
	/*EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgDice, D4);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_dmgType, SLASHING);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_mod, FINESSE);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_light, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP)->m_twoHand, false);
	EXPECT_EQ(item->getComponent<CompAttack>(ATTACK_COMP).use_count(), 1);*/

}