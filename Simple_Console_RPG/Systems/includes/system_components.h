#ifndef SYSTEM_COMPONENTS
#define SYSTEM_COMPONENTS

#include "..\..\utils.h"

#include "..\..\Entity\entity.h"
#include "..\..\Components\comp_info.h"
#include "..\..\Components\comp_score.h"
#include "..\..\Components\comp_level.h"
#include "..\..\Components\comp_points.h"
#include "..\..\Components\comp_stats.h"
#include "..\..\Components\comp_armor.h"
#include "..\..\Components\comp_equips.h"
#include "..\..\Components\comp_cast.h"
#include "..\..\Components\comp_nat-armor.h"
#include "..\..\Components\comp_nat-weapon.h"

//Entity and containers Data Structures
extern Container<Entity_ptr> entityContainer;
extern Container<Score_ptr> scoreContainer;
extern Container<Info_ptr> infoContainer;
extern Container<Level_ptr> levelContainer;
extern Container<Points_ptr> pointsContainer;
extern Container<Stats_ptr> statsContainer;
extern Container<Armor_ptr> armorContainer;
extern Container<Equips_ptr> rHandContainer;
extern Container<Cast_ptr> castContainer;
extern Container<NatArmor_ptr> natArmorContainer;
extern Container<NatWeapon_ptr> natWeaponContainer;

template <typename T>
T& getComp(ID& entity, std::vector<T>& container) {
	for (auto member : container) {
		if (member->m_ownerID == entity) {
			return member;
		}
	}
};

template <typename T>
void delComp(ID& entity, std::vector<T>& container) {
	for (auto member : container) {
		if (member->mownderID) == entity) {
			container.erase(member);
		}
	}
};

Mod getMod(ID& entity, ScoreList score) {
	Mod mod;
	switch (score)
	{
	case STR:
		mod = getComp<Score_ptr>(entity, scoreContainer)->m_str;
		break;
	case DEX:
		mod = getComp<Score_ptr>(entity, scoreContainer)->m_dex;
		break;
	case CON:
		mod = getComp<Score_ptr>(entity, scoreContainer)->m_con;
		break;
	case INT:
		mod = getComp<Score_ptr>(entity, scoreContainer)->m_int;
		break;
	case FTH:
		mod = getComp<Score_ptr>(entity, scoreContainer)->m_fth;
		break;
	case LCK:
		mod = getComp<Score_ptr>(entity, scoreContainer)->m_lck;
		break;
	}
	return floor((mod - 10) / 2);
}

#endif