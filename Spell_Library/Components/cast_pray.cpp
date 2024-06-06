#include "includes\cast_pray.h"

Pray getPray(PrayList prayList) {

	Pray newPray;

	switch (prayList)
	{
	case TEND:
		newPray.m_name = "Tend";
		newPray.m_description = "Restore one ally's small amount of hit points.";
		newPray.m_isRevive = false;
		newPray.m_isHeal = true;
		newPray.m_isCure = false;
		newPray.m_isRestore = false;
		newPray.m_isArea = false;
		newPray.m_isAll = false;
		newPray.m_cost = 0;
		break;
	case HEAL:
		newPray.m_name = "Heal";
		newPray.m_description = "Restore one ally's hit points.";
		newPray.m_isRevive = false;
		newPray.m_isHeal = true;
		newPray.m_isCure = false;
		newPray.m_isRestore = false;
		newPray.m_isArea = false;
		newPray.m_isAll = false;
		newPray.m_cost = 1;
		break;
	case CURE:
		newPray.m_name = "Cure";
		newPray.m_description = "Cure one ally's conditions.";
		newPray.m_isRevive = false;
		newPray.m_isHeal = false;
		newPray.m_isCure = true;
		newPray.m_isRestore = false;
		newPray.m_isArea = false;
		newPray.m_isAll = false;
		newPray.m_cost = 1;
		break;
	case REVIVE:
		newPray.m_name = "Revive";
		newPray.m_description = "Revive one ally.";
		newPray.m_isRevive = true;
		newPray.m_isHeal = false;
		newPray.m_isCure = false;
		newPray.m_isRestore = false;
		newPray.m_isArea = false;
		newPray.m_isAll = false;
		newPray.m_cost = 2;
		break;
	case PRAY:
		newPray.m_name = "Pray";
		newPray.m_description = "Ask for divine punishment upon one enemy.";
		newPray.m_isRevive = false;
		newPray.m_isHeal = false;
		newPray.m_isCure = false;
		newPray.m_isRestore = false;
		newPray.m_isArea = false;
		newPray.m_isAll = false;
		newPray.m_cost = 1;
		break;
	case MASS_HEAL:
		newPray.m_name = "Mass Heal";
		newPray.m_description = "Restore all allies hit points.";
		newPray.m_isRevive = false;
		newPray.m_isHeal = true;
		newPray.m_isCure = false;
		newPray.m_isRestore = false;
		newPray.m_isArea = false;
		newPray.m_isAll = true;
		newPray.m_cost = 2;
		break;
	case MASS_CURE:
		newPray.m_name = "Mass Cure";
		newPray.m_description = "Cure all allies conditions.";
		newPray.m_isRevive = false;
		newPray.m_isHeal = false;
		newPray.m_isCure = true;
		newPray.m_isRestore = false;
		newPray.m_isArea = false;
		newPray.m_isAll = true;
		newPray.m_cost = 2;
		break;
	case SMITE:
		newPray.m_name = "Smite";
		newPray.m_description = "Ask for divine punishment upon one enemy and adjacents.";
		newPray.m_isRevive = false;
		newPray.m_isHeal = false;
		newPray.m_isCure = false;
		newPray.m_isRestore = false;
		newPray.m_isArea = true;
		newPray.m_isAll = false;
		newPray.m_cost = 2;
		break;
	case RESTORE:
		newPray.m_name = "Restore";
		newPray.m_description = "Fully restore one ally hit points.";
		newPray.m_isRevive = false;
		newPray.m_isHeal = false;
		newPray.m_isCure = false;
		newPray.m_isRestore = true;
		newPray.m_isArea = false;
		newPray.m_isAll = false;
		newPray.m_cost = 3;
		break;
	case REINCARNATE:
		newPray.m_name = "Reincarnate";
		newPray.m_description = "Revive one ally and fully restore their hit points.";
		newPray.m_isRevive = true;
		newPray.m_isHeal = false;
		newPray.m_isCure = false;
		newPray.m_isRestore = true;
		newPray.m_isArea = false;
		newPray.m_isAll = false;
		newPray.m_cost = 4;
		break;
	case JUDGMENT:
		newPray.m_name = "Judgment";
		newPray.m_description = "Ask for divine judgment upon all enemies.";
		newPray.m_isRevive = false;
		newPray.m_isHeal = false;
		newPray.m_isCure = false;
		newPray.m_isRestore = false;
		newPray.m_isArea = false;
		newPray.m_isAll = true;
		newPray.m_cost = 4;
		break;
	default:
		break;
	}

	return newPray;

}

std::string prayLibrary(PrayList prayList) {

	switch (prayList)
	{
	case TEND:
		return "Tend";
		break;
	case HEAL:
		return "Heal";
		break;
	case CURE:
		return "Cure";
		break;
	case REVIVE:
		return "Revive";
		break;
	case PRAY:
		return "Pray";
		break;
	case MASS_HEAL:
		return "Mass Heal";
		break;
	case MASS_CURE:
		return "Mass Cure";
		break;
	case SMITE:
		return "Smite";
		break;
	case RESTORE:
		return "Restore";
		break;
	case REINCARNATE:
		return "Reincarnate";
		break;
	case JUDGMENT:
		return "Judgment";
		break;
	default:
		break;
	}

}