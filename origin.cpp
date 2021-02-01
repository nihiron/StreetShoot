#include "graphic.h"
#include "origin.h"

//赤反転
void exechangeRed(float* R, int loopCnt, const char* mode) {
	origin test;
	if (!test.atai) {
		test.atai = 1.0f - *R;
		test.Valperexe = test.atai / loopCnt;
	}
	*R += test.Valperexe;
	//0から
	if (mode == koujun) {
		if (*R >= test.atai) {
			*R = test.atai;
		}
		return;
	}
	//1から
	if (mode == shoujun) {
		test.Valperexe = -test.Valperexe;
		if (*R <= test.atai) {
			*R = test.atai;
		}
		return;
	}
	//途中から
	if (mode == middle) {
		if (test.atai > * R) {
			if (test.atai == 1.0f - *R) {
				test.Valperexe = -test.Valperexe;
			}
		}
		if (test.Valperexe > 0.0f) {
			if (*R >= test.atai) {
				*R = test.atai;
			}
		}
		if (test.Valperexe < 0.0f) {
			if (*R <= test.atai) {
				*R = test.atai;
			}
		}
		return;
	}
	//一瞬
	if (mode == moment) {
		*R = 1.0f - *R;
		return;
	}
}

//緑反転
void exechangeGreen(float* G, int loopCnt, const char* mode) {
	origin test;
	if (!test.atai) {
		test.atai = 1.0f - *G;
		test.Valperexe = test.atai / loopCnt;
	}
	*G += test.Valperexe;
	//0から
	if (mode == koujun) {
		if (*G >= test.atai) {
			*G = test.atai;
		}
		return;
	}
	//1から
	if (mode == shoujun) {
		test.Valperexe = -test.Valperexe;
		if (*G <= test.atai) {
			*G = test.atai;
		}
		return;
	}
	//途中から
	if (mode == middle) {
		if (test.atai > * G) {
			if (test.atai == 1.0f - *G) {
				test.Valperexe = -test.Valperexe;
			}
		}
		if (test.Valperexe > 0.0f) {
			if (*G >= test.atai) {
				*G = test.atai;
			}
		}
		if (test.Valperexe < 0.0f) {
			if (*G <= test.atai) {
				*G = test.atai;
			}
		}
		return;
	}
	//一瞬
	if (mode == moment) {
		*G = 1.0f - *G;
		return;
	}
}

//青反転
void exechangeBlue(float* B, int loopCnt, const char* mode) {
	origin test;
	if (!test.atai) {
		test.atai = 1.0f - *B;
		test.Valperexe = test.atai / loopCnt;
	}
	*B += test.Valperexe;
	//0から
	if (mode == koujun) {
		if (*B >= test.atai) {
			*B = test.atai;
		}
		return;
	}
	//1から
	if (mode == shoujun) {
		test.Valperexe = -test.Valperexe;
		if (*B <= test.atai) {
			*B = test.atai;
		}
		return;
	}
	//途中から
	if (mode == middle) {
		if (test.atai > * B) {
			if (test.atai == 1.0f - *B) {
				test.Valperexe = -test.Valperexe;
			}
		}
		if (test.Valperexe > 0.0f) {
			if (*B >= test.atai) {
				*B = test.atai;
			}
		}
		if (test.Valperexe < 0.0f) {
			if (*B <= test.atai) {
				*B = test.atai;
			}
		}
		return;
	}
	//一瞬
	if (mode == moment) {
		*B = 1.0f - *B;
		return;
	}
}

//白黒反転関数
void exechangeTone(float* R, float* G, float* B, int loopCnt, const char* mode) {
	exechangeRed(R, loopCnt, mode);
	exechangeGreen(G, loopCnt, mode);
	exechangeBlue(B, loopCnt, mode);
}

//時間付きエフェクト描画。ラジアンではない。マップで行っている場合、事前にその分の計算をしておくこと
void drawEffect(int loopCnt, float px, float py, float rad, int img) {
	//工事中！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	static int i = 0;
	if (i < loopCnt) {
		float Rad = 3.141592f / 180 * rad;
		drawImage(img, px, py, Rad);
	}
	else i = 0;
	i++;
}