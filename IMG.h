#pragma once
#include "graphic.h"
#include "CONTAINER_MANAGER.h"
//#include "origin.h"

	struct IMAGE {
		int Img = 0;
		float Px = 0.0f;
		float Py = 0.0f;
		//値が大きいと色が濃くなる
		float R = 0.0f;//Red	赤の値。1.0～0.0f
		float G = 0.0f;//Green	緑の値。1.0～0.0f
		float B = 0.0f;//Blue	青の値。1.0～0.0f
		float A = 0.0f;//Alpha	透明度。1.0～0.0f
		void draw() {
			drawImage(Img, Px, Py, COLOR(R, G, B, A));
		}
		//プレイ画面がふわーっと出てくるようにする
		void feedin() {
			//透明じゃないなら
			if (A >= 0.0f) {
				//透明度を上げる
				A -= 0.07f;
			}
		}
		//プレイ画面がふわーっと消えるようにする
		void feedout() {
			//透明なら
			if (A <= 1.0f) {
				//透明度を下げる
				A += 0.07f;
			}
		}
		void blackout() {
			//exechangeTone(R, G, B, 30);
			R = 0.0f;
			G = 0.0f;
			B = 0.0f;
		}
		void colorring() {
			//exechangeTone(R, G, B, 30);
			R = 1.0f;
			G = 1.0f;
			B = 1.0f;
		}
		float alpha() { return A; }
	};

class IMG {
public:
	IMG();
	void draw();

	void feedin();
	void feedout();
	void blackout();
	void colorring();

	float alpha();


	IMAGE TITLE;
	IMAGE TITLELOGO;
	IMAGE BACK;
	IMAGE DUNGEON;
	IMAGE CLEAR;
	IMAGE FAILED;
	IMAGE GAMEOVER;
	IMAGE FEED;


protected:
	int Img = 0;
	float Px = 0;
	float Py = 0;
	float Red = 1.0f;
	float Green = 1.0f;
	float Blue = 1.0f;
	float Alpha = 1.0f;

};
