#include "includes\choose-option.h"

std::vector<char> validOptions;

OptionInput validOptionInput() {

	char option;
	std::cin >> option;
	option = std::tolower(option);

	for (auto valid : validOptions) {
		if (option == valid) {
			switch (option)
			{
			case 'a':
				return OPTION_A;
				break;
			case 'b':
				return OPTION_B;
				break;
			case 'c':
				return OPTION_C;
				break;
			case 'd':
				return OPTION_D;
				break;
			case 'e':
				return OPTION_E;
				break;
			case 'f':
				return OPTION_F;
				break;
			case 'g':
				return OPTION_G;
				break;
			case 'h':
				return OPTION_H;
				break;
			case 'i':
				return OPTION_I;
				break;
			case 'j':
				return OPTION_J;
				break;
			case 'n':
				return NEXT_PAGE;
				break;
			case 'p':
				return PREVIOUS_PAGE;
				break;
			case 'm':
				return MENU;
				break;
			case 's':
				return SAVE;
				break;
			case 'l':
				return LOAD;
				break;
			case 'r':
				return RETURN;
				break;
			case 'x':
				return EXIT;
				break;
			}
		}
	}
	
}