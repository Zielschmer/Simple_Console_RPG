#pragma once

#include <iostream>
#include <vector>

extern std::vector<char> validOptions;

enum OptionInput {

	OPTION_A,
	OPTION_B,
	OPTION_C,
	OPTION_D,
	OPTION_E,
	OPTION_F,
	OPTION_G,
	OPTION_H,
	OPTION_I,
	OPTION_J,
	NEXT_PAGE,
	PREVIOUS_PAGE,
	MENU,
	SAVE,
	LOAD,
	RETURN,
	EXIT

};

OptionInput validOptionInput();