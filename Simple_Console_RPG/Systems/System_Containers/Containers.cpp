#include "Containers.h"

#include "..\..\utils.h"
#include "..\..\Entity\entity.h"
#include "..\..\Components\comp_info.h"
#include "..\..\Components\comp_score.h"
#include "..\..\Components\comp_level.h"
#include "..\..\Components\comp_points.h"
#include "..\..\Components\comp_stats.h"
#include "..\..\Components\comp_armor.h"
#include "..\..\Components\comp_main-hand.h"
#include "..\..\Components\comp_off-hand.h"
#include "..\..\Components\comp_cast.h"
#include "..\..\Components\comp_nat-armor.h"
#include "..\..\Components\comp_nat-weapons.h"

Container<Entity_ptr> entityContainer;
Container<Score_ptr> scoreContainer;
Container<Info_ptr> infoContainer;
Container<Level_ptr> levelContainer;
Container<Points_ptr> pointsContainer;
Container<Stats_ptr> statsContainer;
Container<Armor_ptr> armorContainer;
Container<MainHand_ptr> mainHandContainer;
Container<OffHand_ptr> offHandContainer;
Container<Cast_ptr> castContainer;
Container<NatArmor_ptr> natArmorContainer;
Container<NatWeapons_ptr> natWeaponsContainer;

bool testComponent(ID entityID, CompList comp) {
	return entityContainer.find(entityID)->second.get()->chk_comp(comp);
}

//Component Info specifics
std::string getName(ID entityID) {
	auto it = infoContainer.find(entityID)->second.get();
	return it->m_name;
}

//Component Score specifics
Scr chkScore(ID entityID, ScoreList score) {
	auto it = scoreContainer.find(entityID);
	switch (score)
	{
	case STR:
		return it->second->m_str;
		break;
	case DEX:
		return it->second->m_dex;
		break;
	case CON:
		return it->second->m_con;
		break;
	case INT:
		return it->second->m_int;
		break;
	case FTH:
		return it->second->m_fth;
		break;
	case LCK:
		return it->second->m_lck;
		break;
	}
	
}
Mod getMod(ID entityID, ScoreList score) {
	return (chkScore(entityID, score) - 10) / 2;
}

//Component Points specifics
HP chkHP(ID entityID) {
	auto it = pointsContainer.find(entityID)->second.get();
	return it->m_currentHP;
}
HP chkMaxHP(ID entityID) {
	auto it = pointsContainer.find(entityID)->second.get();
	return it->m_maxHP;
}
void takeDamage(ID entityID, HP damage) {
	auto it = pointsContainer.find(entityID)->second.get();
	if (damage > it->m_currentHP) {
		it->m_currentHP = 0;
	}
	else {
		it->m_currentHP -= damage;
	}
}

//Component Stats specifics
RollAdv& getRollAdv(ID entityID, RollType type, ScoreList score) {
	switch (type)
	{
	case ROLL_SCORE:
		auto stats = statsContainer.find(entityID);
		auto roll = stats->second.get()->m_scrRoll.find(score);
		return roll->second;
		break;
	case ROLL_SAVING:
		auto stats = statsContainer.find(entityID);
		auto roll = stats->second.get()->m_svgRoll.find(score);
		return roll->second;
		break;
	case ROLL_ATK:
		auto it = statsContainer.find(entityID);
		return it->second.get()->m_atkRoll;
		break;
	case ROLL_AC:
		auto it = statsContainer.find(entityID);
		return it->second.get()->m_ACRoll;
		break;
	}
}

ID getWeapon(ID entityID, CompList hand) {
	switch (hand)
	{
	case MAINHAND:
	{
		auto it = mainHandContainer.find(entityID);
		return it->second.get()->m_weapon;
		break;
	}
	case OFFHAND:
	{
		auto it = offHandContainer.find(entityID);
		return it->second.get()->m_weapon;
		break;
	}
	case NAT_WEAPONS:
	{
		auto it = natWeaponsContainer.find(entityID);
		int weapons = it->second.get()->m_weapons.size();
		return it->second.get()->m_weapons[rand() % weapons];
		break;
	}
	}
}