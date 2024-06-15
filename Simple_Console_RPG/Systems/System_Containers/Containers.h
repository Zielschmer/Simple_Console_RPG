#ifndef SYSTEM_CONTAINER
#define SYSTEM_CONTAINER

#include "..\..\..\utilities\utils.h"
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
#include "..\..\Components\comp_inventory.h"

extern Container<Entity_ptr> entityContainer;
extern Container<Score_ptr> scoreContainer;
extern Container<Info_ptr> infoContainer;
extern Container<Level_ptr> levelContainer;
extern Container<Points_ptr> pointsContainer;
extern Container<Stats_ptr> statsContainer;
extern Container<Armor_ptr> armorContainer;
extern Container<MainHand_ptr> mainHandContainer;
extern Container<OffHand_ptr> offHandContainer;
extern Container<Cast_ptr> castContainer;
extern Container<NatArmor_ptr> natArmorContainer;
extern Container<NatWeapons_ptr> natWeaponsContainer;

bool testComponent(ID entityID, CompList comp);
template <typename T>
std::unique_ptr<T> getComponent(ID entityID, CompList comp) {
	switch (comp)
	{
	case SCORE_COMP:
		return scoreContainer.find(entityID)->second.get();
		break;
	case INFO_COMP:
		return infoContainer.find(entityID)->second.get();
		break;
	case LEVEL_COMP:
		return levelContainer.find(entityID)->second.get();
		break;
	case POINTS_COMP:
		return pointsContainer.find(entityID)->second.get();
		break;
	case STATS_COMP:
		return statsContainer.find(entityID)->second.get();
		break;
	case ARMOR_COMP:
		return armorContainer.find(entityID)->second.get();
		break;
	case MAINHAND_COMP:
		return mainHandContainer.find(entityID)->second.get();
		break;
	case OFFHAND_COMP:
		return offHandContainer.find(entityID)->second.get();
		break;
	case CAST_COMP:
		return castContainer.find(entityID)->second.get();
		break;
	case NAT_ARMOR_COMP:
		return natArmorContainer.find(entityID)->second.get();
		break;
	case NAT_WEAPONS_COMP:
		return natWeaponsContainer.find(entityID)->second.get();
		break;
	}
}

//Component Info specifics
std::string getName(ID entityID);

//Component Score specifics
Scr chkScore(ID entityID, ScoreList score);
Mod getMod(ID entityID, ScoreList score);


//Component Points specifics
HP chkHP(ID entityID);
HP chkMaxHP(ID entityID);
void takeDamage(ID entityID, HP damage);

//Component Stats specifics
RollAdv& getRollAdv(ID entityID, RollType type, ScoreList score);

//Weapon components
ID getWeapon(ID entityID, CompList hand);

//Component Inventory specifics
std::vector<ID> getInventory(ID entityID);
Coins chkCoins(ID entityID);
void addCoins(ID entityID, Coins coins);
void rmvCoins(ID entityID, Coins coins);

#endif