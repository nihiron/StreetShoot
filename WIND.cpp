#include "WIND.h"
#include "rand.h"

WIND::WIND() : CHARA() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	Img = C->ad.wind.WindImg;
	CharaId = C->ad.wind.WindId;
	turn = C->ad.wind.Windturn;
	turnchagepercent = C->ad.wind.WindPercent;
	ChangeInterval = C->ad.wind.WCPInterval;
}

void WIND::init() {
}

void WIND::update() {
		CONTAINER* C = CONTAINER_MANAGER::getInstance();
	Rad += turn;
	ChangeInterval--;
	if (ChangeInterval < 0) {
		if (getRand() % turnchagepercent <= 3) {
			turn = -turn;
		}
		ChangeInterval = C->ad.wind.WCPInterval;
	}
}

void WIND::draw() {
	drawImage(Img, Px + offsetPx, Py + offsetPy, Rad, Color);
}

void WIND::management(char CharaId, float px, float py) {
}