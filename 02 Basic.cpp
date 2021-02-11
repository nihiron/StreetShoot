#include"framework.h"
#include"window.h"
#include"GAME.h"
#include <stdlib.h>

void gmain() {
	//////別のファイルを実行することできる関数。
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
