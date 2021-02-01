#pragma once
#include "IMG.h"
#include "CONTAINER_MANAGER.h"

class FEED : public IMG {
public:
	FEED() {
			CONTAINER* C = CONTAINER_MANAGER::getInstance();
		Img = C->EffFeedImg;
		Px = 0.0f;
		Py = 0.0f;
		Alpha = 0.0f;
	}
};