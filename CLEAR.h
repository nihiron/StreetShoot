#pragma once
#include "IMG.h"
#include "CONTAINER_MANAGER.h"

class CLEAR : public IMG {
public:
	CLEAR() {
			CONTAINER* C = CONTAINER_MANAGER::getInstance();
		Img = C->clearImg;
		Px = C->clearPx;
		Py = C->clearPy;
	}
};