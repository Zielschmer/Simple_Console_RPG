#ifndef SYSTEM_CONTAINER
#define SYSTEM_CONTAINER

#include "..\..\utils.h"

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
	case SCORE:
		return scoreContainer.find(entityID)->second.get();
		break;
	case INFO:
		return infoContainer.find(entityID)->second.get();
		break;
	case LEVEL:
		return levelContainer.find(entityID)->second.get();
		break;
	case POINTS:
		return pointsContainer.find(entityID)->second.get();
		break;
	case STATS:
		return statsContainer.find(entityID)->second.get();
		break;
	case ARMOR:
		return armorContainer.find(entityID)->second.get();
		break;
	case MAINHAND:
		return mainHandContainer.find(entityID)->second.get();
		break;
	case OFFHAND:
		return offHandContainer.find(entityID)->second.get();
		break;
	case CAST:
		return castContainer.find(entityID)->second.get();
		break;
	case NAT_ARMOR:
		return natArmorContainer.find(entityID)->second.get();
		break;
	case NAT_WEAPONS:
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

#endif