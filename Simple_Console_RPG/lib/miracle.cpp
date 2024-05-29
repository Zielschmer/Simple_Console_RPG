#include "includes\cast.h"

Miracle getTend() {

	Miracle newMiracle;

	newMiracle.m_name = "Tend";
	newMiracle.m_description = "Restore one ally's small amount of hit points.";
	newMiracle.m_isRevive = false;
	newMiracle.m_isHeal = true;
	newMiracle.m_isCure = false;
	newMiracle.m_isRestore = false;
	newMiracle.m_isArea = false;
	newMiracle.m_isAll = false;
	newMiracle.m_cost = 0;

	return newMiracle;

}

Miracle getHeal () {

	Miracle newMiracle;

	newMiracle.m_name = "Heal";
	newMiracle.m_description = "Restore one ally's hit points.";
	newMiracle.m_isRevive = false;
	newMiracle.m_isHeal = true;
	newMiracle.m_isCure = false;
	newMiracle.m_isRestore = false;
	newMiracle.m_isArea = false;
	newMiracle.m_isAll = false;
	newMiracle.m_cost = 1;

	return newMiracle;

}

Miracle getCure() {

	Miracle newMiracle;

	newMiracle.m_name = "Cure";
	newMiracle.m_description = "Cure one ally's conditions.";
	newMiracle.m_isRevive = false;
	newMiracle.m_isHeal = false;
	newMiracle.m_isCure = true;
	newMiracle.m_isRestore = false;
	newMiracle.m_isArea = false;
	newMiracle.m_isAll = false;
	newMiracle.m_cost = 1;

	return newMiracle;

}

Miracle getRevive() {

	Miracle newMiracle;

	newMiracle.m_name = "Revive";
	newMiracle.m_description = "Revive one ally.";
	newMiracle.m_isRevive = true;
	newMiracle.m_isHeal = false;
	newMiracle.m_isCure = false;
	newMiracle.m_isRestore = false;
	newMiracle.m_isArea = false;
	newMiracle.m_isAll = false;
	newMiracle.m_cost = 2;

	return newMiracle;

}

Miracle getPray() {

	Miracle newMiracle;

	newMiracle.m_name = "Pray";
	newMiracle.m_description = "Ask for divine punishment upon one enemy.";
	newMiracle.m_isRevive = false;
	newMiracle.m_isHeal = false;
	newMiracle.m_isCure = false;
	newMiracle.m_isRestore = false;
	newMiracle.m_isArea = false;
	newMiracle.m_isAll = false;
	newMiracle.m_cost = 1;

	return newMiracle;

}

Miracle getMassHeal() {

	Miracle newMiracle;

	newMiracle.m_name = "Mass Heal";
	newMiracle.m_description = "Restore all allies hit points.";
	newMiracle.m_isRevive = false;
	newMiracle.m_isHeal = true;
	newMiracle.m_isCure = false;
	newMiracle.m_isRestore = false;
	newMiracle.m_isArea = false;
	newMiracle.m_isAll = true;
	newMiracle.m_cost = 2;

	return newMiracle;

}

Miracle getMassCure() {

	Miracle newMiracle;

	newMiracle.m_name = "Mass Cure";
	newMiracle.m_description = "Cure all allies conditions.";
	newMiracle.m_isRevive = false;
	newMiracle.m_isHeal = false;
	newMiracle.m_isCure = true;
	newMiracle.m_isRestore = false;
	newMiracle.m_isArea = false;
	newMiracle.m_isAll = true;
	newMiracle.m_cost = 2;

	return newMiracle;

}

Miracle getSmite() {

	Miracle newMiracle;

	newMiracle.m_name = "Smite";
	newMiracle.m_description = "Ask for divine punishment upon one enemy and adjacents.";
	newMiracle.m_isRevive = false;
	newMiracle.m_isHeal = false;
	newMiracle.m_isCure = false;
	newMiracle.m_isRestore = false;
	newMiracle.m_isArea = true;
	newMiracle.m_isAll = false;
	newMiracle.m_cost = 2;

	return newMiracle;

}

Miracle getRestore() {

	Miracle newMiracle;

	newMiracle.m_name = "Restore";
	newMiracle.m_description = "Fully restore one ally hit points.";
	newMiracle.m_isRevive = false;
	newMiracle.m_isHeal = false;
	newMiracle.m_isCure = false;
	newMiracle.m_isRestore = true;
	newMiracle.m_isArea = false;
	newMiracle.m_isAll = false;
	newMiracle.m_cost = 3;

	return newMiracle;

}

Miracle getReincarnate() {

	Miracle newMiracle;

	newMiracle.m_name = "Reincarnate";
	newMiracle.m_description = "Revive one ally and fully restore their hit points.";
	newMiracle.m_isRevive = true;
	newMiracle.m_isHeal = false;
	newMiracle.m_isCure = false;
	newMiracle.m_isRestore = true;
	newMiracle.m_isArea = false;
	newMiracle.m_isAll = false;
	newMiracle.m_cost = 4;

	return newMiracle;

}

Miracle getJudgment() {

	Miracle newMiracle;

	newMiracle.m_name = "Judgment";
	newMiracle.m_description = "Ask for divine judgment upon all enemies.";
	newMiracle.m_isRevive = false;
	newMiracle.m_isHeal = false;
	newMiracle.m_isCure = false;
	newMiracle.m_isRestore = false;
	newMiracle.m_isArea = false;
	newMiracle.m_isAll = true;
	newMiracle.m_cost = 4;

	return newMiracle;

}