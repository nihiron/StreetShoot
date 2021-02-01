#include "CHARA.h"
#include "CONTAINER_MANAGER.h"

class GOAL : public CHARA {
public:
	GOAL();
	void init();
	void appear(float px, float py, float dx, float dy);
	void update();

	float pBottom();
	float pTop();
	float pLeft();
	float pRight();
};