#include "combat_map.h"

#include "..\..\..\utilities\utils.h"

Map<6> map;

bool currentCoordinate(ID entityID, int& currentY, int& currentX) {
	for (auto axysY : map) {
		for (auto axysX : axysY) {
			if (axysX == entityID) {
				return true;
			}
			currentX++;
		}
		currentX = 0;
		currentY++;
	}
	return false;
}

void validPlacement(ID entityID) {
	int axysY = rand() % 5;
	int axysX = rand() % 6;
	if (map[axysY][axysX] == NULL) {
		map[axysY][axysX] = entityID;
	}
	else {
		validPlacement(entityID);
	}
}

void mapSetup(Party& partyID, Party& enemiesID) {

	for (auto axysY : map) {
		for (auto axysX : axysY) {
			axysX == NULL;
		}
	}

	int axysY = 5;
	int axysX = 0;
	for (auto member : partyID) {
		if(axysX < 6) {
			map[axysY][axysX] = member;
		}
		else {
			axysY--;
			axysX = 0;
			map[axysY][axysX] = member;
		}
		axysX++;
	}

	for (auto enemy : enemiesID) {
		validPlacement(enemy);
	}

}

bool moveCharacter(ID entityID, std::string coordinate, int speed) {

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

	if (!currentCoordinate(entityID, currentY, currentX)) {
		return false;
	}
	if ((abs(destineY - currentY) + abs(destineX - currentX)) > speed) {
		return false;
	}
	if (map[destineY][destineX] != NULL) {
		return false;
	}
	map[destineY][destineX] = entityID;
	map[currentY][currentX] = NULL;
	return true;

}

bool validTarget(int axysY, int axysX, Party& targetID) {
	if (map[axysY][axysX] != NULL) {
		for (auto target : targetID) {
			if (map[axysY][axysX] == target) {
				return true;
			}
		}
	}
	return false;
}

bool checkRange(ID attackerID, int range, Party& targetID, std::vector<int>& inRangeTargets) {

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
						if (validTarget((currentY + y), (currentX + x), targetID)) {
							inRangeTargets.emplace_back(map[currentY + y][currentX + x]);
						}
					}
					else if (abs(y) + abs(x) <= range) {
						if (validTarget((currentY + y), (currentX + x), targetID)) {
							inRangeTargets.emplace_back(map[currentY + y][currentX + x]);
						}
					}
				}
			}
			//check negative X axys
			for (int x = (-1); abs(x) <= range && abs(x) < 6; x--) {
				if (currentX + x >= 0) {
					if (abs(y) == abs(x)) {
						if (validTarget((currentY + y), (currentX + x), targetID)) {
							inRangeTargets.emplace_back(map[currentY + y][currentX + x]);
						}
					}
					else if (abs(y) + abs(x) <= range) {
						if (validTarget((currentY + y), (currentX + x), targetID)) {
							inRangeTargets.emplace_back(map[currentY + y][currentX + x]);
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
						if (validTarget((currentY + y), (currentX + x), targetID)) {
							inRangeTargets.emplace_back(map[currentY + y][currentX + x]);
						}
					}
					else if (abs(y) + abs(x) <= range) {
						if (validTarget((currentY + y), (currentX + x), targetID)) {
							inRangeTargets.emplace_back(map[currentY + y][currentX + x]);
						}
					}
				}
			}
			//check negative X axys
			for (int x = (-1); abs(x) <= range && abs(x) < 6; x--) {
				if (currentX + x >= 0) {
					if (abs(y) == abs(x)) {
						if (validTarget((currentY + y), (currentX + x), targetID)) {
							inRangeTargets.emplace_back(map[currentY + y][currentX + x]);
						}
					}
					else if (abs(y) + abs(x) <= range) {
						if (validTarget((currentY + y), (currentX + x), targetID)) {
							inRangeTargets.emplace_back(map[currentY + y][currentX + x]);
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