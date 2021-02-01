#pragma once
#include "IMG.h"
#include "CONTAINER_MANAGER.h"

class BACKGROUND : public IMG {
public:
	BACKGROUND() {
		CONTAINER* C = CONTAINER_MANAGER::getInstance();
		Img = C->backgroundImg;
		Px = C->backgroundPx;
		Py = C->backgroundPy;
	}
};