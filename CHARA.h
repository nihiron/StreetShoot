#pragma once
#include "COLOR.h"

class CHARA {
public:
	virtual void init();
	virtual void appear(float px, float py, float rad, float dx, float dy);
	virtual void update();
	virtual void draw();

	virtual void management(char CharaId, float px, float py);

	float px();
	float py();
	float rad();
	float dx();
	float dy();
	float alpha();
	char charaId();

	virtual float pBottom();
	virtual float pTop();
	virtual float pRight();
	virtual float pLeft();


	//static CHARA* getInstance();
	//static CHARA* destroy();

	CHARA();
//private:
//	static CHARA* Chara;
protected:
	void initRGBA();
	int Img = 0;
	float Px = 0;
	float Py = 0;
	float Rad = 0;
	float Dx = 0;
	float Dy = 0;
	char CharaId = 0;
	float Red = 1.0f;
	float Blue = 1.0f;
	float Green = 1.0f;
	float Alpha = 0.0f;
	COLOR Color;
	float offsetPx = 0.0f;
	float offsetPy = 0.0f;
	int ChipSize = 0;
};