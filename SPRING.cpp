#include "SPRING.h"
#include "CONTAINER_MANAGER.h"

SPRING::SPRING() : CHARA() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	Img = C->Handle[Spring];
	CharaId = C->ad.spring.SpringId;
}

void SPRING::init() {
}

void SPRING::update() {
}

void SPRING::management(char CharaId, float px, float py) {
}

float SPRING::pLeft() { return Px + 3; }
float SPRING::pRight() { return Px + 57; }
float SPRING::pBottom() { return Py + 60; }
float SPRING::pTop() { return Py + 5; }