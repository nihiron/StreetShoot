#include "CHARA.h"
#include "CONTAINER_MANAGER.h"

class SPRING : public CHARA {
public:
	SPRING();
	void init();
	void update();
	void management(char CharaId, float px, float py);

	float pLeft();
	float pRight();
	float pBottom();
	float pTop();
};
