#include "CHARA.h"

class BALL : public CHARA {
public:
	BALL();
	void init();
	void appear(float px, float py, float rad, float dx, float dy);
	void update();
	void draw();
	
	
	void management(char Id, float px, float py);

	int state();
	enum STATE { BALL_STATE_BOUNDING, BALL_STATE_MISS, BALL_STATE_GOAL, BALL_STATE_HAVE,BALL_STATE_ONEUP };//投げた、捕まった、ゴールした、持っている、1UP!!!!
	int State = BALL_STATE_BOUNDING;

private:
	int jetpackImg = 0;
	float currentPx = 0;
	float currentPy = 0;
	int chipSize = 0;
	float windowwidth = 0;
	float windowheight = 0;
	float Gravity = 0;
	int moveCnt = 0;
	int isnotmoveCnt = 0;

	int coinsNum = 0;

	float CllVec = 0.0f;//Collision Vector

	int collisionCnt = 0;
	int recollisionframe = 0;
	int gottencoinsNum = 0;
	int flyframe = 0;

	int BoundSe = 0;
	int GoalSe = 0;
	int SpringSe = 0;
	int CoinSe = 0;
	int CatchSe = 0;
	int OneupSe = 0;
};
