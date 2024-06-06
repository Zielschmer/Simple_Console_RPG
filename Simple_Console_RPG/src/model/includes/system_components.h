#pragma once

#include "..\..\lib\includes\lib_primitives.h"

#include "..\..\lib\includes\lib_entity.h"
#include "..\..\lib\includes\comp_score.h"
#include "..\..\lib\includes\comp_info.h"
#include "..\..\lib\includes\comp_level.h"
#include "..\..\lib\includes\comp_points.h"
#include "..\..\lib\includes\comp_stats.h"
#include "..\..\lib\includes\comp_armor.h"
#include "..\..\lib\includes\comp_rhand.h"
#include "..\..\lib\includes\comp_lhand.h"
#include "..\..\lib\includes\comp_cast.h"
#include "..\..\lib\includes\comp_nat-armor.h"
#include "..\..\lib\includes\comp_nat-weapon.h"

//Entity and containers Data Structures
extern Container<Entity_ptr> entityContainer;
extern Container<Score_ptr> scoreContainer;
extern Container<Info_ptr> infoContainer;
extern Container<Level_ptr> levelContainer;
extern Container<Points_ptr> pointsContainer;
extern Container<Stats_ptr> statsContainer;
extern Container<Armor_ptr> armorContainer;
extern Container<RHand_ptr> rHandContainer;
extern Container<LHand_ptr> lHandContainer;
extern Container<Cast_ptr> castContainer;
extern Container<NatArmor_ptr> natArmorContainer;
extern Container<NatWeapon_ptr> natWeaponContainer;

//Get Entity function
Entity_ptr& getEntity (ID entityID);

//Get containers functions
Score_ptr& getScoreComp(ID ownerID);
Info_ptr& getInfoComp(ID ownerID);
Level_ptr& getLevelComp(ID ownerID);
Points_ptr& getPointsComp(ID ownerID);
Stats_ptr& getStatsComp(ID ownerID);
Armor_ptr& getArmorComp(ID ownerID);
RHand_ptr& getRHandComp(ID ownerID);
LHand_ptr& getLHandComp(ID ownerID);
Cast_ptr& getCastComp(ID ownerID);
NatArmor_ptr& getNatArmorComp(ID ownerID);
NatWeapon_ptr& getNatWeaponComp(ID ownerID);

//Delete containers functions
void delArmorComp(ID ownerID);
void delRHandComp(ID ownerID);
void delLHandComp(ID ownerID);
void delCastComp(ID ownerID);

//Misc functions
int getScoreMod(ID ownderID, ScoreList score);
int getSpeed(ID ownderID);