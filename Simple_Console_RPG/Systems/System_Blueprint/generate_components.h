#include "..\..\utils.h"

#include "blueprint.h"
#include "..\..\Components\comp_score.h"
#include "..\..\Components\comp_info.h"
#include "..\..\Components\comp_level.h"
#include "..\..\Components\comp_points.h"
#include "..\..\Components\comp_stats.h"
#include "..\..\Components\comp_armor.h"
#include "..\..\Components\comp_main-hand.h"
#include "..\..\Components\comp_off-hand.h"
#include "..\..\Components\comp_cast.h"

Score_ptr generateScore(ID& entityID);
Info_ptr generateInfo(ID& entityID);
Armor_ptr generateArmor(ID& entityID);
MainHand_ptr generateMainHand(ID& entityID);
OffHand_ptr generateOffHand(ID& entityID);
Cast_ptr generateCast(ID& entityID);