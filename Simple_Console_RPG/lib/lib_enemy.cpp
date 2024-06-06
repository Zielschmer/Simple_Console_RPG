#include "includes\lib_enemy.h"
#include "..\..\src\model\includes\system_dice.h"

void getEnemyScore(Score_Comp& score, EnemyList enemy) {

	switch (enemy)
	{
		case BAT:
		{
			score.m_str = 2;
			score.m_dex = 15;
			score.m_con = 8;
			score.m_int = 2;
			score.m_fth = 12;
			score.m_lck = 4;
			break;
		}
		case RAT:
		{
			score.m_str = 2;
			score.m_dex = 11;
			score.m_con = 9;
			score.m_int = 9;
			score.m_fth = 10;
			score.m_lck = 4;
			break;
		}
		case SCORPION:
		{
			score.m_str = 2;
			score.m_dex = 11;
			score.m_con = 8;
			score.m_int = 1;
			score.m_fth = 8;
			score.m_lck = 2;
			break;
		}
		default:
			break;
	}

}

void getEnemyInfo(Info_Comp& info, EnemyList enemy) {

	switch (enemy)
	{
	case BAT:
		info.m_desc = "Bat";
		break;

	case RAT:
		info.m_desc = "Rat";
		break;

	case SCORPION:
		info.m_desc = "Scorpion";
		break;

	default:
		break;
	}

}

void getEnemyPoints(Points_Comp& points, EnemyList enemy) {

	switch (enemy)
	{
	case BAT:
		points.m_maxHP = getDice(D4, 1, NORMAL, (-1));
		points.m_currentHP = points.m_maxHP;
		break;

	case RAT:
		points.m_maxHP = getDice(D4, 1, NORMAL, (-1));
		points.m_currentHP = points.m_maxHP;
		break;

	case SCORPION:
		points.m_maxHP = getDice(D4, 1, NORMAL, (-1));
		points.m_currentHP = points.m_maxHP;
		break;
	}

}

void getEnemyNatArmor(NatArmor_Comp& natArmor, EnemyList enemy) {

	switch (enemy)
	{
		case BAT:
		{
			natArmor.m_armorClass = 12;
			break;
		}
		case RAT:
		{
			natArmor.m_armorClass = 10;
			break;
		}
		case SCORPION:
		{
			natArmor.m_armorClass = 11;
			break;
		}
	}
}

void getEnemyNatWeapon(NatWeapon_Comp& natWeapon, EnemyList enemy) {

	switch (enemy)
	{
		case BAT:
		{
			Weapon newWeapon;
			newWeapon.m_name = "Bite";
			newWeapon.m_diceAtk = 0;
			newWeapon.m_savingThrow = 0;
			newWeapon.m_DC = 0;
			newWeapon.m_extraDice = 0;
			newWeapon.m_passEffect = false;

			natWeapon.m_weapons.push_back(newWeapon);
			break;
		}
		case RAT:
		{
			Weapon newWeapon;
			newWeapon.m_name = "Bite";
			newWeapon.m_diceAtk = 0;
			newWeapon.m_savingThrow = 0;
			newWeapon.m_DC = 0;
			newWeapon.m_extraDice = 0;
			newWeapon.m_passEffect = false;

			natWeapon.m_weapons.push_back(newWeapon);
			break;
		}
		case SCORPION:
		{
			Weapon newWeapon;
			newWeapon.m_name = "Sting";
			newWeapon.m_diceAtk = 0;
			newWeapon.m_savingThrow = 3;
			newWeapon.m_DC = 9;
			newWeapon.m_extraDice = 3;
			newWeapon.m_passEffect = true;

			natWeapon.m_weapons.push_back(newWeapon);
			break;
		}
		default:
			break;
	}
}