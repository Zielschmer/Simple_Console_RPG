#include "includes\spells.h"

Spell getMagicMissile() {

	Spell newSpell;

	newSpell.m_name = "Magic Missile";
	newSpell.m_description = "Hit one enemy with a magical projectile.";
	newSpell.m_isTeleport = false;
	newSpell.m_isPortal = false;
	newSpell.m_isArea = false;
	newSpell.m_isAll = false;
	newSpell.m_damageType = 0;
	newSpell.m_cost = 0;

	return newSpell;

}

Spell getFlare() {

	Spell newSpell;

	newSpell.m_name = "Flare";
	newSpell.m_description = "Set one enemy ablaze.";
	newSpell.m_isTeleport = false;
	newSpell.m_isPortal = false;
	newSpell.m_isArea = false;
	newSpell.m_isAll = false;
	newSpell.m_damageType = 1;
	newSpell.m_cost = 1;

	return newSpell;

}

Spell getFreeze() {

	Spell newSpell;

	newSpell.m_name = "Freeze";
	newSpell.m_description = "Freeze one enemy.";
	newSpell.m_isTeleport = false;
	newSpell.m_isPortal = false;
	newSpell.m_isArea = false;
	newSpell.m_isAll = false;
	newSpell.m_damageType = 2;
	newSpell.m_cost = 1;

	return newSpell;

}

Spell getShock() {

	Spell newSpell;

	newSpell.m_name = "Shock";
	newSpell.m_description = "Eletrocute one enemy.";
	newSpell.m_isTeleport = false;
	newSpell.m_isPortal = false;
	newSpell.m_isArea = false;
	newSpell.m_isAll = false;
	newSpell.m_damageType = 3;
	newSpell.m_cost = 1;

	return newSpell;

}

Spell getTeleport() {

	Spell newSpell;

	newSpell.m_name = "Teleport";
	newSpell.m_description = "Escape the dungeon.";
	newSpell.m_isTeleport = true;
	newSpell.m_isPortal = false;
	newSpell.m_isArea = false;
	newSpell.m_isAll = false;
	newSpell.m_damageType = 0;
	newSpell.m_cost = 1;

	return newSpell;

}

Spell getFlame() {

	Spell newSpell;

	newSpell.m_name = "Flame";
	newSpell.m_description = "Set an enemy and adjacents ablaze.";
	newSpell.m_isTeleport = false;
	newSpell.m_isPortal = false;
	newSpell.m_isArea = true;
	newSpell.m_isAll = false;
	newSpell.m_damageType = 1;
	newSpell.m_cost = 2;

	return newSpell;

}

Spell getIce() {

	Spell newSpell;

	newSpell.m_name = "Ice";
	newSpell.m_description = "Freeze an enemy and adjacents.";
	newSpell.m_isTeleport = false;
	newSpell.m_isPortal = false;
	newSpell.m_isArea = true;
	newSpell.m_isAll = false;
	newSpell.m_damageType = 2;
	newSpell.m_cost = 2;

	return newSpell;

}

Spell getLightning() {

	Spell newSpell;

	newSpell.m_name = "Lightning";
	newSpell.m_description = "Eletrocute an enemy and adjacents.";
	newSpell.m_isTeleport = false;
	newSpell.m_isPortal = false;
	newSpell.m_isArea = true;
	newSpell.m_isAll = false;
	newSpell.m_damageType = 3;
	newSpell.m_cost = 2;

	return newSpell;

}

Spell getPortal() {

	Spell newSpell;

	newSpell.m_name = "Portal";
	newSpell.m_description = "Create a portal to the city and back.";
	newSpell.m_isTeleport = false;
	newSpell.m_isPortal = true;
	newSpell.m_isArea = false;
	newSpell.m_isAll = false;
	newSpell.m_damageType = 0;
	newSpell.m_cost = 2;

	return newSpell;

}

Spell getInferno() {

	Spell newSpell;

	newSpell.m_name = "Inferno";
	newSpell.m_description = "Set all enemies ablaze.";
	newSpell.m_isTeleport = false;
	newSpell.m_isPortal = false;
	newSpell.m_isArea = false;
	newSpell.m_isAll = true;
	newSpell.m_damageType = 1;
	newSpell.m_cost = 3;

	return newSpell;

}

Spell getCocitus() {

	Spell newSpell;

	newSpell.m_name = "Cocitus";
	newSpell.m_description = "Freeze all enemies.";
	newSpell.m_isTeleport = false;
	newSpell.m_isPortal = false;
	newSpell.m_isArea = false;
	newSpell.m_isAll = true;
	newSpell.m_damageType = 2;
	newSpell.m_cost = 3;

	return newSpell;

}

Spell getTempest() {

	Spell newSpell;

	newSpell.m_name = "Tempest";
	newSpell.m_description = "Electrocute all enemies.";
	newSpell.m_isTeleport = false;
	newSpell.m_isPortal = false;
	newSpell.m_isArea = false;
	newSpell.m_isAll = true;
	newSpell.m_damageType = 3;
	newSpell.m_cost = 3;

	return newSpell;

}