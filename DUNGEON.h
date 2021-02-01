#pragma once
#include "IMG.h"
#include "CONTAINER_MANAGER.h"

class DUNGEON : public IMG {
public:
	DUNGEON::DUNGEON() {
			CONTAINER* C = CONTAINER_MANAGER::getInstance();
		Img = C->dungeonImg;
		Px = C->dungeonPx;
		Py = C->dungeonPy;
	}
};