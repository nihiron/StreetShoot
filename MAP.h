#pragma once
//class CONTAINER;

class MAP {
public:
	//MAP();
	~MAP();
	void init(const char* Filename, int stagenum);
	void update(float dx, float dy);
	void draw();

	int hiddenmap();

	bool collisionCheck(float px, float py);
	bool collisionRight(float px, float py);
	bool collisionTop(float px, float py);
	bool collisionLeft(float px, float py);
	bool collisionBottom(float px, float py);


	int stageNum();
	int playersNum();
	int ballsNum();
	int springsNum();
	int windsNum();
	int deffendersNum();
	int goalsNum();
	int blockNum();
	int jetpackNum();
	int oneupNum();
	int coinNum();

	//static void setContainer(CONTAINER* c) { C = c; }


	//シングルトン実装のため追加したもの---------------------------------------

	//インスタンスをnewする関数
	static MAP* getInstance();

	//インスタンスを開放する関数
	static MAP* destroy();

private:

	//静的な MAP のインスタンス
	static MAP* Map;

	//-------------------------------------------------------------------------
	//static CONTAINER* C;
	MAP();
	int blockImg = 0;
	char* Data = 0;
	int NumDataCol = 0;
	int NumDataRow = 0;
	int chipSize = 0;
	int Hiddenmap = 0;
	float offsetPx = 0;
	float offsetPy = 0;
	int StageNum = 0;
	int windowwidth = 0;
	int windowheight = 0;

	int PlayersNum = 0;
	int BallsNum = 0;
	int SpringsNum = 0;
	int WindsNum = 0;
	int DeffendersNum = 0;
	int GoalsNum = 0;
	int BlockNum = 0;
	int JetpackNum = 0;
	int OneupNum = 0;
	int CoinNum = 0;
};