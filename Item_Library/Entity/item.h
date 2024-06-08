#ifndef ITEM
#define ITEM

#include "..\utils.h"

class Item {
public:
	Item(ID& nextID, std::string name, std::string desc);

	ID m_ID;
	CompSet components;
	std::string m_name;
	std::string m_desc;

	template <typename T>
	void addComponent(std::shared_ptr<T>& component, CompList comp) {
		components.emplace(comp, std::move(component));
	}

	template <typename T>
	std::shared_ptr<T>& getComponent(CompList comp) {
		auto it = components.find(comp);
		if (it != components.end())
		{
			return std::any_cast<std::shared_ptr<T>&>(it->second);
		}
		static std::shared_ptr<T> nullPtr;
		return nullPtr;
	}
};

using Item_ptr = std::unique_ptr<Item>;

#endif
