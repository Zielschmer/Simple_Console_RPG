#include "item.h"

Item::Item(ID& nextID, std::string name, std::string desc, std::string compset)
	: m_ID(nextID), m_name(name), m_desc(desc), m_compset(compset) {}

ID& Item::getID() { return m_ID; }
std::string& Item::getName() { return m_name; }
std::string& Item::getDesc() { return m_desc; }

bool Item::chk_comp(CompList comp) {
	switch (comp)
	{
	case COMP_CONSUMABLE:
		return m_compset.test(0);
		break;
	case COMP_POINTSREGEN:
		return m_compset.test(1);
		break;
	case COMP_ATTACK:
		return m_compset.test(2);
		break;
	case COMP_DEFENSE:
		return m_compset.test(3);
		break;
	case AMMUNITION:
		return m_compset.test(4);
		break;
	case CAST_FOCUS:
		return m_compset.test(5);
		break;
	default:
		break;
	}
}
bool Item::add_comp(CompList comp) {
	switch (comp)
	{
	case COMP_CONSUMABLE:
		m_compset.set(0);
		break;
	case COMP_POINTSREGEN:
		m_compset.set(1);
		break;
	case COMP_ATTACK:
		m_compset.set(2);
		break;
	case COMP_DEFENSE:
		m_compset.set(3);
		break;
	case AMMUNITION:
		m_compset.set(4);
		break;
	case CAST_FOCUS:
		m_compset.set(5);
		break;
	default:
		return false;
		break;
	}
	return true;
}