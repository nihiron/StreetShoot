#include"framework.h"
#include"window.h"
#include"GAME.h"
#include <stdlib.h>

void gmain() {
	//////�ʂ̃t�@�C�������s���邱�Ƃł���֐��B
#ifdef _DEBUG
	system("../Project1");
	return;
#endif
	GAME* game = new GAME;
	while (msgProc()) {
		game->proc();
	}
	delete game;
	CONTAINER_MANAGER::destroy();
}
