#pragma once
#include "IMG.h"
#include "CONTAINER_MANAGER.h"

class TITLE : public IMG {
public:
	TITLE() {
			CONTAINER* C = CONTAINER_MANAGER::getInstance();
		Img = C->titleImg;
		Px = C->titlePx;
		Py = C->titlePy;
	}
};