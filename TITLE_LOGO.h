#pragma once
#include "IMG.h"
#include "CONTAINER_MANAGER.h"

class TITLE_LOGO : public IMG {
public:
	TITLE_LOGO() {
			CONTAINER* C = CONTAINER_MANAGER::getInstance();
		Img = C->titlelogoImg;
		Px = C->titlelogoPx;
		Py = C->titlelogoPy;
	}
};