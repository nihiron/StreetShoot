#include "CHARA_MANAGER.h"
#include "CONTAINER_MANAGER.h"

#include "PLAYER.h"
#include "BALL.h"
#include "SPRING.h"
#include "DEFFENDER.h"
#include "WIND.h" 
#include "GOAL.h"
#include "STICKEY_BLOCK.h"
#include "JETPACK.h"
#include "ONEUP.h"
#include "COIN.h"

CHARA** CHARA_MANAGER::Chara = 0;

CHARA_MANAGER::CHARA_MANAGER() {
	MAP* map = MAP::getInstance();
	Total = 0;
	Total += map->playersNum();
	Total += map->ballsNum();
	Total += map->deffendersNum();
	Total += map->springsNum();
	Total += map->windsNum();
	Total += map->goalsNum();
	Total += map->blockNum();
	Total += map->jetpackNum();
	Total += map->oneupNum();
	Total += map->coinNum();
	Chara = new CHARA*[Total];

	int i, j = 0;
	PlayersIdx = j;
	for (i = 0; i < map->playersNum();		i++)Chara[j++] = new PLAYER;

	BallsIdx = j;
	for (i = 0; i < map->ballsNum();		i++)Chara[j++] = new BALL;
	
	SpringsIdx = j;
	for (i = 0; i < map->springsNum();		i++)Chara[j++] = new SPRING;
	
	DeffendersIdx = j;
	for (i = 0; i < map->deffendersNum();	i++)Chara[j++] = new DEFFENDER;
	
	WindsIdx = j;
	for (i = 0; i < map->windsNum();		i++)Chara[j++] = new WIND;
	
	GoalsIdx = j;
	for (i = 0; i < map->goalsNum();		i++)Chara[j++] = new GOAL;

	blocksIdx = j;
	for (i = 0; i < map->blockNum();		i++)Chara[j++] = new STICKY_BLOCK;

	jetpackIdx = j;
	for (i = 0; i < map->jetpackNum();		i++)Chara[j++] = new JETPACK;

	oneupIdx = j;
	for (i = 0; i < map->oneupNum();		i++)Chara[j++] = new ONEUP;

	coinIdx = j;
	for (i = 0; i < map->coinNum();			i++)Chara[j++] = new COIN;
}


CHARA_MANAGER::~CHARA_MANAGER() {
	for (int i = 0; i < Total; i++) {
		delete Chara[i];
	}
	delete[]Chara;
}


void CHARA_MANAGER::init() {
	for (int i = 0; i < Total; i++) {
		Chara[i]->init();
	}
}

void CHARA_MANAGER::appear(char charaId, float px, float py, float rad, float dx, float dy) {
	for (int i = 0; i < Total; i++) {
		if (Chara[i]->charaId() == charaId) {
			if (Chara[i]->alpha() <= 0.0f) {
				Chara[i]->appear(px, py, rad, dx, dy);
				break;
			}
		}
	}
}

void CHARA_MANAGER::update() {
	MAP* map = MAP::getInstance();
	for (int i = 0; i < Total; i++) {
		if (Chara[i]->alpha() > 0.0f) {
			Chara[i]->update();
		}
	}
	for (int i = 0; i < Total; i++) {
		if (map->stageNum() < 50) {
			if (Chara[i]->alpha() == 0.0f || Chara[i] == Chara[BallsIdx]) {
				continue;
			}
			if (Chara[BallsIdx]->pRight() > Chara[i]->pLeft() &&
				Chara[BallsIdx]->pLeft() < Chara[i]->pRight() &&
				Chara[BallsIdx]->pBottom() > Chara[i]->pTop() &&
				Chara[BallsIdx]->pTop() < Chara[i]->pBottom()) {
				Chara[BallsIdx]->management(Chara[i]->charaId(), Chara[i]->px(), Chara[i]->py());
				Chara[i]->management(Chara[BallsIdx]->charaId(), Chara[BallsIdx]->px(), Chara[BallsIdx]->py());
			}
		}
		else {
			if (Chara[i]->alpha() == 0.0f || Chara[i] == Chara[PlayersIdx]) {
				continue;
			}
			if (Chara[PlayersIdx]->pRight() > Chara[i]->pLeft() &&
				Chara[PlayersIdx]->pLeft() < Chara[i]->pRight() &&
				Chara[PlayersIdx]->pBottom() > Chara[i]->pTop() &&
				Chara[PlayersIdx]->pTop() < Chara[i]->pBottom()) {
				Chara[PlayersIdx]->management(Chara[i]->charaId(), Chara[i]->px(), Chara[i]->py());
				Chara[i]->management(Chara[PlayersIdx]->charaId(), Chara[PlayersIdx]->px(), Chara[PlayersIdx]->py());
			}
		}
	}
}

void CHARA_MANAGER::draw() {
	for (int i = 0; i < Total; i++) {
		if (Chara[i]->alpha() > 0.0f) {
			Chara[i]->draw();
		}
	}
}

//オモテ
bool CHARA_MANAGER::ballgoal() {
	BALL* ball = dynamic_cast<BALL*>(Chara[BallsIdx]);
	return ball->state() == BALL::BALL_STATE_GOAL;
}

bool CHARA_MANAGER::ballmissed() {
	BALL* ball = dynamic_cast<BALL*>(Chara[BallsIdx]);
	return ball->state() == BALL::BALL_STATE_MISS;
}

bool CHARA_MANAGER::playercatch() {
	BALL* ball = dynamic_cast<BALL*>(Chara[BallsIdx]);
	return ball->state() == BALL::BALL_STATE_HAVE;
}

bool CHARA_MANAGER::balloneup() {
	BALL* ball = dynamic_cast<BALL*>(Chara[BallsIdx]);
	return ball->state() == BALL::BALL_STATE_ONEUP;
}

//裏モード
bool CHARA_MANAGER::playergoal() {
	PLAYER* player = dynamic_cast<PLAYER*>(Chara[PlayersIdx]);
	return player->pb_state() == PLAYER::PLAYER_BALL_STATE_GOAL;
}
bool CHARA_MANAGER::playermissed() {
	PLAYER* player = dynamic_cast<PLAYER*>(Chara[PlayersIdx]);
	return player->pb_state() == PLAYER::PLAYER_BALL_STATE_MISS;
}
bool CHARA_MANAGER::playeroneup() {
	PLAYER* player = dynamic_cast<PLAYER*>(Chara[PlayersIdx]);
	return player->pb_state() == PLAYER::PLAYER_BALL_STATE_ONEUP;
}