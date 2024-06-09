#include "Containers.h"

#include "..\..\Entity\item.h"
#include "..\..\Components\comp_consumable.h"
#include "..\..\Components\comp_points-regen.h"
#include "..\..\Components\comp_equipable.h"
#include "..\..\Components\comp_attack.h"
#include "..\..\Components\comp_damage.h"
#include "..\..\Components\comp_defense.h"
#include "..\..\Components\comp_ammunition.h"
#include "..\..\Components\comp_ammo.h"
#include "..\..\Components\comp_throwable.h"
#include "..\..\Components\comp_cast-focus.h"
#include "..\..\Components\comp_conditions.h"

Container<Item_ptr> itemContainer;
Container<Consumable_ptr> consumableContainer;
Container<PointsRegen_ptr> pointsRegenContainer;
Container<Attack_ptr> attackContainer;
Container<Defense_ptr> defenseContainer;
Container<Equipable_ptr> equipableContainer;
Container<Damage_ptr> damageContainer;
Container<Ammunition_ptr> ammunitionContainer;
Container<Ammo_ptr> ammoContainer;
Container<Throwable_ptr> throwableContainer;
Container<CastFocus_ptr> castFocusContainer;
Container<Conditions_ptr> conditionsContainer;

bool testComponent(ID itemID, ItemCompList comp) {
	auto it = itemContainer.find(itemID);
	return it->second->chk_comp(comp);
}

std::string getItemName(ID itemID) {
	auto it = itemContainer.find(itemID);
	return it->second->chk_name();
}