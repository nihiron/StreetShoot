#pragma once
#include "MAP.h"
class CHARA;

class CHARA_MANAGER {
public:
	~CHARA_MANAGER();
	void init();
	void appear(char charaId, float px, float py, float rad, float dx, float dy);
	void update();
	void draw();

	bool ballgoal();
	bool ballmissed();
	bool playercatch();
	bool balloneup();

	bool playergoal();
	bool playermissed();
	bool playeroneup();
	
	static void setChara(CHARA** chara) { Chara = chara; }


private:
	friend class MANAGER_CharaManager;

	CHARA_MANAGER();
	int Total = 0;
	int PlayersIdx = 0;
	int BallsIdx = 0;
	int DeffendersIdx = 0;
	int SpringsIdx = 0;
	int WindsIdx = 0;
	int GoalsIdx = 0;
	int blocksIdx = 0;
	int jetpackIdx = 0;
	int oneupIdx = 0;
	int coinIdx = 0;
	static CHARA** Chara;
};
