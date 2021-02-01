#include "IMG.h"

IMG::IMG() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();

	FAILED = {
		FAILED.Img = C->ad.failed.Img,
		FAILED.Px = C->ad.failed.Px,
		FAILED.Py = C->ad.failed.Py,
		FAILED.R = 1.0f,
		FAILED.G = 1.0f,
		FAILED.B = 1.0f,
		FAILED.A = 1.0f
	};
	FEED = {
		FEED.Img = C->ad.feed.Img,
		FEED.Px = C->ad.feed.Px,
		FEED.Py = C->ad.feed.Py,
		FEED.R = 1.0f,
		FEED.G = 1.0f,
		FEED.B = 1.0f,
		FEED.A = 1.0f
	};
	TITLE = {
		TITLE.Img = C->ad.title.Img,
		TITLE.Px = C->ad.title.Px,
		TITLE.Py = C->ad.title.Py,
		TITLE.R = 1.0f,
		TITLE.G = 1.0f,
		TITLE.B = 1.0f,
		TITLE.A = 1.0f
	};
	TITLELOGO = {
		TITLELOGO.Img = C->ad.titlelogo.Img,
		TITLELOGO.Px = C->ad.titlelogo.Px,
		TITLELOGO.Py = C->ad.titlelogo.Py,
		TITLELOGO.R = 1.0f,
		TITLELOGO.G = 1.0f,
		TITLELOGO.B = 1.0f,
		TITLELOGO.A = 1.0f
	};
	CLEAR = {
		CLEAR.Img = C->ad.clear.Img,
		CLEAR.Px = C->ad.clear.Px,
		CLEAR.Py = C->ad.clear.Py,
		CLEAR.R = 1.0f,
		CLEAR.G = 1.0f,
		CLEAR.B = 1.0f,
		CLEAR.A = 1.0f
	};
	DUNGEON = {
		DUNGEON.Img = C->ad.dungeon.Img,
		DUNGEON.Px = C->ad.dungeon.Px,
		DUNGEON.Py = C->ad.dungeon.Py,
		DUNGEON.R = 1.0f,
		DUNGEON.G = 1.0f,
		DUNGEON.B = 1.0f,
		DUNGEON.A = 1.0f
	};
	BACK = {
		BACK.Img = C->ad.back.Img,
		BACK.Px = C->ad.back.Px,
		BACK.Py = C->ad.back.Py,
		BACK.R = 1.0f,
		BACK.G = 1.0f,
		BACK.B = 1.0f,
		BACK.A = 1.0f
	};
	GAMEOVER = {
		GAMEOVER.Img = C->ad.gameover.Img,
		GAMEOVER.Px = C->ad.gameover.Px,
		GAMEOVER.Py = C->ad.gameover.Py,
		GAMEOVER.R = 1.0f,
		GAMEOVER.G = 1.0f,
		GAMEOVER.B = 1.0f,
		GAMEOVER.A = 1.0f
	};
	FEED = {
		FEED.Img = C->ad.feed.Img,
		FEED.Px = C->ad.feed.Px,
		FEED.Py = C->ad.feed.Py,
		FEED.R = 1.0f,
		FEED.G = 1.0f,
		FEED.B = 1.0f,
		FEED.A = 0.0f
	};
	//FAILED = {
	//	FAILED.Img = C->failed.Img,
	//	FAILED.Px = C->failed.Px,
	//	FAILED.Py = C->failed.Py,
	//	FAILED.R = 1.0f,
	//	FAILED.G = 1.0f,
	//	FAILED.B = 1.0f,
	//	FAILED.A = 1.0f
	//};
	//FEED = {
	//	FEED.Img = C->feed.Img,
	//	FEED.Px = C->feed.Px,
	//	FEED.Py = C->feed.Py,
	//	FEED.R = 1.0f,
	//	FEED.G = 1.0f,
	//	FEED.B = 1.0f,
	//	FEED.A = 1.0f
	//};
	//TITLE = {
	//	TITLE.Img = C->title.Img,
	//	TITLE.Px = C->title.Px,
	//	TITLE.Py = C->title.Py,
	//	TITLE.R = 1.0f,
	//	TITLE.G = 1.0f,
	//	TITLE.B = 1.0f,
	//	TITLE.A = 1.0f
	//};
	//TITLELOGO = {
	//	TITLELOGO.Img = C->titlelogo.Img,
	//	TITLELOGO.Px = C->titlelogo.Px,
	//	TITLELOGO.Py = C->titlelogo.Py,
	//	TITLELOGO.R = 1.0f,
	//	TITLELOGO.G = 1.0f,
	//	TITLELOGO.B = 1.0f,
	//	TITLELOGO.A = 1.0f
	//};
	//CLEAR = {
	//	CLEAR.Img = C->clear.Img,
	//	CLEAR.Px = C->clear.Px,
	//	CLEAR.Py = C->clear.Py,
	//	CLEAR.R = 1.0f,
	//	CLEAR.G = 1.0f,
	//	CLEAR.B = 1.0f,
	//	CLEAR.A = 1.0f
	//};
	//DUNGEON = {
	//	DUNGEON.Img = C->dungeon.Img,
	//	DUNGEON.Px = C->dungeon.Px,
	//	DUNGEON.Py = C->dungeon.Py,
	//	DUNGEON.R = 1.0f,
	//	DUNGEON.G = 1.0f,
	//	DUNGEON.B = 1.0f,
	//	DUNGEON.A = 1.0f
	//};
	//BACK = {
	//	BACK.Img = C->back.Img,
	//	BACK.Px = C->back.Px,
	//	BACK.Py = C->back.Py,
	//	BACK.R = 1.0f,
	//	BACK.G = 1.0f,
	//	BACK.B = 1.0f,
	//	BACK.A = 1.0f
	//};
	//GAMEOVER = {
	//	GAMEOVER.Img = C->gameover.Img,
	//	GAMEOVER.Px = C->gameover.Px,
	//	GAMEOVER.Py = C->gameover.Py,
	//	GAMEOVER.R = 1.0f,
	//	GAMEOVER.G = 1.0f,
	//	GAMEOVER.B = 1.0f,
	//	GAMEOVER.A = 1.0f
	//};
	//FEED = {
	//	FEED.Img = C->feed.Img,
	//	FEED.Px = C->feed.Px,
	//	FEED.Py = C->feed.Py,
	//	FEED.R = 1.0f,
	//	FEED.G = 1.0f,
	//	FEED.B = 1.0f,
	//	FEED.A = 0.0f
	//};
}
void IMG::draw() {
	drawImage(Img, Px, Py, COLOR(Red, Green, Blue, Alpha));
}

void IMG::feedin() {
	if (Alpha >= 0.0f) {
		Alpha -= 0.07f;
	}
}
void IMG::feedout() {
	if (Alpha <= 1.0f) {
		Alpha += 0.07f;
	}
}

void IMG::blackout() {
	Red = 0.0f;
	Green = 0.0f;
	Blue = 0.0f;
}
void IMG::colorring() {
	Red = 1.0f;
	Green = 1.0f;
	Blue = 1.0f;
}

float IMG::alpha() { return Alpha; }