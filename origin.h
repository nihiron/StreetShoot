#pragma once
#define koujun "des"
#define shoujun "asc"
#define middle "mid"
#define moment "mom"

struct origin {
	//1.0 - �����l������
	float atai = 0;
	//1�t���[���ő��������
	float Valperexe = 0;
};

//�ԁB�l�K/�|�W���]
//���������Bdes 0���瑝�₷�Basc 1���猸�炷�Bmid �����l���瓮���� mom ��u
void exechangeRed(float* R, int loopCnt, const char* mode);

//�΁B�l�K/�|�W���]
void exechangeGreen(float* G, int loopCnt, const char* mode);

//�B�l�K/�|�W���]
void exechangeBlue(float* B, int loopCnt, const char* mode);

//�l�K/�|�W���]
void exechangeTone(float* R, float* G, float* B, int loopCnt, const char* mode);

//���ԕt���G�t�F�N�g�`��B
void drawEffect(int loopCnt, float px, float py, float rad, int img);