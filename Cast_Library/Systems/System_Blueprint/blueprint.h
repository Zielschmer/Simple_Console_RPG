#ifndef CAST_BLUEPRINT
#define CAST_BLUEPRINT

#include <functional>

#include <utility>
#include <iostream>

#include "..\..\..\utilities\utils.h"
#include "..\..\Entity\cast.h"
#include "..\..\Components\comp_casting.h"
#include "..\..\Components\comp_upcast.h"
#include "..\..\Components\comp_saving.h"
#include "..\..\Components\comp_damage.h"
#include "..\..\Components\comp_healing.h"
#include "..\..\Components\comp_teleport.h"
#include "..\..\Components\comp_conditions.h"
#include "..\..\Components\comp_range.h"
#include "..\..\Components\comp_ricochet.h"

extern Container<Cast_ptr> castContainer;
extern Container<Casting_ptr> castingContainer;
extern Container<Upcast_ptr> upcastContainer;
extern Container<Saving_ptr> savingContainer;
extern Container<Damage_ptr> damageContainer;
extern Container<Healing_ptr> healingContainer;
extern Container<Teleport_ptr> teleportContainer;
extern Container<Conditions_ptr> conditionsContainer;
extern Container<Range_ptr> rangeContainer;
extern Container<Ricochet_ptr> ricochetContainer;

static ID CAST_ID = 2001;

class Blueprint {
public:
	std::vector<std::function<void(Cast&)>> componentAdders;

	CompSet compSet;

	void addComponent(CastCompList compList) {
		compSet.set(static_cast<int>(compList));
	}

	Cast_ptr instantiateCast(const ID& ownerID, CastType type, std::string name, std::string desc) {
		Cast* cast = new Cast(CAST_ID, ownerID, compSet, type, name, desc);
		for (auto& adder : componentAdders) {
			adder(*cast);
		}
		CAST_ID++;
		return std::move(std::unique_ptr<Cast>(cast));
	}
	template <typename T>
	void registerComponent(std::unique_ptr<T> component) {
		componentAdders.emplace_back([component = std::move(component)](Cast& cast) mutable { T().emplace_back(cast->m_ID, std::move(component)); });
	}
	template <>
	void registerComponent(std::unique_ptr<CompCasting> component) {
		castingContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompUpcast> component) {
		upcastContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompSaving> component) {
		upcastContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompDamage> component) {
		damageContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompHealing> component) {
		healingContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompTeleport> component) {
		teleportContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompConditions> component) {
		conditionsContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompRange> component) {
		rangeContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompRicochet> component) {
		upcastContainer;
	}
};

#endif
