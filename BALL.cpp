#include <cmath>
#include "rand.h"
#include "input.h"

#include "MAP.h"
#include "BALL.h"
#include "CONTAINER_MANAGER.h"

BALL::BALL() : CHARA() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	jetpackImg = C->ad.jet.JetImg;
	Img = C->ad.ball.BallImg;
	CharaId = C->ad.ball.BallId;
	Px = 0;
	Py = 0;
	chipSize = C->chipSize;
	Alpha = 0.0f;
	Gravity = C->ad.system.Gravity;
	isnotmoveCnt = C->ad.ball.NotMoveCnt;
	recollisionframe = C->ad.ball.ReCollisionCnt;
	windowwidth = C->ad.system.WindowWidth;
	windowheight = C->ad.system.WindowHeight;

	BoundSe = C->boundSe;
	GoalSe = C->goalSe;
	SpringSe = C->springSe;
	CoinSe = C->coinSe;
	CatchSe = C->catchSe;
	OneupSe = C->oneupSe;
	setRandSeed();

	//CONTAINER* C = CONTAINER_MANAGER::getInstance();
	//jetpackImg = C->ad.system.jetpackImg;
	//Img = C->ad.system.BallImg;
	//CharaId = C->ad.system.ballId;
	//Px = 0;
	//Py = 0;
	//chipSize = C->ad.system.chipSize;
	//Alpha = 0.0f;
	//Gravity = C->ad.system.gravity;
	//isnotmoveCnt = C->ad.system.notmoveCnt;
	//recollisionframe = C->ad.system.recollisionCnt;
	//windowwidth = C->ad.system.WindowWidth;
	//windowheight = C->ad.system.WindowHeight;

	//BoundSe = C->ad.system.boundSe;
	//GoalSe = C->ad.system.goalSe;
	//SpringSe = C->ad.system.springSe;
	//WindSe = C->ad.system.windSe;
	//CoinSe = C->ad.system.coinSe;
	//CatchSe = C->ad.system.catchSe;
	//OneupSe = C->ad.system.oneupSe;
	//setRandSeed();
}

void BALL::init() {
	MAP* map = MAP::getInstance();
	if (map->stageNum() < 50) {
		Alpha = 0.0f;
		gottencoinsNum = 0;
		coinsNum = map->coinNum();
	}
	State = BALL_STATE_BOUNDING;
}

void BALL::appear(float px, float py, float rad, float dx, float dy) {
	Alpha = 1.0f;
	Rad = rad;
	if (Rad >= 0) {
		Px = px + cos(Rad * 2) * 25;
		Py = py - sin(Rad * 2) * 45;
	}
	else {
		Px = px + cos(3.14 / 4 + Rad) * 25;
		Py = py - sin(3.14 / 4 + Rad) * 45;
	}
	Dx =  cos(rad) * dx;
	Dy = -sin(rad) * dy;
}

void BALL::update() {
	MAP* map = MAP::getInstance();

	currentPx = Px;
	currentPy = Py;
	Px += Dx;
	Py += Dy;
	Rad -= Dx / 10;
	float currentRad = Rad;

	if (Dx != 0) {
		Rad += -Dx / 100;
	}
	//横にも縦にも動かなくなったら
	if (Dx < 0.02f && Dx > -0.02f && Dy < 0.5f && Dy > -0.5f) {
		if (++moveCnt == isnotmoveCnt) {
			State = BALL_STATE_MISS;
		}
	}
	else {
		moveCnt = 0;
	}
	//ブロックに当たった場合の処理-----------------------------
	if (map->collisionBottom(Px, Py)) {
		Py = Py / chipSize * (float)chipSize;
		Dy *= -0.85f;
		Dy = (int)Dy;
		Dx *= 0.99f;
		Py = currentPy;
		if (currentPy / ChipSize * (float)ChipSize != Py / ChipSize * (float)ChipSize) {
		//if (currentPy != Py) {
			playSound(BoundSe);
		}
	}
	else {
		Dy += Gravity;
	}
	if (map->collisionTop(Px, Py)) {
		playSound(BoundSe);
		Py = currentPy;
		Dy *= -1.0f;
	}
	if (map->collisionLeft(Px, Py)) {
		playSound(BoundSe);
		Rad = currentRad;
		Px = currentPx;
		Dx *= -0.8f;
	}
	if (map->collisionRight(Px, Py)) {
		playSound(BoundSe);
		Rad = currentRad;
		Px = currentPx;
		Dx *= -0.8f;
	}
	//------------------------------------------------------------

	//画面外に出たら
	if (Px > windowwidth || Px < -chipSize || Py > windowheight || Py < -map->hiddenmap() - chipSize) {
		State = BALL_STATE_MISS;
	}

	if (collisionCnt > 0)collisionCnt--;
	if (flyframe-- > 0) {
		drawImage(jetpackImg, Px, Py + 20, COLOR(Red, Green, Blue, Alpha));
		if (Dy > -2.0f) {
			Dy -= 0.6f;
		}
		else Dy = -2.0f;
	}
	if (gottencoinsNum == coinsNum && coinsNum != 0)BALL_STATE_GOAL;
	if (State == BALL_STATE_ONEUP)State = BALL_STATE_BOUNDING;
}


//引数でポジションを渡して判定を行う
//ベクトルを使う　atan2
void BALL::management(char Id, float px, float py) {
	//collision Vector
	CllVec = -atan2(Px - px, Py - py);

	//1度
	float radian = 3.141592f / 180;

	//ギミックごとの処理。(ボール側)
	switch (Id) {

		//deffender
	case 'd':
		//右
		if (CllVec <= radian * -27) {
			//右上
			if (CllVec <= radian * -75) {
				//Dy *= sin(CllVec);
				Py = currentPy;
				Dy = -Dy;
			}
			else {
				//Dx *= -cos(CllVec);
				Px = currentPx;
				Dx = -Dx;
			}
		}
		else {
			State = BALL_STATE_MISS;
		}
		break;

		//spring
	case 's':
		if (collisionCnt == 0) {
			collisionCnt = recollisionframe;
			//上
			if (CllVec <= radian * -120 || CllVec >= radian * 120) {
				Dy *= -1.5f;
				playSound(SpringSe);
			}//下
			else if (CllVec >= radian * -45 && CllVec <= radian * 45) {
				Dy *= -1.0f;
			}//左右
			else {
				Dx *= -1.0f;
			}
		}
		break;

		//goal
	case 'g':
		if (collisionCnt == 0) {
			//上*
			collisionCnt = recollisionframe;
			if ((CllVec <= radian * -117 || CllVec >= radian * 117) && Dy >= 0) {
				playSound(GoalSe);
				State = BALL_STATE_GOAL;
			}
			else {
				Dx = -cos(CllVec) * Dx;
				Dy = sin(CllVec) * Dy;
			}
		}
		break;

		//wind
	case 'w':
		if (collisionCnt == 0) {
			collisionCnt = recollisionframe;
			//playSound(WindSe);
			Dx = -50.0 + getRand() % 1000 / 10.0;
			Dy = -50.0 + getRand() % 1000 / 10.0;
		}
		break;

		//player
	case 'p':
		if (isTrigger(KEY_Z)) {
			State = BALL_STATE_HAVE;
			playSound(CatchSe);
		}
		break;

		//nentyaku block
	case 'n':
		if (collisionCnt == 0) {
			collisionCnt = recollisionframe;
			Red -= 0.08f;
			//上下
			if (CllVec <= radian * -120 || CllVec >= radian * 120) {
				Dy *= -0.4f;
				Dy = (int)Dy;
				Dx *= 0.85f;
				Py = currentPy;
			}
			if (CllVec >= radian * -50 && CllVec <= radian * 50) {
				Dy *= 0.2f;
				Dx *= 0.3f;
			}
			//左右
			else {
				Dx *= 0.8f;
				Dy *= 0.8f;
			}
		}
		break;

	case 'j':
		flyframe = 300;
		break;

	case 'o':
		State = BALL_STATE_ONEUP;
		playSound(OneupSe);
		break;

	case 'c':
		gottencoinsNum++;
		playSound(CoinSe);
		break;
	}
}

void BALL::draw(){
	drawImage(Img, Px + 30, Py + 30, Rad, COLOR(Red, Blue, Green, Alpha));
}


int BALL::state() { return State; }