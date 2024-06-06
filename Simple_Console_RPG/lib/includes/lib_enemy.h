#pragma once

#include "lib_primitives.h"
#include "comp_score.h"
#include "comp_info.h"
#include "comp_points.h"
#include "comp_nat-armor.h"
#include "comp_nat-weapon.h"

enum EnemyList {

	BAT,
	RAT,
	SCORPION

};

void getEnemyScore(Score_Comp& score, EnemyList enemy);

void getEnemyInfo(Info_Comp& info, EnemyList enemy);

void getEnemyPoints(Points_Comp& points, EnemyList enemy);

void getEnemyNatArmor(NatArmor_Comp& naturalArmor, EnemyList enemy);

void getEnemyNatWeapon(NatWeapon_Comp& naturalWeapons, EnemyList enemy);