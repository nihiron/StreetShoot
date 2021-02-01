#include"framework.h"
#include"window.h"
#include"GAME.h"
#include <stdio.h>

void gmain() {
	//CONTAINER* C = CONTAINER_MANAGER::getInstance();
	//FILE* fp = 0;
	//fopen_s(&fp, "data/SYSTEM_DATA.bin","rb");
	//fread(&C->ad, sizeof(ALL_DATA), 58, fp);
	//fclose(fp);

	GAME* game = new GAME;
	while (msgProc()) {
		game->proc();
	}
	delete game;
	CONTAINER_MANAGER::destroy();
}
