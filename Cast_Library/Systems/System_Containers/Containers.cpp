#include "Containers.h"

#include "..\..\Entity\cast.h"
#include "..\..\Components\comp_casting.h"
#include "..\..\Components\comp_damage.h"
#include "..\..\Components\comp_healing.h"
#include "..\..\Components\comp_teleport.h"
#include "..\..\Components\comp_conditions.h"
#include "..\..\Components\comp_range.h"
#include "..\..\Components\comp_upcast.h"

Container<Cast_ptr> castContainer;
Container<Casting_ptr> castingContainer;
Container<Damage_ptr> damageContainer;
Container<Healing_ptr> healingContainer;
Container<Teleport_ptr> teleportContainer;
Container<Conditions_ptr> conditionsContainer;
Container<Range_ptr> rangeContainer;
Container<Upcast_ptr> upcastContainer;

bool testComponent(ID castID, CastCompList comp) {
	auto it = castContainer.find(castID);
	return it->second->chk_comp(comp);
}

std::string getCastName(ID castID) {
	auto it = castContainer.find(castID);
	return it->second->chk_name();
}