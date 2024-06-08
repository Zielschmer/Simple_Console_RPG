#ifndef ITEM_BLUEPRINT
#define ITEM_BLUEPRINT

#include <functional>

#include <utility>

#include "..\..\utils.h"
#include "..\System_Containers\Containers.h"

class Blueprint {
public:
	std::vector<std::function<void(Item&)>> componentAdders;

	Item_ptr instantiateItem(ID& nextID, const ID& ownerID, std::string name, std::string desc) {
		Item* item = new Item(nextID, ownerID, name, desc);
		for (auto& adder : componentAdders) {
			adder(*item);
		}
		nextID++;
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
	void registerComponent(std::unique_ptr<CompEquipable> component) {
		equipableContainer;
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
