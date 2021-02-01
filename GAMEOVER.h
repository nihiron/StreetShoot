#pragma once
#include "IMG.h"
#include "CONTAINER_MANAGER.h"

class GAMEOVER : public IMG {
public:
	GAMEOVER() {
			CONTAINER* C = CONTAINER_MANAGER::getInstance();
		Img = C->gameoverImg;
		Px = C->gameoverPx;
		Py = C->gameoverPy;
	}
};