#include "CONTAINER_MANAGER.h"
#include "CHARA.h"
//CHARA* CHARA::Chara = 0;
//
//CHARA* CHARA::getInstance() {
//	if (!Chara) {
//		Chara = new CHARA;
//	}
//	return Chara;
//}
//
//CHARA* CHARA::destroy() {
//	if (Chara) {
//		delete Chara;
//		Chara = 0;
//	}
//	return Chara;
//}

CHARA::CHARA() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	offsetPx = C->ad.system.OffsetPx;
	offsetPy = C->ad.system.OffsetPy;
	ChipSize = C->chipSize;
}

void CHARA::init() {
}

void CHARA::appear(float px, float py, float rad, float dx, float dy) {
	Alpha = 1.0f;
	Px = px;
	Py = py;
	Rad = rad;
	Color = COLOR(Red, Green, Blue, Alpha);
}

void CHARA::update() {
}

void CHARA::draw() {
	drawImage(Img, Px, Py, Color);
}

void CHARA::management(char CharaId, float px, float py){
}

void CHARA::initRGBA() {
	Alpha = 1.0f;
	Red = 1.0f;
	Blue = 1.0f;
	Green = 1.0f;
}

float CHARA::px() { return Px; }
float CHARA::py() {	return Py; }
float CHARA::rad() { return Rad; }
float CHARA::dx() { return Dx; }
float CHARA::dy() { return Dy; }
float CHARA::alpha() { return Alpha; }
char CHARA::charaId() { return CharaId; }
float CHARA::pBottom() { return Py + ChipSize; }
float CHARA::pTop() { return Py; }
float CHARA::pRight() { return Px + ChipSize; }
float CHARA::pLeft() { return Px; }
