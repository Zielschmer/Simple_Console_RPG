#include "includes\choose-bool.h"

bool validBoolInput() {

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
		validBoolInput();
		break;
	}

}
