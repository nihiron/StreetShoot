#include "CHARA.h"

class PLAYER : public CHARA {
public:
	PLAYER();
	void init();
	void update();
	void draw();
	
	void management(char Id, float px, float py);


	enum P_STATE { PLAYER_HAVE, PLAYER_THREW };
	int State = PLAYER_HAVE;

	enum PB_STATE { PLAYER_BALL_STATE_BOUNDING, PLAYER_BALL_STATE_MISS, PLAYER_BALL_STATE_GOAL, PLAYER_BALL_STATE_STAY,PLAYER_BALL_STATE_ONEUP };//投げた、捕まった、ゴールした、力を溜める,ONEUP!!
	int pb_State = PLAYER_BALL_STATE_BOUNDING;
	int pb_state();

private:
	int jetpackImg = 0;
	float currentPx = 0;
	float currentPy = 0;
	int secretImg = 0;
	float Gravity = 0;
	int ChipSize = 0;
	int windowwidth = 0;
	int windowheight = 0;
	//ジャンプしているか。0 = ジャンプ中 , 1 = 着地済
	int JumpFlag = 0;
	//射出用フラグ。0 = それ以外, 1 = 射出待機
	int Shotflag = 0;
	int collisionCnt = 0;
	int recollisionframe = 0;
	int flyframe = 0;
	int gottencoinsNum = 0;
	int coinsNum = 0;

	int BoundSe = 0;
	int GoalSe = 0;
	int SpringSe = 0;
	int CoinSe = 0;
	int OneupSe = 0;


	int LarmImg = 0;
	int RarmImg = 0;
	int powergageImg = 0;

	float upperarmoffsetPx = 0;
	float upperarmoffsetPy = 0;

	float downerarmoffsetPx = 0;
	float downerarmoffsetPy = 0;

	int seemballImg = 0;
	int arrowImg = 0;
	float arrowpx = 0.0f;
	float arrowpy = 0.0f;
	int powergaugeImg = 0;
	int powerbarImg = 0;
	int powersize = 0;
	char ballId = 0;
	float ThrowforRad = 0.0f;
	float Power = 0;
	float Maxpower = 0.0f;
	float Powerplus = 0.0f;
	COLOR Color;
	float distance = 0;
	int throwflag = 0;//0 投げてない 1投げ



	int firstPx = 0;
	int moveflag = 0;

	int ThrowSe = 0;

};