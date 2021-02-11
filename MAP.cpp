#pragma warning(disable : 4996)
#include <stdio.h>
#include <sys/stat.h>
#include "common.h"
#include "MANAGER_CharaManager.h"
#include "MAP.h"
#include "CONTAINER_MANAGER.h"
//CONTAINER* MAP::C = 0;
MAP* MAP::Map = 0;

//シングルトン実装のため追加したもの-------------------------------------------|
MAP* MAP::getInstance() {
	if (!Map) {
		Map = new MAP;
	}
	return Map;
}

MAP* MAP::destroy() {
	if (Map) {
		delete Map;
		Map = 0;
	}
	return Map;
}
//-----------------------------------------------------------------------------|

MAP::MAP() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	blockImg = C->blockImg;
	chipSize = C->chipSize;
	BallsNum = C->ad.ball.BallsNum;
	offsetPx = C->ad.system.OffsetPx;
	offsetPy = C->ad.system.OffsetPy;
	windowwidth = C->WindowWidth;
	windowheight = C->WindowHeight;
}

MAP::~MAP() {
	if (Data) { delete[]Data; Data = 0; }
}

void MAP::init(const char* Filename,int stagenum) {
	SpringsNum = 0;
	WindsNum = 0;
	DeffendersNum = 0;
	GoalsNum = 0;
	BlockNum = 0;
	JetpackNum = 0;
	OneupNum = 0;
	CoinNum = 0;
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	StageNum = stagenum;
	const char* filename = Filename;
	//WARNING(fp == 0, "ファイルが見つからない", filename);
	FILE* fp = fopen(filename, "r");

	struct stat info;
	fstat(fileno(fp), &info);
	if (Data) { delete[]Data; Data = 0; }
	Data = new char[info.st_size];

	Hiddenmap = 0;
	NumDataCol = 0;
	NumDataRow = 0;
	int i = 0;
	char c = 0;

	while (fscanf(fp, "%c", &c) != EOF) {
		if (c != '\n') {
			Data[i] = c;
			if (c == 'p') { PlayersNum++; }
			if (c == 's') { SpringsNum++; }
			if (c == 'w') { WindsNum++; }
			if (c == 'd') { DeffendersNum++; }
			if (c == 'g') { GoalsNum++; }
			if (c == 'n') { BlockNum++; }
			if (c == 'j') { JetpackNum++; }
			if (c == 'o') { OneupNum++; }
			if (c == 'c') { CoinNum++; }
			i++;
		}
		else {
			if (NumDataRow == 0) {
				NumDataCol = i;
			}
			NumDataRow++;
		}
	}
	fclose(fp);
	if (NumDataRow * chipSize > C->WindowHeight) {
		Hiddenmap = NumDataRow * chipSize - C->WindowHeight;
	}
}

void MAP::update(float dx, float dy) {
}

void MAP::draw() {
	CHARA_MANAGER* CharaManager = MANAGER_CharaManager::getInstance();
	for (int col = 0; col < NumDataCol; col++) {
		for (int row = 0; row < NumDataRow; row++) {
			int i = col + row * NumDataCol;
			float px = col * chipSize;
			float py = row * chipSize - Hiddenmap;
			if (Data[i] == '1') { drawImage(blockImg, px, py); }
			else if ('a' <= Data[i] && Data[i] <= 'z') {
				CharaManager->appear(Data[i], px, py, 0, 0, 0);
				Data[i] = '.';
			}
		}
	}
}


//判定シリーズ------------------------------------------------
bool MAP::collisionCheck(float px, float py) {
	//上以外の画面外
	if (px > windowwidth || px < -chipSize || py > windowheight + Hiddenmap || py < -Hiddenmap)
		return false;

	int col = (int)px / chipSize;
	int row = (int)py / chipSize;

	// . は空白。 . 以外は何かしらの判定がある
	if (Data[col + row * NumDataCol] != '.'	) {
		return true;
	}
	return false;
}
bool MAP::collisionRight(float px, float py) {
	bool rightTop	 = collisionCheck(px + chipSize - 1 , py + Hiddenmap);
	bool rightBottom = collisionCheck(px + chipSize - 1 , py + Hiddenmap + chipSize - 1);
	return rightTop || rightBottom;
}
bool MAP::collisionLeft(float px, float py) {
	bool leftTop	 = collisionCheck(px, py + Hiddenmap);
	bool leftBottom	 = collisionCheck(px, py + Hiddenmap + chipSize - 1);
	return leftTop || leftBottom;
}
bool MAP::collisionTop(float px, float py) {
	bool topRight	 = collisionCheck(px + chipSize - 1, py + Hiddenmap);
	bool topLeft	 = collisionCheck(px		, py + Hiddenmap);
	return topRight || topLeft;
}
bool MAP::collisionBottom(float px, float py) {
	bool bottomRight = collisionCheck(px + chipSize - 1, py + Hiddenmap + chipSize - 1);
	bool bottomLeft	 = collisionCheck(px			, py + Hiddenmap + chipSize - 1);
	return bottomRight || bottomLeft;
}


//------------------------------------------------------------
int MAP::hiddenmap() { return Hiddenmap; }
int MAP::stageNum() { return StageNum; }

int MAP::playersNum() { return PlayersNum; }
int MAP::ballsNum() { return BallsNum; }
int MAP::springsNum() { return SpringsNum; }
int MAP::windsNum() { return WindsNum; }
int MAP::deffendersNum() { return DeffendersNum; }
int MAP::goalsNum() { return GoalsNum; }
int MAP::blockNum() { return BlockNum; }
int MAP::jetpackNum() { return JetpackNum; }
int MAP::oneupNum() { return OneupNum; }
int MAP::coinNum() { return CoinNum; }