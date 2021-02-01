#pragma once

class ANIM {
public:
	~ANIM();
	//画像数、ファイル名、切り替えフレーム
	void create(int imagesnum, const char* filename, int toggleframe);
	void draw(float px, float py);

private:
	int num = 0;
	int Toggleframe = 1;
	int* Images;
	int animCnt = 0;
};