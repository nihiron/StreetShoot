#include "ONEUP.h"
#include "CONTAINER_MANAGER.h"

ONEUP::ONEUP() : CHARA() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	Img = C->ad.ball.BallImg;
	CharaId = C->ad.one.OneupId;
	Blue = 0.5f;
	Green = 1.0f;
	Red = 0.0f;
}

void ONEUP::init() {

}

void ONEUP::management(char CharaId, float px, float py) {
	Alpha = 0.0f;
}

//float ONEUP::pLeft() { return Px + 25; }
//float ONEUP::pTop() { return Py + 25; }
//float ONEUP::pRight() { return Px + 35; }
//float ONEUP::pBottom() { return Py + 35; }