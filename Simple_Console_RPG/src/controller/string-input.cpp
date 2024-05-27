#include <iostream>

std::string validStringInput() {

	std::string stringInput;

	std::cin >> stringInput;

	if (stringInput.size() < 1) {
		std::cin >> stringInput;
	}

	if (stringInput == " ") {
		std::cin >> stringInput;
	}

	return stringInput;

}