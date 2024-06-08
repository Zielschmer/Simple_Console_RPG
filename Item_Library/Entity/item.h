#ifndef ITEM
#define ITEM

#include "..\utils.h"

class Item {
public:
	Item(ID& nextID, const ID& ownerID, std::string name, std::string desc);

	const ID m_ID;

	template <typename T>
	void addComponent(std::shared_ptr<T>& component, CompList comp) {
		m_components.emplace(comp, std::move(component));
	}

	template <typename T>
	std::shared_ptr<T>& getComponent(CompList comp) {
		auto it = m_components.find(comp);
		if (it != m_components.end())
		{
			return std::any_cast<std::shared_ptr<T>&>(it->second);
		}
		static std::shared_ptr<T> nullPtr;
		return nullPtr;
	}
private:
	ID m_ownerID;
	CompSet m_components;
	std::string m_name;
	std::string m_desc;
};

using Item_ptr = std::unique_ptr<Item>;

#endif
