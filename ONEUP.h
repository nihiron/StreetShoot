#pragma once
#include "CONTAINER_MANAGER.h"
#include "CHARA.h"

class ONEUP : public CHARA {
public:
	ONEUP();
	void init();
	void management(char CharaId, float px, float py);

	//float pLeft();
	//float pTop();
	//float pRight();
	//float pBottom();
};