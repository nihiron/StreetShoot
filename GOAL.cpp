#include "GOAL.h"
#include "CONTAINER_MANAGER.h"

GOAL::GOAL() :CHARA() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	Img = C->Handle[Goal];
	CharaId = C->ad.goal.GoalId;
}

void GOAL::init() {

}

void GOAL::appear(float px, float py, float dx, float dy) {

}

void GOAL::update() {

}

float GOAL::pBottom() { return Py + 60; }
float GOAL::pTop() { return Py + 26; }
float GOAL::pLeft() { return Px + 10; }
float GOAL::pRight() { return Px + 45; }