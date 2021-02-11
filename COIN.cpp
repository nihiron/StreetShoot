#include "COIN.h"
#include "CONTAINER_MANAGER.h"

COIN::COIN() :CHARA() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	Img = C->Handle[Coin];
	CharaId = C->ad.coin.CoinId;
}

void COIN::draw() {
	drawImage(Img, Px + offsetPx, Py + offsetPy, Rad);
}

void COIN::management(char CharaId, float px, float py) {
	Alpha = 0.0f;
}
//
//float COIN::pLeft() { return Px; }
//float COIN::pTop() { return Py; }
//float COIN::pRight() { return Px + 40; }
//float COIN::pBottom() { return Py + 40; }