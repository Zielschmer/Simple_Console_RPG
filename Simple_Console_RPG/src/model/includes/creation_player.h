#pragma once

#include "..\..\..\lib\includes\lib_primitives.h"

#include "..\..\..\lib\includes\lib_entity.h"

int pickScore(std::vector<int>& scoreOrder);

int calculateExtra(int& extraPoints);

Entity& playerCreation(ID nextID);