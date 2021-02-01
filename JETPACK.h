#pragma once
#include "CHARA.h"
#include "CONTAINER_MANAGER.h"

class JETPACK : public CHARA {
public:
	JETPACK();
	void draw();
	void management(char CharaId, float px, float py);

	//float pLeft();
	//float pTop();
	//float pRight();
	//float pBottom();
};