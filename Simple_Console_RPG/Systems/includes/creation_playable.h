#pragma once

#include "..\..\..\lib\includes\lib_primitives.h"

#include "..\..\lib\includes\lib_entity.h"

enum PlayableType {

	PLAYER,
	MERC,

};

ID createPlayable(ID& nextID, PlayableType type);