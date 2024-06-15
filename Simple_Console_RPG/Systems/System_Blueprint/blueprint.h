#ifndef ENTITY_BLUEPRINT
#define ENTITY_BLUEPRINT

#include <functional>

#include <utility>
#include <iostream>

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

static ID ENTITY_ID = 1;

class Blueprint {
public:
	std::vector<std::function<void(Entity&)>> componentAdders;

	CompSet compSet;

	void addComponent(CompList compList) {
		compSet.set(static_cast<int>(compList));
	}

	Entity_ptr instantiateEntity(const ID& ownerID) {
		Entity* entity = new Entity(ENTITY_ID, compSet);
		for (auto& adder : componentAdders) {
			adder(*entity);
		}
		ENTITY_ID++;
		return std::move(std::unique_ptr<Entity>(entity));
	}
	template <typename T>
	void registerComponent(std::unique_ptr<T> component) {
		componentAdders.emplace_back([component = std::move(component)](Entity& entity) mutable { T().emplace_back(entity->m_ID, std::move(component)); });
	}
	template <>
	void registerComponent(std::unique_ptr<CompScore> component) {
		scoreContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompInfo> component) {
		infoContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompLevel> component) {
		levelContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompPoints> component) {
		pointsContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompStats> component) {
		statsContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompArmor> component) {
		armorContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompMainHand> component) {
		mainHandContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompOffHand> component) {
		offHandContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompCast> component) {
		castContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompNatArmor> component) {
		natArmorContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompNatWeapons> component) {
		natWeaponsContainer;
	}
};

#endif
