#include "includes\monster.h"
#include "..\..\src\model\includes\roll-dice.h"

void createMonsterAbilityScore(AbilityScore& abilityScore, int whatEnemy) {

	switch (whatEnemy)
	{
		case 0:
		{
			abilityScore.m_strength = 2;
			abilityScore.m_dexterity = 15;
			abilityScore.m_constitution = 8;
			abilityScore.m_intelligence = 2;
			abilityScore.m_faith = 12;
			abilityScore.m_luck = 4;
			break;
		}
		case 1:
		{
			abilityScore.m_strength = 2;
			abilityScore.m_dexterity = 11;
			abilityScore.m_constitution = 9;
			abilityScore.m_intelligence = 9;
			abilityScore.m_faith = 10;
			abilityScore.m_luck = 4;
			break;
		}
		case 2:
		{
			abilityScore.m_strength = 2;
			abilityScore.m_dexterity = 11;
			abilityScore.m_constitution = 8;
			abilityScore.m_intelligence = 1;
			abilityScore.m_faith = 8;
			abilityScore.m_luck = 2;
			break;
		}
		default:
			break;
	}

}

void createMonsterInfo(Info& info, int whatEnemy) {

	switch (whatEnemy)
	{
	case 0:
		info.m_description = "Bat";
		break;

	case 1:
		info.m_description = "Rat";
		break;

	case 2:
		info.m_description = "Scorpion";
		break;

	default:
		break;
	}

}

void createMonsterHitPoints(HitPoints& hitPoints, int whatEnemy) {

	switch (whatEnemy)
	{
	case 0:
		hitPoints.m_maxHP = rollDice(3, 1);
		hitPoints.m_currentHP = hitPoints.m_maxHP;
		break;

	case 1:
		hitPoints.m_maxHP = rollDice(3, 1);
		hitPoints.m_currentHP = hitPoints.m_maxHP;
		break;

	case 2:
		hitPoints.m_maxHP = rollDice(3, 1);
		hitPoints.m_currentHP = hitPoints.m_maxHP;
		break;;

	default:
		break;
	}

}

void createMonsterNaturalArmor(NaturalArmor& naturalArmor, int whatEnemy) {

	switch (whatEnemy)
	{
		case 0:
		{
			naturalArmor.m_armorClass = 12;
			break;
		}
		case 1:
		{
			naturalArmor.m_armorClass = 10;
			break;
		}
		case 2:
		{
			naturalArmor.m_armorClass = 11;
			break;
		}
		default:
			break;
	}
}

void createMonsterNaturalWeapon(NaturalWeapons& naturalWeapons, int whatEnemy) {

	switch (whatEnemy)
	{
		case 0:
		{
			NaturalWeapon newWeapon1;
			newWeapon1.m_name = "Bite";
			newWeapon1.m_baseAttack = 0;
			newWeapon1.m_savingThrow = 0;
			newWeapon1.m_difficultClass = 0;
			newWeapon1.m_extraDamage = 0;
			newWeapon1.m_passEffect = false;

			naturalWeapons.m_naturalWeapons.push_back(newWeapon1);
			break;
		}
		case 1:
		{
			NaturalWeapon newWeapon1;
			newWeapon1.m_name = "Bite";
			newWeapon1.m_baseAttack = 0;
			newWeapon1.m_savingThrow = 0;
			newWeapon1.m_difficultClass = 0;
			newWeapon1.m_extraDamage = 0;
			newWeapon1.m_passEffect = false;

			naturalWeapons.m_naturalWeapons.push_back(newWeapon1);
			break;
		}
		case 2:
		{
			NaturalWeapon newWeapon1;
			newWeapon1.m_name = "Sting";
			newWeapon1.m_baseAttack = 0;
			newWeapon1.m_savingThrow = 3;
			newWeapon1.m_difficultClass = 9;
			newWeapon1.m_extraDamage = 3;
			newWeapon1.m_passEffect = true;

			naturalWeapons.m_naturalWeapons.push_back(newWeapon1);
			break;
		}
		default:
			break;
	}
}