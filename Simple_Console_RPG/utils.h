#ifndef UTILS
#define UTILS

#include <bitset>
#include <vector>
#include <inttypes.h>
#include <array>

const int COMPONENTS_NUM = 11;
const int INITIAL_SPELLPOINTS = 4;

using ID = uint16_t;
using Lvl = uint16_t;
using EXP = uint16_t;
using HP = uint16_t;
using SP = uint16_t;
using Scr = uint16_t;
using Mod = int16_t;
using AC = uint16_t;
using Roll = uint16_t;
using Party = std::vector<ID>;
using CompSet = std::bitset<COMPONENTS_NUM>;

template<class T> using Container = std::vector<T>;
template<int T> using Map = std::array<std::array<int, T>, T>;

enum Dice {

	D0 = 0,
	D4 = 4,
	D6 = 6,
	D8 = 8,
	D10 = 10,
	D12 = 12,
	D20 = 20,
	D100 = 100

};

#endif