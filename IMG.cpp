#include "IMG.h"

IMG::IMG() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();

	FAILED = {
		FAILED.Img = C->Handle[Failed],
		FAILED.Px = C->ad.Backs[Failed].Px,
		FAILED.Py = C->ad.Backs[Failed].Py,
		FAILED.R = 1.0f,
		FAILED.G = 1.0f,
		FAILED.B = 1.0f,
		FAILED.A = 1.0f
	};
	FEED = {
		FEED.Img = C->Handle[Feed],
		FEED.Px = C->ad.Backs[Feed].Px,
		FEED.Py = C->ad.Backs[Feed].Py,
		FEED.R = 1.0f,
		FEED.G = 1.0f,
		FEED.B = 1.0f,
		FEED.A = 1.0f
	};
	TITLE = {
		TITLE.Img = C->Handle[Title],
		TITLE.Px = C->ad.Backs[Title].Px,
		TITLE.Py = C->ad.Backs[Title].Py,
		TITLE.R = 1.0f,
		TITLE.G = 1.0f,
		TITLE.B = 1.0f,
		TITLE.A = 1.0f
	};
	TITLELOGO = {
		TITLELOGO.Img = C->Handle[TitleLogo],
		TITLELOGO.Px = C->ad.Backs[TitleLogo].Px,
		TITLELOGO.Py = C->ad.Backs[TitleLogo].Py,
		TITLELOGO.R = 1.0f,
		TITLELOGO.G = 1.0f,
		TITLELOGO.B = 1.0f,
		TITLELOGO.A = 1.0f
	};
	CLEAR = {
		CLEAR.Img = C->Handle[Clear],
		CLEAR.Px = C->ad.Backs[Clear].Px,
		CLEAR.Py = C->ad.Backs[Clear].Py,
		CLEAR.R = 1.0f,
		CLEAR.G = 1.0f,
		CLEAR.B = 1.0f,
		CLEAR.A = 1.0f
	};
	DUNGEON = {
		DUNGEON.Img = C->Handle[Dungeon],
		DUNGEON.Px = C->ad.Backs[Dungeon].Px,
		DUNGEON.Py = C->ad.Backs[Dungeon].Py,
		DUNGEON.R = 1.0f,
		DUNGEON.G = 1.0f,
		DUNGEON.B = 1.0f,
		DUNGEON.A = 1.0f
	};
	BACK = {
		BACK.Img = C->Handle[Back],
		BACK.Px = C->ad.Backs[Back].Px,
		BACK.Py = C->ad.Backs[Back].Py,
		BACK.R = 1.0f,
		BACK.G = 1.0f,
		BACK.B = 1.0f,
		BACK.A = 1.0f
	};
	GAMEOVER = {
		GAMEOVER.Img = C->Handle[GameOver],
		GAMEOVER.Px = C->ad.Backs[GameOver].Px,
		GAMEOVER.Py = C->ad.Backs[GameOver].Py,
		GAMEOVER.R = 1.0f,
		GAMEOVER.G = 1.0f,
		GAMEOVER.B = 1.0f,
		GAMEOVER.A = 1.0f
	};
	FEED = {
		FEED.Img = C->Handle[Feed],
		FEED.Px = C->ad.Backs[Feed].Px,
		FEED.Py = C->ad.Backs[Feed].Py,
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