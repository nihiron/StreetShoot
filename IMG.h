#pragma once
#include "graphic.h"
#include "CONTAINER_MANAGER.h"
//#include "origin.h"

	struct IMAGE {
		int Img = 0;
		float Px = 0.0f;
		float Py = 0.0f;
		//�l���傫���ƐF���Z���Ȃ�
		float R = 0.0f;//Red	�Ԃ̒l�B1.0�`0.0f
		float G = 0.0f;//Green	�΂̒l�B1.0�`0.0f
		float B = 0.0f;//Blue	�̒l�B1.0�`0.0f
		float A = 0.0f;//Alpha	�����x�B1.0�`0.0f
		void draw() {
			drawImage(Img, Px, Py, COLOR(R, G, B, A));
		}
		//�v���C��ʂ��ӂ�[���Əo�Ă���悤�ɂ���
		void feedin() {
			//��������Ȃ��Ȃ�
			if (A >= 0.0f) {
				//�����x���グ��
				A -= 0.07f;
			}
		}
		//�v���C��ʂ��ӂ�[���Ə�����悤�ɂ���
		void feedout() {
			//�����Ȃ�
			if (A <= 1.0f) {
				//�����x��������
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
