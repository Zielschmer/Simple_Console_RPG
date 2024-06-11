#ifndef UTILS
#define UTILS

#include <vector>
#include <inttypes.h>
#include <unordered_map>
#include <memory>
#include <string>
#include <any>
#include <bitset>

const int COMPONENTS_NUM = 11;
const int INITIAL_SPELLPOINTS = 4;

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

enum RollType {
	ROLL_SCORE,
	ROLL_SAVING,
	ROLL_ATK,
	ROLL_AC
};

enum RollAdv {
	DISROLL,
	NMLROLL,
	ADVROLL
};

enum ScoreList {

	NOMOD,
	STR,
	DEX,
	CON,
	INT,
	FTH,
	LCK

};

enum DamageList {
	NODMG,
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

enum CastType {
	NOCAST,
	SPELL,
	PRAY,
	SONG
};

enum CompList {

	SCORE,
	INFO,
	LEVEL,
	POINTS,
	STATS,
	ARMOR,
	MAINHAND,
	OFFHAND,
	CAST,
	NAT_ARMOR,
	NAT_WEAPONS

};

enum TargetList {
	TARGET_SELF,
	TARGET_ALLY,
	TARGET_ENEMY,
	TARGET_AREA
};

enum ConditionList {
	POISONED
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
using Roll = uint16_t;
using Turns = uint16_t;
using Resistance = std::vector<DamageList>;
using Weakness = std::vector<DamageList>;
using Party = std::vector<ID>;

using CompSet = std::bitset<COMPONENTS_NUM>;

template<class T>
using Container = std::unordered_map<ID, T>;
template<int T>
using Map = std::array<std::array<int, T>, T>;

#endif