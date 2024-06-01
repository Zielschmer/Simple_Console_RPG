#include "includes\combat-map.h"

std::array<std::array<int, 6>, 6> combatArea;


bool currentCoordinate(int characterID, int& currentY, int& currentX) {
	for (auto axysY : combatArea) {
		for (auto axysX : axysY) {
			if (axysX == characterID) {
				return true;
			}
			currentX++;
		}
		currentX = 0;
		currentY++;
	}
	return false;
}

void validPlacement(int creature) {
	int axysY = rand() % 5;
	int axysX = rand() % 6;
	if (combatArea[axysY][axysX] == NULL) {
		combatArea[axysY][axysX] = creature;
	}
	else {
		validPlacement(creature);
	}
}

void combatAreaSetup(std::vector<int>& party, std::vector<int>& enemies) {

	for (auto axysY : combatArea) {
		for (auto axysX : axysY) {
			axysX == NULL;
		}
	}

	int axysY = 5;
	int axysX = 0;
	for (auto member : party) {
		if(axysX < 6) {
			combatArea[axysY][axysX] = member;
		}
		else {
			axysY--;
			axysX = 0;
			combatArea[axysY][axysX] = member;
		}
		axysX++;
	}

	for (auto enemy : enemies) {
		validPlacement(enemy);
	}

}

bool moveCharacter(int characterID, std::string coordinate, int speed) {

	int currentY = 0;
	int currentX = 0;
	int destineY;
	int destineX;

	switch (coordinate[0])
	{
	case 'a':
		destineY = 0;
		break;
	case 'b':
		destineY = 1;
		break;
	case 'c':
		destineY = 2;
		break;
	case 'd':
		destineY = 3;
		break;
	case 'e':
		destineY = 4;
		break;
	case 'f':
		destineY = 5;
		break;
	default:
		return false;
		break;
	}

	destineX = coordinate[1] - '0';

	if (!currentCoordinate(characterID, currentY, currentX)) {
		return false;
	}
	if ((abs(destineY - currentY) + abs(destineX - currentX)) > speed) {
		return false;
	}
	if (combatArea[destineY][destineX] != NULL) {
		return false;
	}
	combatArea[destineY][destineX] = characterID;
	combatArea[currentY][currentX] = NULL;
	return true;

}

bool validTarget(int axysY, int axysX, std::vector<int>& targetParty) {
	if (combatArea[axysY][axysX] != NULL) {
		for (auto target : targetParty) {
			if (combatArea[axysY][axysX] == target) {
				return true;
			}
		}
	}
	return false;
}

bool checkRange(int attackerID, int range, std::vector<int>& targetParty, std::vector<int>& inRangeTargets) {

	int currentY = 0;
	int currentX = 0;

	currentCoordinate(attackerID, currentY, currentX);

	//check positive Y axys
	for (int y = 0; y <= range && y < 6; y++) {
		if(currentY + y < 6) {
			//check positive X axys
			for (int x = 0; x <= range && x < 6; x++) {
				if(currentX + x < 6) {
					if (abs(y) == abs(x)) {
						if (validTarget((currentY + y), (currentX + x), targetParty)) {
							inRangeTargets.emplace_back(combatArea[currentY + y][currentX + x]);
						}
					}
					else if (abs(y) + abs(x) <= range) {
						if (validTarget((currentY + y), (currentX + x), targetParty)) {
							inRangeTargets.emplace_back(combatArea[currentY + y][currentX + x]);
						}
					}
				}
			}
			//check negative X axys
			for (int x = (-1); abs(x) <= range && abs(x) < 6; x--) {
				if (currentX + x >= 0) {
					if (abs(y) == abs(x)) {
						if (validTarget((currentY + y), (currentX + x), targetParty)) {
							inRangeTargets.emplace_back(combatArea[currentY + y][currentX + x]);
						}
					}
					else if (abs(y) + abs(x) <= range) {
						if (validTarget((currentY + y), (currentX + x), targetParty)) {
							inRangeTargets.emplace_back(combatArea[currentY + y][currentX + x]);
						}
					}
				}
			}
		}
	}
	//check negative Y axys
	for (int y = (-1); abs(y) <= range && abs(y) < 6; y--) {
		if (currentY + y >= 0) {
			//check positive X axys
			for (int x = 0; x <= range && x < 6; x++) {
				if (currentX + x < 6) {
					if (abs(y) == abs(x)) {
						if (validTarget((currentY + y), (currentX + x), targetParty)) {
							inRangeTargets.emplace_back(combatArea[currentY + y][currentX + x]);
						}
					}
					else if (abs(y) + abs(x) <= range) {
						if (validTarget((currentY + y), (currentX + x), targetParty)) {
							inRangeTargets.emplace_back(combatArea[currentY + y][currentX + x]);
						}
					}
				}
			}
			//check negative X axys
			for (int x = (-1); abs(x) <= range && abs(x) < 6; x--) {
				if (currentX + x >= 0) {
					if (abs(y) == abs(x)) {
						if (validTarget((currentY + y), (currentX + x), targetParty)) {
							inRangeTargets.emplace_back(combatArea[currentY + y][currentX + x]);
						}
					}
					else if (abs(y) + abs(x) <= range) {
						if (validTarget((currentY + y), (currentX + x), targetParty)) {
							inRangeTargets.emplace_back(combatArea[currentY + y][currentX + x]);
						}
					}
				}
			}
		}
	}

	if (inRangeTargets.empty())	{
		return false;
	}
	return true;

}