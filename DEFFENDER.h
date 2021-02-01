#pragma once
#include "CONTAINER_MANAGER.h"
#include "CHARA.h"

class DEFFENDER : public CHARA {
public:
	DEFFENDER();
	void init();
	void update();
	void management(char CharaId, float px, float py);

	float pTop();
	float pBottom();
	float pRight();
	float pLeft();
private:
};