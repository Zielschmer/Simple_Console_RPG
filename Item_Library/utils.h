#ifndef UTILS
#define UTILS

#include <vector>
#include <inttypes.h>
#include <unordered_map>
#include <memory>
#include <string>
#include <any>

const int COMPONENTS_NUM = 11;

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
	CONSUMABLE_COMP,
	POINTSREGEN_COMP,
	ATTACK_COMP,
	DEFENSE_COMP,
	AMMUNITION_COMP,
	CAST_FOCUS_COMP
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

using CompSet = std::unordered_map<CompList, std::any>;

#endif