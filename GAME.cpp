#pragma warning(disable : 4996)

#include "CONTAINER_MANAGER.h"
#include "MANAGER_CharaManager.h"
#include "input.h"
#include <stdio.h>

#include "GAME.h"

GAME::GAME() {
	//CONTAINER_MANAGER::readSystemData();
	//initialize(ad.system.WindowTitle, ad.system.WindowWidth, ad.system.WindowHeight, FULLSCREEN);
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	MAP::getInstance();
	MANAGER_CharaManager::getInstance();
	img = new IMG;

	TitleBgm = C->titleBgm;
	PlayBgm = C->playBgm;
	ClearBgm = C->clearBgm;
	GameoverBgm = C->gameoverSe;
	FailedBgm = C->failedBgm;
	playLoopSound(TitleBgm);
	loadData();
	State = GAME_STATE_TITLE;

}

GAME::~GAME() {
	delete img;
	saveData();
	ad.ball.BallImg = 0;
	ad.coin.CoinImg = 0;
	ad.deffender.DeffenderImg = 0;
	ad.goal.GoalImg = 0;
	ad.jet.JetImg = 0;
	ad.one.OneupImg = 0;
	ad.player.BodyImg = 0;
	ad.player.LArmImg = 0;
	ad.player.RArmImg = 0;
	ad.player.PowergaugeImg = 0;
	ad.spring.SpringImg = 0;
	ad.stickey.StickeyImg = 0;
	ad.system.PowerBarImg = 0;
	ad.system.PowerGaugeImg = 0;
	ad.wind.WindImg = 0;
	ad.clear.Img = 0;
	ad.failed.Img = 0;
	ad.gameover.Img = 0;
	ad.back.Img = 0;
	ad.dungeon.Img = 0;
	ad.feed.Img = 0;
	ad.title.Img = 0;
	ad.titlelogo.Img = 0;
	CONTAINER_MANAGER::createSystemData();
	MAP::destroy();
	MANAGER_CharaManager::destroy();
	CONTAINER_MANAGER::destroy();
}

void GAME::proc() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	getInput();
	clearTarget();
	if (stageno == 5 || stageno == 55) {
		img->DUNGEON.draw();
	}//最終ステージ以外
	else {
		img->BACK.draw();
	}

	switch (State) {
	case GAME_STATE_TITLE:
		title();
		break;

	case GAME_STATE_SELECT:
		select();
		break;

	case GAME_STATE_PLAY:
		play();
		break;

	case GAME_STATE_CLEAR:
		clear();
		break;

	case GAME_STATE_FAILED:
		failed();
		break;

	case GAME_STATE_GAMEOVER:
		gameover();
		break;

	case GAME_STATE_END:
		ending();
		break;
	}
	if (stageno > PlayerCouldStage && stageno <= 5) { PlayerCouldStage = stageno; }
	img->FEED.draw();
	drawDebugStr();
	present();
}

void GAME::saveData() {
	FILE* fp = 0;
	fopen_s(&fp, "data/PLAYER_DATA.bin", "wb");
	fwrite(&PlayerCouldStage, 4, 1, fp);
	fclose(fp);
}
void GAME::loadData() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	FILE* fp = 0;
	fopen_s(&fp, "data/PLAYER_DATA.bin", "rb");
	if (fp) {
		fread(&PlayerCouldStage, sizeof(int), 1, fp);
		fclose(fp);
	}
}

void GAME::title() {//-----------------------------------------------------------
	stopSound(PlayBgm);
	stopSound(ClearBgm);
	stopSound(GameoverBgm);
	stopSound(FailedBgm);
	Isarcadeflag = 0;
	stayFlag = 0;
	img->TITLE.draw();
	img->TITLELOGO.draw();
	zanki = 5;
	MANAGER_CharaManager::destroy();

	//さぶらふ
	if (isTrigger(KEY_S) && command == 0)command = 1;
	if (isTrigger(KEY_A) && command == 1)command = 2;
	if (isTrigger(KEY_B) && command == 2)command = 3;
	if (isTrigger(KEY_U) && command == 3)command = 4;
	if (isTrigger(KEY_R) && command == 4)command = 5;
	if (isTrigger(KEY_O) && command == 5)command = 6;
	if (isTrigger(KEY_U) && command == 6) {
		command = 7;
		wff = 90;
	}


	if (isTrigger(KEY_X) && wff == 0) {
		stageno = 1;
		State = GAME_STATE_SELECT;
		return;
	}

	////プレイヤー情報を表示するステートの予定だったもの
	//if (isTrigger(KEY_I)) {
	//	State = GAME_STATE_INFO;
	//	return;
	//}

	//Zを押してゲーム開始する
	if (isTrigger(KEY_Z)) {
		wff = 90;
		stageno = 1;
		command = 0;
	}

	//フェードアウト
	if (wff != 0) {
		img->FEED.feedout();
		if (--wff == 0) {
			if (command == 7) { stageno = 51; }
			if (command == 10)stageno = -1000;
			command = 0;
			mapChange(stayFlag);
			//フェードアウト
			wff = 90;
			stopSound(TitleBgm);
			playLoopSound(PlayBgm);
		}
	}
}
void GAME::select() {//----------------------------------------------------------
	MAP* map = MAP::getInstance();
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	img->TITLE.draw();
	img->TITLELOGO.draw();
	if (wff == 0) {
		//増やす。プレイヤーが見たところまで
		if (isTrigger(KEY_RIGHT)) {
			if (++stageno > PlayerCouldStage) {
				if (PlayerCouldStage < 1) {
					PlayerCouldStage = 1;
				}
				stageno = PlayerCouldStage;
			}
		}
		//減らす。0以上
		if (isTrigger(KEY_LEFT)) {
			if (--stageno <= 0) { stageno = 1; }
		}
		if (isTrigger(KEY_G)) {
			stageno = 100;
		}
		//if (PlayerCouldStage < 50) {
		//	//減らす。0以上
		//	if (isTrigger(KEY_LEFT)) {
		//		if (PlayerCouldStage < 1) {
		//			PlayerCouldStage = 1;
		//		}
		//		if (--stageno <= 0) { stageno = 1; }
		//	}
		//	//増やす。プレイヤーが見たところまで
		//	if (isTrigger(KEY_RIGHT)) {
		//		if (++stageno > PlayerCouldStage || PlayerCouldStage <= 5) {
		//			stageno = PlayerCouldStage;
		//		}
		//	}
		//	if (isTrigger(KEY_UP)) {
		//		if (PlayerCouldStage > 50) {
		//			stageno = 51;
		//		}
		//	}
		//}
		//else {
		//	//減らす。0以上
		//	if (isTrigger(KEY_LEFT)) {
		//		if (--stageno <= 50) { stageno = 51; }
		//	}
		//	//増やす。プレイヤーが見たところまで
		//	if (isTrigger(KEY_RIGHT)) {
		//		if (++stageno > PlayerCouldStage) {
		//			stageno = PlayerCouldStage;
		//		}
		//	}
		//	//サブローステージ
		//	if (isTrigger(KEY_DOWN)) {
		//		stageno = 1;
		//	}
		//}
	}
	Isarcadeflag = 1;

	if (isTrigger(KEY_X)) {
		State = GAME_STATE_TITLE;
		stageno = 1;
		return;
	}

	if (isTrigger(KEY_Z)) {
		wff = 90;
	}
	//フェードアウト
	if (wff != 0) {
		img->FEED.feedout();
		if (--wff == 0) {

			mapChange(0);
			command = 0;
			State = GAME_STATE_PLAY;

			//キャラの一括 new
			CHARA_MANAGER* CharaManager = MANAGER_CharaManager::getInstance();

			//キャラを一括初期化
			CharaManager->init();

			//フェードアウト
			wff = 90;
			stopSound(TitleBgm);
			playLoopSound(PlayBgm);
		}
	}
}
void GAME::play() {//------------------------------------------------------------
	stopSound(FailedBgm);
	stopSound(ClearBgm);
	MAP* map = MAP::getInstance();
	CHARA_MANAGER* CharaManager = MANAGER_CharaManager::getInstance();
	if (img->FEED.alpha() == 0) { playTime++; }
	//フェードイン
	img->DUNGEON.feedout();
	img->BACK.feedout();
	img->FEED.feedin();

	CharaManager->update();
	map->draw();
	CharaManager->draw();
	//ゴールを決めた。もしくは一度クリアしたうえでQキーを押した。
	if (CharaManager->ballgoal() || CharaManager->playergoal() || (isTrigger(KEY_Q) && stayFlag == 1)) {
		State = GAME_STATE_CLEAR;
		wff = 180;
		stopSound(PlayBgm);
		playLoopSound(ClearBgm);

		////最速タイムの更新
		//switch (stageno) {
		//case 1:
		//	if (data.MinPlayTime1 < playTime)data.MinPlayTime1 = playTime;
		//	break;
		//case 2:
		//	if (data.MinPlayTime2 < playTime)data.MinPlayTime2 = playTime;
		//	break;
		//case 3:
		//	if (data.MinPlayTime3 < playTime)data.MinPlayTime3 = playTime;
		//	break;
		//case 4:
		//	if (data.MinPlayTime4 < playTime)data.MinPlayTime4 = playTime;
		//	break;
		//case 5:
		//	if (data.MinPlayTime5 < playTime)data.MinPlayTime5 = playTime;
		//	break;
		//
		//case 51:
		//	if (data.MinPlayTimeS1 < playTime)data.MinPlayTimeS1 = playTime;
		//	break;
		//case 52:
		//	if (data.MinPlayTimeS2 < playTime)data.MinPlayTimeS2 = playTime;
		//	break;
		//case 53:
		//	if (data.MinPlayTimeS3 < playTime)data.MinPlayTimeS3 = playTime;
		//	break;
		//case 54:
		//	if (data.MinPlayTimeS4 < playTime)data.MinPlayTimeS4 = playTime;
		//	break;
		//case 55:
		//	if (data.MinPlayTimeS5 < playTime)data.MinPlayTimeS5 = playTime;
		//	break;
		//}
		//return;
	}

	//残機を減らす条件。Rキーを押すか
	//Ball_STATE が Ball_STATE_MISS になるか
	if (isTrigger(KEY_R) || CharaManager->ballmissed() || CharaManager->playermissed()) {
		wff = 0;
		img->FEED.blackout();
		//data.TotalFailedNum++;
		zanki--;
		stopSound(PlayBgm);
		if (zanki > 0 || stayFlag != 0 || Isarcadeflag != 0) {
			State = GAME_STATE_FAILED;
			playSound(FailedBgm);
			return;
		}
		else {
			State = GAME_STATE_GAMEOVER;
			//data.TotalGameoverNum++;
			playSound(GameoverBgm);
			return;
		}
	}

	//プレイヤーがボールをキャッチした
	if (CharaManager->playercatch() && stageno < 50) {
		mapChange(0);
		return;
	}

	//タイトルに戻る
	if (isTrigger(KEY_T)) {
		stopSound(PlayBgm);
		State = GAME_STATE_TITLE;
		stageno = 1;
		stayFlag = 0;
		playLoopSound(TitleBgm);
		wff = 0;
		return;
	}
	if (CharaManager->playeroneup()) {
		zanki++;
	}
}
void GAME::clear() {//-----------------------------------------------------------
	MAP* map = MAP::getInstance();
	CHARA_MANAGER* CharaManager = MANAGER_CharaManager::getInstance();
	//Zキーを押して次のステージに進む
	if (isTrigger(KEY_Z)) {
		//残機を補充
		if (zanki <= 5) {
			zanki = 5;
		}
		wff = 90;
	}
	wff--;
	if (wff == 90) {
		wff = 91;
	}
	if (wff > 135) {
		if (CharaManager) { CharaManager->draw(); map->draw(); }
		img->FEED.feedout();
	}
	if (wff < 135 && wff > 90) {
		img->CLEAR.draw();
		img->FEED.feedin();
	}
	if (wff < 90) {
		img->FEED.feedout();
		//練習だったら
		if (Isarcadeflag != 0) {
			State = GAME_STATE_TITLE;
			playLoopSound(TitleBgm);
			stageno = 1;
			wff = 0;
			return;
		}
		//最終ステージなら
		if (stageno == 5 || stageno == 55) {
			State = GAME_STATE_TITLE;
			stopSound(ClearBgm);
			playLoopSound(TitleBgm);
			stageno = 1;
			wff = 0;
			return;
		}
		//フェードアウト待ち
		if (wff == 0) {
			stayFlag = 1;
			mapChange(stayFlag);
			stayFlag = 0;
			stopSound(ClearBgm);
			playLoopSound(PlayBgm);
		}
	}
	//リトライ
	if (isTrigger(KEY_R)) {
		stayFlag = 1;
		mapChange(0);
		stopSound(ClearBgm);
		playLoopSound(PlayBgm);
	}
}
void GAME::failed() {//----------------------------------------------------------
	MAP* map = MAP::getInstance();
	CHARA_MANAGER* CharaManager = MANAGER_CharaManager::getInstance();
	map->draw();
	CharaManager->draw();

	if (isTrigger(KEY_Z)) {
		wff = 450;
	}
	if (wff < 90) {
		img->DUNGEON.feedin();
		img->BACK.feedin();
	}

	//フェードアウト
	if (wff > 360) {
		img->FEED.feedout();
		//フェードアウト待ち
		if (wff == 450) {
			mapChange(0);
			playLoopSound(PlayBgm);
			img->FEED.colorring();
		}
	}
	else {
		img->FAILED.draw();
	}
	wff++;
}
void GAME::gameover() {//--------------------------------------------------------
	stageno = 1;
	wff++;
	MANAGER_CharaManager::destroy();

	if (isTrigger(KEY_Z) && wff > 180) {
		wff = 600;
	}

	if (wff < 90) {
		img->FEED.feedout();
	}
	if (wff < 180 && wff > 90) {
		img->FEED.feedin();
	}
	if (wff > 90) {
		img->GAMEOVER.draw();
	}

	//フェードアウト待ち
	if (wff == 600) {
		State = GAME_STATE_TITLE;
		playLoopSound(TitleBgm);
		img->FEED.colorring();
		stopSound(GameoverBgm);
		wff = 0;
	}
}
void GAME::ending() {//----------------------------------------------------------
	stageno = 1;
	img->FEED.feedin();
	//img->ENDING.draw();

	if (isTrigger(KEY_Z)) {
		State = GAME_STATE_TITLE;
		playLoopSound(TitleBgm);
		wff = 0;
	}
}
void GAME::infomation() {
	//戻る
	if (isTrigger(KEY_I)) {
		State = GAME_STATE_TITLE;
		return;
	}

}
//1 = next,0 = stay
void GAME::mapChange(int flag) {//-----------------------------------------------
	if (flag) {
		stageno++;
	}
	MANAGER_CharaManager::destroy();
	MAP* map = MAP::getInstance();
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	switch (stageno) {
	//case -1000:
	//	map->init(C->testmap, stageno);
	//	break;
	case 1:
		map->init(C->stage1, stageno);
		break;
	case 2:
		map->init(C->stage2, stageno);
		break;
	case 3:
		map->init(C->stage3, stageno);
		break;
	case 4:
		map->init(C->stage4, stageno);
		break;
	case 5:
		map->init(C->stage5, stageno);
		break;
	case 51:
		map->init(C->stage51, stageno);
		break;
	case 52:
		map->init(C->stage52, stageno);
		break;
	case 53:
		map->init(C->stage53, stageno);
		break;
	case 54:
		map->init(C->stage54, stageno);
		break;
	case 55:
		map->init(C->stage55, stageno);
		break;
	case 100:
		map->init(C->testmap, stageno);
		break;
	}
	CHARA_MANAGER* CharaManager = MANAGER_CharaManager::getInstance();
	CharaManager->init();
	State = GAME_STATE_PLAY;
	playLoopSound(PlayBgm);
	playTime = 0;
}
