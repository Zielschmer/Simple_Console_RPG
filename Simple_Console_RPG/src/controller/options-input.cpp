#include <iostream>
#include "includes\options-input.h"

int validOptionInput(HandChoice handChoice) {

	std::cout << std::endl;
	switch (handChoice)
	{
	case UNEQUIP:
	{
		std::cout << "Unequip what hand?\n[A]Right\n[B]Left" << std::endl;
		break;
	}
	case EQUIP_HAND:
	{
		std::cout << "Equip what hand?\n[A]Right\n[B]Left" << std::endl;
		break;
	}
	default:
		break;
	}

	char option;
	std::cin >> option;

	option = tolower(option);

	switch (option)
	{
	case 'a':
		return 0;
		break;
	case 'b':
		return 1;
		break;
	default:
		validOptionInput(handChoice);
		break;
	}

}