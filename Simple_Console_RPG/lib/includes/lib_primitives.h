#pragma once

#include <bitset>
#include <vector>
#include <string>
#include <array>

#define COMPONENTS_NUM 11
#define INITIAL_SPELLSLOTS 4

typedef int ID;
template<class T> using Container = std::vector<T>;
typedef std::vector<ID> Party;
typedef std::bitset<COMPONENTS_NUM> CompSet;
template<int T> using Map = std::array<std::array<int, T>, T>;