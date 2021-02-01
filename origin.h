#pragma once
#define koujun "des"
#define shoujun "asc"
#define middle "mid"
#define moment "mom"

struct origin {
	//1.0 - 初期値を入れる
	float atai = 0;
	//1フレームで増減する量
	float Valperexe = 0;
};

//赤。ネガ/ポジ反転
//動かし方。des 0から増やす。asc 1から減らす。mid 初期値から動かす mom 一瞬
void exechangeRed(float* R, int loopCnt, const char* mode);

//緑。ネガ/ポジ反転
void exechangeGreen(float* G, int loopCnt, const char* mode);

//青。ネガ/ポジ反転
void exechangeBlue(float* B, int loopCnt, const char* mode);

//ネガ/ポジ反転
void exechangeTone(float* R, float* G, float* B, int loopCnt, const char* mode);

//時間付きエフェクト描画。
void drawEffect(int loopCnt, float px, float py, float rad, int img);