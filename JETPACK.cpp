#include "JETPACK.h"
#include "CONTAINER_MANAGER.h"

JETPACK::JETPACK() : CHARA() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	Img = C->Handle[Jet];
	CharaId = C->ad.jet.JetId;
}

void JETPACK::draw() {
	drawImage(Img, Px + offsetPx, Py + offsetPy, Rad);
}

void JETPACK::management(char CharaId, float px, float py) {
	Alpha = 0.0f;
}
//
//float JETPACK::pLeft() { return Px; }
//float JETPACK::pTop() { return Py; }
//float JETPACK::pRight() { return Px + 40; }
//float JETPACK::pBottom() { return Py + 40; }