#ifndef UTILS
#define UTILS

#include <bitset>
#include <vector>
#include <inttypes.h>
#include <array>

const int COMPONENTS_NUM = 11;

using ID = uint16_t;
using Lvl = uint16_t;
using EXP = uint16_t;
using HP = uint16_t;
using SP = uint16_t;
using Scr = uint16_t;
using Mod = int16_t;
using AC = uint16_t;
using Range = uint16_t;
using Turns = uint16_t;
using Party = std::vector<ID>;
using Resistance = std::vector<DamageList>;
using Weakness = std::vector<DamageList>;
using CompSet = std::bitset<COMPONENTS_NUM>;

template<class T> using Container = std::vector<T>;

enum DiceList {
	D1 = 1,
	D4 = 4,
	D6 = 6,
	D8 = 8,
	D10 = 10,
	D12 = 12,
	D20 = 20,
	D100 = 100
};

enum ScoreList {
	NONE,
	STR,
	DEX,
	CON,
	INT,
	FTH,
	LCK,
	FINESSE
};

enum DamageList {
	PIERCING,
	SLASHING,
	BLUDGEONING,
	FIRE,
	COLD,
	LIGHTINING,
	RADIANT,
	THUNDER,
	PSYCHIC,
	FORCE,
	ACID,
	POISON,
	NECROTIC
};

enum CompList {
	COMP_CONSUMABLE,
	COMP_POINTSREGEN,
	COMP_ATTACK,
	COMP_DEFENSE,
	AMMUNITION,
	CAST_FOCUS
};

enum AmmoList {
	AMMO_SELF,
	AMMO_BOLT,
	AMMO_ARROW
};

enum TargetList {
	TARGET_SELF,
	TARGET_ALLY,
	TARGET_ENEMY,
	TARGET_AREA
};
#endif