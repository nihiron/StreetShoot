#pragma once
#include "CONTAINER_MANAGER.h"
#include "CHARA.h"

class WIND :public CHARA {
public:
	WIND();
	void init();
	void update();
	void draw();
	void management(char CharaId, float px, float py);

private:
	int turnchagepercent = 0;
	int ChangeInterval = 0;
	float turn = 0.0f;
};