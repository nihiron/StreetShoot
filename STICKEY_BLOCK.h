#pragma once
#include "CONTAINER_MANAGER.h"
#include "CHARA.h"

class STICKY_BLOCK : public CHARA {
public:
	STICKY_BLOCK();
	void init();
	void appear(float px, float py, float dx, float dy);
	void update();
};