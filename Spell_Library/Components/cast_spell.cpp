#include "cast_spell.h"

Spell getSpell(SpellList spellList) {

	Spell newSpell;

	switch (spellList)
	{
	case 0:
	{
		newSpell.m_name = "Magic Missile";
		newSpell.m_description = "Hit one enemy with a magical projectile.";
		newSpell.m_isTeleport = false;
		newSpell.m_isPortal = false;
		newSpell.m_isArea = false;
		newSpell.m_isAll = false;
		newSpell.m_damageType = 0;
		newSpell.m_cost = 0;
		break;
	}
	case 1:
	{
		newSpell.m_name = "Flare";
		newSpell.m_description = "Set one enemy ablaze.";
		newSpell.m_isTeleport = false;
		newSpell.m_isPortal = false;
		newSpell.m_isArea = false;
		newSpell.m_isAll = false;
		newSpell.m_damageType = 1;
		newSpell.m_cost = 1;
		break;
	}
	case 2:
	{
		newSpell.m_name = "Freeze";
		newSpell.m_description = "Freeze one enemy.";
		newSpell.m_isTeleport = false;
		newSpell.m_isPortal = false;
		newSpell.m_isArea = false;
		newSpell.m_isAll = false;
		newSpell.m_damageType = 2;
		newSpell.m_cost = 1;
		break;
	}
	case 3:
	{
		newSpell.m_name = "Shock";
		newSpell.m_description = "Eletrocute one enemy.";
		newSpell.m_isTeleport = false;
		newSpell.m_isPortal = false;
		newSpell.m_isArea = false;
		newSpell.m_isAll = false;
		newSpell.m_damageType = 3;
		newSpell.m_cost = 1;
		break;
	}
	case 4:
	{
		newSpell.m_name = "Teleport";
		newSpell.m_description = "Escape the dungeon.";
		newSpell.m_isTeleport = true;
		newSpell.m_isPortal = false;
		newSpell.m_isArea = false;
		newSpell.m_isAll = false;
		newSpell.m_damageType = 0;
		newSpell.m_cost = 1;
		break;
	}
	case 5:
	{
		newSpell.m_name = "Flame";
		newSpell.m_description = "Set an enemy and adjacents ablaze.";
		newSpell.m_isTeleport = false;
		newSpell.m_isPortal = false;
		newSpell.m_isArea = true;
		newSpell.m_isAll = false;
		newSpell.m_damageType = 1;
		newSpell.m_cost = 2;
		break;
	}
	case 6:
	{
		newSpell.m_name = "Blizzard";
		newSpell.m_description = "Freeze an enemy and adjacents.";
		newSpell.m_isTeleport = false;
		newSpell.m_isPortal = false;
		newSpell.m_isArea = true;
		newSpell.m_isAll = false;
		newSpell.m_damageType = 2;
		newSpell.m_cost = 2;
		break;
	}
	case 7:
	{
		newSpell.m_name = "Bolt";
		newSpell.m_description = "Eletrocute an enemy and adjacents.";
		newSpell.m_isTeleport = false;
		newSpell.m_isPortal = false;
		newSpell.m_isArea = true;
		newSpell.m_isAll = false;
		newSpell.m_damageType = 3;
		newSpell.m_cost = 2;
		break;
	}
	case 8:
	{
		newSpell.m_name = "Portal";
		newSpell.m_description = "Create a portal to the city and back.";
		newSpell.m_isTeleport = false;
		newSpell.m_isPortal = true;
		newSpell.m_isArea = false;
		newSpell.m_isAll = false;
		newSpell.m_damageType = 0;
		newSpell.m_cost = 2;
		break;
	}
	case 9:
	{
		newSpell.m_name = "Inferno";
		newSpell.m_description = "Set all enemies ablaze.";
		newSpell.m_isTeleport = false;
		newSpell.m_isPortal = false;
		newSpell.m_isArea = false;
		newSpell.m_isAll = true;
		newSpell.m_damageType = 1;
		newSpell.m_cost = 3;
		break;
	}
	case 10:
	{
		newSpell.m_name = "Cocitus";
		newSpell.m_description = "Freeze all enemies.";
		newSpell.m_isTeleport = false;
		newSpell.m_isPortal = false;
		newSpell.m_isArea = false;
		newSpell.m_isAll = true;
		newSpell.m_damageType = 2;
		newSpell.m_cost = 3;
		break;
	}
	case 11:
	{
		newSpell.m_name = "Storm";
		newSpell.m_description = "Electrocute all enemies.";
		newSpell.m_isTeleport = false;
		newSpell.m_isPortal = false;
		newSpell.m_isArea = false;
		newSpell.m_isAll = true;
		newSpell.m_damageType = 3;
		newSpell.m_cost = 3;
		break;
	}
	default:
		break;
	}
	return newSpell;
}

std::string spellLibrary(SpellList spellList) {

	switch (spellList)
	{
	case 0:
	{
		return "Magic Missile";
	}
	case 1:
	{
		return "Flare";
	}
	case 2:
	{
		return "Freeze";
	}
	case 3:
	{
		return "Shock";
	}
	case 4:
	{
		return "Teleport";
	}
	case 5:
	{
		return "Flame";
	}
	case 6:
	{
		return "Blizzard";
	}
	case 7:
	{
		return "Bolt";
	}
	case 8:
	{
		return "Portal";
	}
	case 9:
	{
		return "Inferno";
	}
	case 10:
	{
		return "Cocitus";
	}
	case 11:
	{
		return "Storm";
	}
	default:
		break;
	}

}