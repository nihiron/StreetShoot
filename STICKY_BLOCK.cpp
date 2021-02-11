#include "STICKEY_BLOCK.h"
#include "CONTAINER_MANAGER.h"

STICKY_BLOCK::STICKY_BLOCK() :CHARA() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	Img = C->Handle[Stickey];
	CharaId = C->ad.stickey.StickeyId;
}

void STICKY_BLOCK::init() {

}
void STICKY_BLOCK::appear(float px, float py, float dx, float dy) {

}
void STICKY_BLOCK::update() {

}