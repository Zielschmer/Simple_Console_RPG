#ifndef ITEM_BLUEPRINT
#define ITEM_BLUEPRINT

#include <functional>

#include <utility>
#include <iostream>

#include "..\..\utils.h"
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
#include "..\System_Containers\Containers.h"

extern Container<Item_ptr> itemContainer;
extern Container<Consumable_ptr> consumableContainer;
extern Container<PointsRegen_ptr> pointsRegenContainer;
extern Container<Attack_ptr> attackContainer;
extern Container<Defense_ptr> defenseContainer;
extern Container<Equipable_ptr> equipableContainer;
extern Container<Damage_ptr> damageContainer;
extern Container<Ammunition_ptr> ammunitionContainer;
extern Container<Ammo_ptr> ammoContainer;
extern Container<Throwable_ptr> throwableContainer;
extern Container<CastFocus_ptr> castFocusContainer;
extern Container<Conditions_ptr> conditionsContainer;

static ID ITEM_ID = 1;

class Blueprint {
public:
	std::vector<std::function<void(Item&)>> componentAdders;

	CompSet compSet;

	void addComponent(ItemCompList compList) {
		compSet.set(static_cast<int>(compList));
	}

	Item_ptr instantiateItem(const ID& ownerID, std::string name, std::string desc) {
		Item* item = new Item(ITEM_ID, ownerID, compSet, name, desc);
		for (auto& adder : componentAdders) {
			adder(*item);
		}
		ITEM_ID++;
		return std::move(std::unique_ptr<Item>(item));
	}
	template <typename T>
	void registerComponent(std::unique_ptr<T> component) {
		componentAdders.emplace_back([component = std::move(component)](Item& item) mutable { T().emplace_back(item->m_ID, std::move(component)); });
	}
	template <>
	void registerComponent(std::unique_ptr<CompConsumable> component) {
		consumableContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompPointsRegen> component) {
		pointsRegenContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompEquipable> component) {
		equipableContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompAttack> component) {
		attackContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompDamage> component) {
		damageContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompDefense> component) {
		defenseContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompAmmunition> component) {
		ammunitionContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompAmmo> component) {
		ammoContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompThrowable> component) {
		throwableContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompCastFocus> component) {
		castFocusContainer;
	}
	template <>
	void registerComponent(std::unique_ptr<CompConditions> component) {
		conditionsContainer;
	}
};

#endif
