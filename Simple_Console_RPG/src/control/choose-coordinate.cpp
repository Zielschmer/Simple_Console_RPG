#include "includes\choose-coordinate.h"

std::string checkCoordinateInput(std::string& input) {

	std::cin >> input;

	input[0] = std::tolower(input[0]);

	switch (input[0])
	{
	case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
		break;
	default:
		std::cout << "Invalid coordinate!" << std::endl;
		checkCoordinateInput(input);
		break;
	}

	switch (input[1])
	{
	case '1': case '2': case '3': case '4': case '5': case '6':
		input[1] = input[1] - 1;
		break;
	default:
		std::cout << "Invalid coordinate!" << std::endl;
		checkCoordinateInput(input);
		break;
	}

	return input;
}

std::string validCoordinateInput() {

	std::string coordinate;

	coordinate = checkCoordinateInput(coordinate);

	return coordinate.substr(0, 2);

}