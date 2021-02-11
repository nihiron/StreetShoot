#include "DEFFENDER.h"
#include "CONTAINER_MANAGER.h"

DEFFENDER::DEFFENDER() : CHARA() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	Img = C->Handle[Deffender];
	CharaId = C->ad.deffender.DeffenderId;
}

void DEFFENDER::init() {
}

void DEFFENDER::update() {

}

void DEFFENDER::management(char CharaId, float px, float py) {
}

float DEFFENDER::pTop() { return Py + 29; }
float DEFFENDER::pBottom() { return Py + 211; }
float DEFFENDER::pRight () { return Px + 133; }
float DEFFENDER::pLeft() { return Px + 45; }