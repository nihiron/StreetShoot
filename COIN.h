#pragma once
#include "CHARA.h"

class COIN : public CHARA {
public:
	COIN();
	void draw();
	void management(char CharaID, float px, float py);

	//float pLeft();
	//float pTop();
	//float pRight();
	//float pBottom();
private:
};