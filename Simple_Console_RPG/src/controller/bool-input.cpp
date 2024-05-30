#include <iostream>
#include "includes\bool-input.h"

bool validBoolInput(WeaponEquip weaponEquip) {

	std::cout << std::endl;
	switch (weaponEquip)
	{
	case 0:
		std::cout << "Unequip left-hand to equip a two-handed weapon? [Y/N]:" << std::endl;
		break;
	case 1:
		std::cout << "Unequip right-hand to equip a two-handed weapon? [Y/N]:" << std::endl;
		break;
	case 2:
		std::cout << "Unequip both hands to equip a two-handed weapon? [Y/N]:" << std::endl;
		break;
	case 3:
		std::cout << "Unequip two-hand weapon to equip a weapon? [Y/N]:" << std::endl;
		break;
	case 4:
		std::cout << "Unequip two-hand weapon to equip a shield? [Y/N]:" << std::endl;
		break;
	default:
		break;
	}

	char charInput;

	std::cin >> charInput;

	switch (tolower(charInput))
	{
	case 'y':
		return true;
		break;
	case 'n':
		return false;
		break;
	default:
		validBoolInput(weaponEquip);
		break;
	}

}
