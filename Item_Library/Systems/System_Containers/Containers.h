#ifndef SYSTEM_CONTAINER
#define SYSTEM_CONTAINER

#include <functional>

#include <utility>

#include "..\..\utils.h"
#include "..\..\Entity\item.h"
#include "..\..\Components\comp_consumable.h"
#include "..\..\Components\comp_points-regen.h"
#include "..\..\Components\comp_equipable.h"
#include "..\..\Components\comp_attack.h"
#include "..\..\Components\comp_damage.h"
#include "..\..\Components\comp_defense.h"
#include "..\..\Components\comp_ammunition.h"
#include "..\..\Components\comp_cast-focus.h"
#include "..\..\Components\comp_conditions.h"

extern Container<Item_ptr> itemContainer;
extern Container<Consumable_ptr> consumableContainer;
extern Container<PointsRegen_ptr> pointsRegenContainer;
extern Container<Attack_ptr> attackContainer;
extern Container<Defense_ptr> defenseContainer;
extern Container<Equipable_ptr> equipableContainer;
extern Container<Damage_ptr> damageContainer;
extern Container<Ammunition_ptr> ammunitionContainer;
extern Container<CastFocus_ptr> castFocusContainer;
extern Container<Conditions_ptr> conditionsContainer;

#endif