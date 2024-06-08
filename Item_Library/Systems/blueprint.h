#ifndef SYSTEM_COMPONENTS
#define SYSTEM_COMPONENTS

#include <functional>

#include <utility>

#include "..\utils.h"
#include "..\Entity\item.h"

class Blueprint {
public:
	std::vector<std::function<void(Item*)>> componentAdders;

	Item_ptr createItem(ID& nextID, std::string name, std::string desc) {
		auto item = std::make_unique<Item>(nextID, name, desc);
		for (auto& adder : componentAdders) {
			adder(item.get());
		}
		return item;
	}
	template <typename T>
	void registerComponent(std::shared_ptr<T>& component, CompList comp) {
		componentAdders.emplace_back([component, comp](Item* item) mutable { item->addComponent(component, comp); });
	}

};

#endif
