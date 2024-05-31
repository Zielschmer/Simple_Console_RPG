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