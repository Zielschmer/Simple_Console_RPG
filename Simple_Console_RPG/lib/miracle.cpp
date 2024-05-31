#include "includes\miracle.h"

Miracle getMiracle(MiracleList miracleList) {

	Miracle newMiracle;

	switch (miracleList)
	{
	case TEND:
		newMiracle.m_name = "Tend";
		newMiracle.m_description = "Restore one ally's small amount of hit points.";
		newMiracle.m_isRevive = false;
		newMiracle.m_isHeal = true;
		newMiracle.m_isCure = false;
		newMiracle.m_isRestore = false;
		newMiracle.m_isArea = false;
		newMiracle.m_isAll = false;
		newMiracle.m_cost = 0;
		break;
	case HEAL:
		newMiracle.m_name = "Heal";
		newMiracle.m_description = "Restore one ally's hit points.";
		newMiracle.m_isRevive = false;
		newMiracle.m_isHeal = true;
		newMiracle.m_isCure = false;
		newMiracle.m_isRestore = false;
		newMiracle.m_isArea = false;
		newMiracle.m_isAll = false;
		newMiracle.m_cost = 1;
		break;
	case CURE:
		newMiracle.m_name = "Cure";
		newMiracle.m_description = "Cure one ally's conditions.";
		newMiracle.m_isRevive = false;
		newMiracle.m_isHeal = false;
		newMiracle.m_isCure = true;
		newMiracle.m_isRestore = false;
		newMiracle.m_isArea = false;
		newMiracle.m_isAll = false;
		newMiracle.m_cost = 1;
		break;
	case REVIVE:
		newMiracle.m_name = "Revive";
		newMiracle.m_description = "Revive one ally.";
		newMiracle.m_isRevive = true;
		newMiracle.m_isHeal = false;
		newMiracle.m_isCure = false;
		newMiracle.m_isRestore = false;
		newMiracle.m_isArea = false;
		newMiracle.m_isAll = false;
		newMiracle.m_cost = 2;
		break;
	case PRAY:
		newMiracle.m_name = "Pray";
		newMiracle.m_description = "Ask for divine punishment upon one enemy.";
		newMiracle.m_isRevive = false;
		newMiracle.m_isHeal = false;
		newMiracle.m_isCure = false;
		newMiracle.m_isRestore = false;
		newMiracle.m_isArea = false;
		newMiracle.m_isAll = false;
		newMiracle.m_cost = 1;
		break;
	case MASS_HEAL:
		newMiracle.m_name = "Mass Heal";
		newMiracle.m_description = "Restore all allies hit points.";
		newMiracle.m_isRevive = false;
		newMiracle.m_isHeal = true;
		newMiracle.m_isCure = false;
		newMiracle.m_isRestore = false;
		newMiracle.m_isArea = false;
		newMiracle.m_isAll = true;
		newMiracle.m_cost = 2;
		break;
	case MASS_CURE:
		newMiracle.m_name = "Mass Cure";
		newMiracle.m_description = "Cure all allies conditions.";
		newMiracle.m_isRevive = false;
		newMiracle.m_isHeal = false;
		newMiracle.m_isCure = true;
		newMiracle.m_isRestore = false;
		newMiracle.m_isArea = false;
		newMiracle.m_isAll = true;
		newMiracle.m_cost = 2;
		break;
	case SMITE:
		newMiracle.m_name = "Smite";
		newMiracle.m_description = "Ask for divine punishment upon one enemy and adjacents.";
		newMiracle.m_isRevive = false;
		newMiracle.m_isHeal = false;
		newMiracle.m_isCure = false;
		newMiracle.m_isRestore = false;
		newMiracle.m_isArea = true;
		newMiracle.m_isAll = false;
		newMiracle.m_cost = 2;
		break;
	case RESTORE:
		newMiracle.m_name = "Restore";
		newMiracle.m_description = "Fully restore one ally hit points.";
		newMiracle.m_isRevive = false;
		newMiracle.m_isHeal = false;
		newMiracle.m_isCure = false;
		newMiracle.m_isRestore = true;
		newMiracle.m_isArea = false;
		newMiracle.m_isAll = false;
		newMiracle.m_cost = 3;
		break;
	case REINCARNATE:
		newMiracle.m_name = "Reincarnate";
		newMiracle.m_description = "Revive one ally and fully restore their hit points.";
		newMiracle.m_isRevive = true;
		newMiracle.m_isHeal = false;
		newMiracle.m_isCure = false;
		newMiracle.m_isRestore = true;
		newMiracle.m_isArea = false;
		newMiracle.m_isAll = false;
		newMiracle.m_cost = 4;
		break;
	case JUDGMENT:
		newMiracle.m_name = "Judgment";
		newMiracle.m_description = "Ask for divine judgment upon all enemies.";
		newMiracle.m_isRevive = false;
		newMiracle.m_isHeal = false;
		newMiracle.m_isCure = false;
		newMiracle.m_isRestore = false;
		newMiracle.m_isArea = false;
		newMiracle.m_isAll = true;
		newMiracle.m_cost = 4;
		break;
	default:
		break;
	}

	return newMiracle;

}

std::string miracleLibrary(MiracleList miracleList) {

	switch (miracleList)
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