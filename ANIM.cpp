#include "ANIM.h"
#include "graphic.h"
#include <stdio.h>

ANIM::~ANIM() {
	if (Images) { delete Images; Images = 0; }
}

//âÊëúê∂ê¨
void ANIM::create(int imagesnum, const char* filename, int toggleframe) {
	num = imagesnum;
	Toggleframe = toggleframe;
	Images = new int[num];
	char Filename[256];
	for (int i = 0; i < num; i++) {
		sprintf_s(Filename, "%s%d.png", filename, i + 1);
		Images[i] = loadImage(Filename);
	}
}

void ANIM::draw(float px, float py) {
	int i = 0;
	if (num > 1) {
		i = animCnt / num % animCnt;
		animCnt %= num * Toggleframe;
	}
	drawImage(Images[i], px, py);
}
