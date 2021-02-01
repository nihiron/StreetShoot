#pragma once
#include "IMG.h"
#include "CONTAINER_MANAGER.h"

class FAILED : public IMG {
public:
	FAILED() {
			CONTAINER* C = CONTAINER_MANAGER::getInstance();
		Img = C->failedImg;
		Px = C->failedPx;
		Py = C->failedPy;
	}
};