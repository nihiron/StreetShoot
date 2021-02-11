//ストリートシュートの方のコンテナです！！！！！！！！！！
#pragma once
#include "framework.h"
#include "graphic.h"
#include "COLOR.h"
#include "debugStr.h"
#include "sound.h"
#include <stdio.h>
#include "CONTAINER_MANAGER.h"

enum IMGS {
	Title,
	TitleLogo,
	Back,
	Clear,
	Failed,
	GameOver,
	Dungeon,
	Ending,
	Feed,
	TYPE_MAX_BACKS,
	PBody,
	PLArm,
	PRArm,
	Ball,
	Deffender,
	Spring,
	Wind,
	Goal,
	Stickey,
	Jet,
	Oneup,
	Coin,
	PowerBar,
	PowerGauge,
	TYPE_MAX
};

struct IMAGEDATA {
	int Px = 0;
	int Py = 0;
};

//Total 49
struct SYSTEM_DATA {
	int PowerBarHeight;
	float OffsetPx;
	float OffsetPy;
	float Gravity;
	float RADIAN;
};
struct PLAYER_DATA {
	float UpperArmsOffsetPx;
	float UpperArmsOffsetPy;
	float DownerArmsOffsetPx;
	float DownerArmsOffsetPy;
	float PlayerOffsetPy;
	float MaxPower;
	int PlayersNum;
	float PlayerAllowedDistance;
	char PlayerId;
};
struct BALL_DATA {
	int BallsNum;
	float InitialPx;
	float InitialPy;
	int NotMoveCnt;
	int ReCollisionCnt;
	char BallId;
};
struct DEFF_DATA {
	char DeffenderId;
};
struct SPRING_DATA {
	char SpringId;
};
struct WIND_DATA {
	float Windturn;
	int WindPercent;
	int WCPInterval;
	char WindId;
};
struct GOAL_DATA {
	char GoalId;
};
struct STICKEY_DATA {
	char StickeyId;
};
struct JET_DATA {
	char JetId;
};
struct ONEUP_DATA {
	char OneupId;
};
struct COIN_DATA {
	char CoinId;
};

//struct ALL_DATA {
//	SYSTEM_DATA system;
//	PLAYER_DATA player;
//	BALL_DATA ball;
//	DEFF_DATA deffender;
//	SPRING_DATA spring;
//	WIND_DATA wind;
//	GOAL_DATA goal;
//	STICKEY_DATA stickey;
//	JET_DATA jet;
//	ONEUP_DATA one;
//	COIN_DATA coin;
//	IMAGEDATA Backs[TYPE_MAX_BACKS];
//};

//ここまでのデータを統合したもの


//struct SYSTEM_DATA {
//	int PowerBarHeight = 32;
//	float OffsetPx = 30.0f;
//	float OffsetPy = 30.0f;
//	float Gravity = 0.205f;
//	float RADIAN = 3.141592f / 180;
//};
//struct PLAYER_DATA {
//	float UpperArmsOffsetPx = 45;
//	float UpperArmsOffsetPy = 5;
//	float DownerArmsOffsetPx = 35;
//	float DownerArmsOffsetPy = 5;
//	float PlayerOffsetPy = 7.0f;
//	float MaxPower = 17.0f;
//	float PlayerAllowedDistance = 70.0f;
//	int PlayersNum = 1;
//	char PlayerId = 'p';
//};
//struct BALL_DATA {
//	int BallsNum = 1;
//	float InitialPx = -50.0f;
//	float InitialPy = -2000.0f;
//	int NotMoveCnt = 180;
//	int ReCollisionCnt = 5;
//	char BallId = 'b';
//};
//struct DEFF_DATA {
//	char DeffenderId = 'd';
//};
//struct SPRING_DATA {
//	char SpringId = 's';
//};
//struct WIND_DATA {
//	float Windturn = 0.5f;
//	int WindPercent = 10;
//	int WCPInterval = 300;
//	char WindId = 'w';
//};
//struct GOAL_DATA {
//	char GoalId = 'g';
//};
//struct STICKEY_DATA {
//	char StickeyId = 'n';
//};
//struct JET_DATA {
//	char JetId = 'j';
//};
//struct ONEUP_DATA {
//	char OneupId = 'o';
//};
//struct COIN_DATA {
//	char CoinId = 'c';
//};

struct ALL_DATA {
	SYSTEM_DATA system{
	system.PowerBarHeight = 32,
	system.OffsetPx = 30.0f,
	system.OffsetPy = 30.0f,
	system.Gravity = 0.205f,
	system.RADIAN = 3.141592f / 180
	};
	PLAYER_DATA player{
	player.UpperArmsOffsetPx = 45,
	player.UpperArmsOffsetPy = 5,
	player.DownerArmsOffsetPx = 35,
	player.DownerArmsOffsetPy = 5,
	player.PlayerOffsetPy = 7.0f,
	player.MaxPower = 17.0f,
	player.PlayersNum = 1,
	player.PlayerAllowedDistance = 70.0f,
	player.PlayerId = 'p'
	};
	BALL_DATA ball{
	ball.BallsNum = 1,
	ball.InitialPx = -50.0f,
	ball.InitialPy = -2000.0f,
	ball.NotMoveCnt = 180,
	ball.ReCollisionCnt = 5,
	ball.BallId = 'b'
	};
	DEFF_DATA deffender{
	deffender.DeffenderId = 'd'
	};
	SPRING_DATA spring{
	spring.SpringId = 's'
	};
	WIND_DATA wind{
	wind.Windturn = 0.5f,
	wind.WindPercent = 10,
	wind.WCPInterval = 300,
	wind.WindId = 'w'
	};
	GOAL_DATA goal{
	goal.GoalId = 'g'
	};
	STICKEY_DATA stickey{
	stickey.StickeyId = 'n'
	};
	JET_DATA jet{
	jet.JetId = 'j'
	};
	ONEUP_DATA one{
	one.OneupId = 'o'
	};
	COIN_DATA coin{
	coin.CoinId = 'c'
	};
	IMAGEDATA Backs[TYPE_MAX_BACKS];
	//Backs[Title];
	//Backs[TitleLogo];
	//Backs[Back];
	//Backs[Clear]{
	//	Backs[Clear].Px = 790,
	//	Backs[Clear].Py = 390
	//};
	//Backs[Failed]{
	//	Backs[Failed].Px = 790,
	//	Backs[Failed].Py = 390
	//};
	//Backs[GameOver]{
	//	Backs[GameOver].Px = 790,
	//	Backs[GameOver].Py = 390
	//};
	//Backs[Dungeon];
	//Backs[Ending];
	//Backs[Feed];
};

class CONTAINER {
public:
	const char* WindowTitle = "StreetShoot!";
	const int WindowWidth = 1920;
	const int WindowHeight = 1080;
	int Handle[TYPE_MAX];

	//MAP
	const char* testmap = "data/testmap.txt";
	const char* stage1 = "data/stage1.txt";
	const char* stage2 = "data/stage2.txt";
	const char* stage3 = "data/stage3.txt";
	const char* stage4 = "data/stage4.txt";
	const char* stage5 = "data/stage5.txt";
	const char* stage51 = "data/stage51.txt";
	const char* stage52 = "data/stage52.txt";
	const char* stage53 = "data/stage53.txt";
	const char* stage54 = "data/stage54.txt";
	const char* stage55 = "data/stage55.txt";
	int blockImg = 0;
	const int chipSize = 60;

	//arrow
	int arrowImg = 0;

	//SE
	int titleBgm = 0;
	int playBgm = 0;
	int throwSe = 0;
	int boundSe = 0;
	int goalSe = 0;
	int coinSe = 0;
	int oneupSe = 0;
	int springSe = 0;
	int clearBgm = 0;
	int failedBgm = 0;
	int gameoverSe = 0;
	int catchSe = 0;

	ALL_DATA ad;

private:
	CONTAINER() {
		//initialize(ad.system.WindowTitle, ad.system.WindowWidth, ad.system.WindowHeight, FULLSCREEN);
		//initialize("Street_Shoot!", 1920, 1080, FULLSCREEN);
		initialize(WindowTitle, WindowWidth, WindowHeight, FULLSCREEN);
		FILE* fp = 0;
		fopen_s(&fp, "data/SYSTEM_DATA.bin", "rb");
		fread(&ad, sizeof(ALL_DATA), 1, fp);
		fclose(fp);


		//LOADIMAGE	
		//ギミックとキャラクター
		Handle[PBody] = loadImage("player2.png");
		Handle[PLArm] = loadImage("player1.png");
		Handle[PRArm] = loadImage("player4.png");
		Handle[Ball] = loadImage("basketball.png");
		Handle[Deffender] = loadImage("difennda.png");
		Handle[Spring] = loadImage("bane omake.png");
		Handle[Wind] = loadImage("kaze.png");
		Handle[Goal] = loadImage("basketgoal.png");
		Handle[Coin] = loadImage("medal.png");
		Handle[Stickey] = loadImage("adhesive.png");
		Handle[Jet] = loadImage("jetpack.png");
		Handle[Oneup] = loadImage("basketball.png");
		blockImg = loadImage("tetu.png");
		//ad.player.BodyImg = loadImageFromRes(PLAYER);
		//ad.player.LArmImg = loadImageFromRes(LARM);
		//ad.player.RArmImg = loadImageFromRes(RARM);
		//ad.ball.BallImg = loadImageFromRes(BALL);
		//ad.deffender.DeffenderImg = loadImageFromRes(DEFFENDER);
		//ad.spring.SpringImg = loadImageFromRes(SPRING);
		//ad.wind.WindImg = loadImageFromRes(WIND);
		//ad.goal.GoalImg = loadImageFromRes(GOAL);
		//ad.coin.CoinImg = loadImageFromRes(MEDAL);
		//ad.stickey.StickeyImg = loadImageFromRes(STICKEY);
		//ad.jet.JetImg = loadImageFromRes(JET);
		//ad.one.OneupImg = loadImageFromRes(ONEUP);
		//blockImg = loadImageFromRes(BLOCK);

		//背景とロゴ
		Handle[Title] = loadImage("title.png");
		Handle[TitleLogo] = loadImage("Title_Logo.png");
		Handle[Back] = loadImage("backGround1.png");
		Handle[Clear] = loadImage("Stage_Clear.png");
		Handle[Failed]= loadImage("failed.png");
		Handle[GameOver]= loadImage("GAME_OVER.png");
		Handle[Dungeon] = loadImage("dungeon1.png");
		Handle[Ending]= loadImage("ending.png");
		//ad.title.Img = loadImageFromRes(TITLE);
		//ad.titlelogo.Img = loadImageFromRes(TITLE_LOGO);
		//ad.back.Img = loadImageFromRes(BACK);
		//ad.dungeon.Img = loadImageFromRes(DUNGEON);
		//ad.clear.Img = loadImageFromRes(CLEAR);
		//ad.failed.Img = loadImageFromRes(FAILED);
		//ad.gameover.Img = loadImageFromRes(GAMEOVER);
		//ad.ending.Img = loadImageFromRes("ENDING);


		//フェード
		Handle[Feed] = loadImage("effect_feed.png");
		//ad.feed.Img = loadImageFromRes(FEED);

		//システム系
		Handle[PowerBar] = loadImage("powerbar.png");
		arrowImg = loadImage("ya.png");
		Handle[PowerGauge] = loadImage("Gauge_Bar_1.png");
		//ad.system.PowerBarImg = loadImageFromRes(BAR);
		//arrowImg = loadImageFromRes(ARROW);
		//ad.system.PowerGaugeImg = loadImageFromRes(GAUGE);

		//LOADSOUND
		titleBgm 	 = loadSound("midnightmoon.wav");
		playBgm	 = loadSound("garasugoshinoyutsu.wav");
		throwSe	 = loadSound("throw.wav");
		boundSe	 = loadSound("キャッチ01.wav");
		goalSe	 = loadSound("ゴールイン01.wav");
		springSe = loadSound("バネ.wav");
		coinSe = loadSound("ピコ！.wav");
		oneupSe = loadSound("ピコ！.wav");
		clearBgm	 = loadSound("拍手.wav");
		failedBgm	 = loadSound("geshinoyukoku.wav");
		gameoverSe = loadSound("shizumiyukutaiyou.wav");
		catchSe = loadSound("拍手.wav");

	}
	friend class CONTAINER_MANAGER;
};