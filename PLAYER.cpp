#include "input.h"
#include <cmath>
#include "rand.h"
#include "MANAGER_CharaManager.h"
#include "CONTAINER_MANAGER.h"
#include "PLAYER.h"

#include "origin.h"
PLAYER::PLAYER() : CHARA() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	jetpackImg = C->Handle[Jet];
	Img = C->Handle[PBody];
	CharaId = C->ad.player.PlayerId;
	secretImg = C->Handle[Ball];
	Gravity = C->ad.system.Gravity;
	ChipSize = C->chipSize;
	windowwidth = C->WindowWidth;
	windowheight = C->WindowHeight;

	LarmImg = C->Handle[PLArm];
	RarmImg = C->Handle[PRArm];

	upperarmoffsetPx = C->ad.player.UpperArmsOffsetPx;
	upperarmoffsetPy = C->ad.player.UpperArmsOffsetPy;

	downerarmoffsetPx = C->ad.player.DownerArmsOffsetPx;
	downerarmoffsetPy = C->ad.player.DownerArmsOffsetPy;

	seemballImg = C->Handle[Ball];
	offsetPy = C->ad.player.PlayerOffsetPy;

	arrowImg = C->arrowImg;
	powerbarImg = C->Handle[PowerBar];
	powergaugeImg = C->Handle[PowerGauge];
	powersize = C->ad.system.PowerBarHeight;
	ballId = C->ad.ball.BallId;
	Maxpower = C->ad.player.MaxPower;
	Powerplus = 0.5f;
	distance = C->ad.player.PlayerAllowedDistance;
	CharaId = C->ad.player.PlayerId;

	recollisionframe = C->ad.ball.ReCollisionCnt;

	ThrowSe = C->throwSe;
	BoundSe = C->boundSe;
	GoalSe = C->goalSe;
	SpringSe = C->springSe;
	CoinSe = C->coinSe;
	OneupSe = C->oneupSe;
	setRandSeed();
}

void PLAYER::init() {
	MAP* map = MAP::getInstance();
	if (map->stageNum() < 50) {
		State = PLAYER_HAVE;
	}
	else {
		pb_State = PLAYER_BALL_STATE_BOUNDING;
		gottencoinsNum = 0;
		coinsNum = map->coinNum();
	}
}

void PLAYER::update() {
	CHARA_MANAGER* CharaManager = MANAGER_CharaManager::getInstance();
	MAP* map = MAP::getInstance();
	if (map->stageNum() <= 10) {
		if (moveflag == 0) {
			firstPx = Px;
		}
		int currentPx = Px;
		if (isPress(KEY_LEFT)) { Px += -3.0f; moveflag = 1; }
		if (isPress(KEY_RIGHT)) { Px += 3.0f; moveflag = 1; }


		if (isPress(KEY_UP)) {
			ThrowforRad += 0.017f;
			if (ThrowforRad > 3.141592 / 2) {
				ThrowforRad = 3.141592 / 2;
			}
		}

		if (isPress(KEY_DOWN)) {
			ThrowforRad += -0.017f;
			if (ThrowforRad < -3.141592 / 4) {
				ThrowforRad = -3.141592 / 4;
			}
		}
		if (Px > firstPx + distance * 2 || Px < ChipSize + offsetPx || Px < firstPx - distance * 2) {
			Px = currentPx;
		}

		arrowpx = Px + 150 + cos(ThrowforRad) * 30;
		arrowpy = Py - 10 - sin(ThrowforRad) * 30;

		if (State == PLAYER_HAVE && isPress(KEY_A)) {
			Power += Powerplus;
			if (Power > Maxpower) {
				Powerplus *= -1;
			}
			else {
				if (Power < 0) {
					Powerplus *= -1;
				}
			}
		}
		else {
			if (Power != 0) {
				if (!(Px < ChipSize + 77 && ThrowforRad > 3.141592 / 180 * 50)) {
					State = PLAYER_THREW;
					playSound(ThrowSe);
					if (ThrowforRad >= 0) {
						CharaManager->appear(ballId, Px + cos(ThrowforRad * 2) * 65, Py - 85 - sin(ThrowforRad * 2) * 50, ThrowforRad, Power, Power);
					}
					else {
						CharaManager->appear(ballId, Px + 7 + cos(3.14 / 4 + ThrowforRad) * 85, Py - 33 - sin(3.14 / 4 + ThrowforRad) * 75, ThrowforRad, Power, Power);
					}
				}
			}
			Power = 0;
		}
	}
	if (map->stageNum() >= 50) {
		currentPx = Px;
		currentPy = Py;
		Px += Dx;
		Py += Dy;
		Rad -= Dx / 10;
		float currentRad = Rad;

		if (Dx != 0) {
			Rad += -Dx / 100;
		}


		//ブロックに当たった場合の処理-----------------------------
		if (map->collisionBottom(Px, Py)) {
			Py = Py / ChipSize * (float)ChipSize;
			if (isPress(KEY_SPACE)) {
				Dy *= -0.65f;
			}
			else {
				Dy *= -0.85f;
				//Dy = -Dy;
			}
			Dy = (int)Dy;
			if (!(isPress(KEY_A) || isPress(KEY_D))) {
				Dx *= 0.85f;
			}
			Py = currentPy;
			JumpFlag = 1;
			if (currentPy / ChipSize * (float)ChipSize != Py / ChipSize * (float)ChipSize) {
			//if((int)currentPy != (int)Py){
				playSound(BoundSe);
			}
		}
		else {
			Dy += Gravity;
			JumpFlag = 0;
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
		//操作-------------------------------------------------------------
		//左右移動
		if (JumpFlag == 1) {
			if (Shotflag == 0) {
				if (isPress(KEY_A)) {
					Dx += -0.4f;
					if (Dx <= -5.0f && Dx >= -6.0f)Dx = -5.0f;
				}
				if (isPress(KEY_D)) {
					Dx += 0.4f;
					if (Dx >= 5.0f && Dx <= 6.0f)Dx = 5.0f;
				}
			}
			if (!(isPress(KEY_A) && isPress(KEY_D))) {
				//射出準備
				if (isTrigger(KEY_S)) { pb_State = PLAYER_BALL_STATE_STAY; }
			}
		}
		//踏ん張り
		if (isPress(KEY_SPACE)) { Dx *= 0.98f; Dy += Gravity / 2; }

		if (pb_State == PLAYER_BALL_STATE_STAY) {
			Shotflag = 1;
			//射角変更
			if (isPress(KEY_UP)) {
				ThrowforRad += -0.017f;
			}
			if (isPress(KEY_DOWN)) {
				ThrowforRad += 0.017f;
			}
			//力溜め
			if (isPress(KEY_A)) {
				Power += Powerplus;
				if (Power > Maxpower) {
					Powerplus *= -1;
				}
				else {
					if (Power < 0) {
						Powerplus = -Powerplus;
					}
				}
			}
			//リリース
			else {
				if (Power != 0) {
					Dx += sin(ThrowforRad) * Power;
					Dy += -cos(ThrowforRad) * Power;
					Shotflag = 0;
				}
				if (Shotflag == 0) {
					pb_State = PLAYER_BALL_STATE_BOUNDING;
					Power = 0;
					ThrowforRad = 0;
				}
			}
		}

		//------------------------------------------------------------
		//画面外に出たら
		if (Px > windowwidth || Px < -ChipSize || Py > windowheight || Py < -map->hiddenmap() -ChipSize) {
			pb_State = PLAYER_BALL_STATE_MISS;
		}
		if (collisionCnt > 0)collisionCnt--;

		if (flyframe-- > 0) {
			drawImage(jetpackImg, Px, Py + 20, COLOR(Red, Green, Blue, Alpha));
			//exechangeTone(&Red, &Green, &Blue, 20, "mid");
			if (Dy > -2.0f) {
				Dy -= 0.6f;
			}
			else Dy = -2.0f;
		}
		if (pb_State == PLAYER_BALL_STATE_ONEUP)pb_State = PLAYER_BALL_STATE_BOUNDING;
		if (gottencoinsNum == coinsNum && coinsNum != 0)pb_State = PLAYER_BALL_STATE_GOAL;
	}
}

//引数でポジションを渡して判定を行う
//ベクトルを使う　atan2
void PLAYER::management(char Id, float px, float py) {
	//collision Vector
	float CllVec = -atan2(Px - px, Py - py);
	float radian = 3.141592f / 180;
	switch (Id) {

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
			collisionCnt = recollisionframe;
			//上*
			if ((CllVec <= radian * -117 || CllVec >= radian * 117) && Dy >= 0) {
				playSound(GoalSe);
				pb_State = PLAYER_BALL_STATE_GOAL;
			}
			else {
				Dx = -cos(CllVec) * Dx;
				Dy = sin(CllVec) * Dy;
			}
		}
		break;

		//deffender
	case 'd':
		//右
		if (CllVec <= radian * -27) {
			JumpFlag = 1;
			//右上
			if (CllVec <= radian * -85) {
				Dy = -Dy;
			}
			else {
				Dx = -Dx;
			}
		}
		else {
			pb_State = PLAYER_BALL_STATE_MISS;
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
		pb_State = PLAYER_BALL_STATE_ONEUP;
		playSound(OneupSe);
		break;

	case 'c':
		gottencoinsNum++;
		playSound(CoinSe);
		break;
	}
}

int PLAYER::pb_state() { return pb_State; }

void PLAYER::draw() {
	MAP* map = MAP::getInstance();
	if (map->stageNum() < 50) {
		//////左腕。そえるだけ
		if (ThrowforRad >= 0) {
			drawImage(LarmImg, Px + upperarmoffsetPx - cos(ThrowforRad) * 5, Py + upperarmoffsetPy - sin(ThrowforRad) * 50, ThrowforRad);
		}
		else {
			drawImage(LarmImg, Px + downerarmoffsetPx + sin(ThrowforRad) * 37, Py + downerarmoffsetPy - sin(ThrowforRad) * 17, ThrowforRad);
		}
		if (State == PLAYER_HAVE) {
			if (ThrowforRad >= 0) {
				drawImage(seemballImg, Px + cos(ThrowforRad * 2) * 65, Py - 85 - sin(ThrowforRad * 2) * 50, ThrowforRad);
				drawImage(arrowImg, Px - 70 + cos(ThrowforRad) * 250, Py - 85 - sin(ThrowforRad) * 150, ThrowforRad);
			}

			else {
				drawImage(seemballImg, Px + 7 + cos(3.14 / 4 + ThrowforRad) * 85, Py - 33 - sin(3.14 / 4 + ThrowforRad) * 75, ThrowforRad);
				drawImage(arrowImg, Px + cos(ThrowforRad) * 200, Py - 85 - sin(ThrowforRad / 3 * 2) * 250, ThrowforRad);
			}
		}

		drawImage(Img, Px + offsetPx, Py + offsetPy, Rad, Color);

		////右腕。複雑に動くほう
		if (ThrowforRad >= 0) {
			drawImage(RarmImg, Px + upperarmoffsetPx - cos(ThrowforRad) * 5, Py + upperarmoffsetPy - sin(ThrowforRad) * 50, ThrowforRad);
		}
		else {
			drawImage(RarmImg, Px + downerarmoffsetPx + sin(ThrowforRad) * 37, Py + downerarmoffsetPy - sin(ThrowforRad) * 17, ThrowforRad);
		}
	}
	if (map->stageNum() >= 50) {
		drawImage(secretImg, Px + 30, Py + 30, Rad, COLOR(Red, Green, Blue, Alpha));

		if (pb_State == PLAYER_BALL_STATE_STAY) {
			drawImage(arrowImg, Px + 30 + sin(ThrowforRad) * 100, Py  + 30 - cos(ThrowforRad) * 100, -ThrowforRad + 3.141592 / 180 * 90);
		}
	}
	for (int i = 0; i < Power * 2; i++) {
		drawImage(powerbarImg, 100, 800 - i * powersize / 2, 0.0f, hsv_to_rgb(3.4 - i * 0.1));
	}
	if (Power) {
		drawImage(powergaugeImg, -100, 228 - 100);
	}
}