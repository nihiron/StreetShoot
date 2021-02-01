#pragma once
#include "framework.h"
#include "graphic.h"
#include "COLOR.h"
#include "debugStr.h"
#include "sound.h"
#include <stdio.h>
#include "CONTAINER_MANAGER.h"

struct IMAGEDATA {
	int Img = 0;
	int Px = 0;
	int Py = 0;
};

//Total 49
struct SYSTEM_DATA {
	char* WindowTitle;
	int WindowWidth;
	int WindowHeight;
	int PowerBarImg;
	int PowerGaugeImg;
	int PowerBarHeight;
	float OffsetPx;
	float OffsetPy;
	float Gravity;
	float RADIAN;
};
struct PLAYER_DATA {
	int BodyImg;
	int LArmImg;
	int RArmImg;
	int PowergaugeImg;
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
	int BallImg;
	int BallsNum;
	float InitialPx;
	float InitialPy;
	int NotMoveCnt;
	int ReCollisionCnt;
	char BallId;
};
struct DEFF_DATA {
	int DeffenderImg;
	char DeffenderId;
};
struct SPRING_DATA {
	int SpringImg;
	char SpringId;
};
struct WIND_DATA {
	int WindImg;
	float Windturn;
	int WindPercent;
	int WCPInterval;
	char WindId;
};
struct GOAL_DATA {
	int GoalImg;
	char GoalId;
};
struct STICKEY_DATA {
	int StickeyImg;
	char StickeyId;
};
struct JET_DATA {
	int JetImg;
	char JetId;
};
struct ONEUP_DATA {
	int OneupImg;
	char OneupId;
};
struct COIN_DATA {
	int CoinImg;
	char CoinId;
};


















struct ALL_DATA {
	SYSTEM_DATA system;
	PLAYER_DATA player;
	BALL_DATA ball;
	DEFF_DATA deffender;
	SPRING_DATA spring;
	WIND_DATA wind;
	GOAL_DATA goal;
	STICKEY_DATA stickey;
	JET_DATA jet;
	ONEUP_DATA one;
	COIN_DATA coin;
	IMAGEDATA title;
	IMAGEDATA titlelogo;
	IMAGEDATA back;
	IMAGEDATA clear;
	IMAGEDATA failed;
	IMAGEDATA gameover;
	IMAGEDATA dungeon;
	IMAGEDATA ending;
	IMAGEDATA feed;
};

////ここまでのデータを統合したもの

//struct ALL_DATA {
//	SYSTEM_DATA system{
//	system.WindowTitle = "Street_Shoot!",
//	system.WindowWidth = 1920,
//	system.WindowHeight = 1080,
//	system.PowerBarImg = 0,
//	system.PowerGaugeImg = 0,
//	system.PowerBarHeight = 32,
//	system.OffsetPx = 30.0f,
//	system.OffsetPy = 30.0f,
//	system.Gravity = 0.205f,
//	system.RADIAN = 3.141592f / 180
//	};
//	PLAYER_DATA player{
//	player.BodyImg = 0,
//	player.LArmImg = 0,
//	player.RArmImg = 0,
//	player.PowergaugeImg = 0,
//	player.UpperArmsOffsetPx = 45,
//	player.UpperArmsOffsetPy = 5,
//	player.DownerArmsOffsetPx = 35,
//	player.DownerArmsOffsetPy = 5,
//	player.PlayerOffsetPy = 7.0f,
//	player.MaxPower = 17.0f,
//	player.PlayersNum = 1,
//	player.PlayerAllowedDistance = 70.0f,
//	player.PlayerId = 'p'
//	};
//	BALL_DATA ball{
//	ball.BallImg = 0,
//	ball.BallsNum = 1,
//	ball.InitialPx = -50.0f,
//	ball.InitialPy = -2000.0f,
//	ball.NotMoveCnt = 180,
//	ball.ReCollisionCnt = 5,
//	ball.BallId = 'b'
//	};
//	DEFF_DATA deffender{
//	deffender.DeffenderImg = 0,
//	deffender.DeffenderId = 'd'
//	};
//	SPRING_DATA spring{
//	spring.SpringImg = 0,
//	spring.SpringId = 's'
//	};
//	WIND_DATA wind{
//	wind.WindImg = 0,
//	wind.Windturn = 0.5f,
//	wind.WindPercent = 10,
//	wind.WCPInterval = 300,
//	wind.WindId = 'w'
//	};
//	GOAL_DATA goal{
//	goal.GoalImg = 0,
//	goal.GoalId = 'g'
//	};
//	STICKEY_DATA stickey{
//	stickey.StickeyImg = 0,
//	stickey.StickeyId = 'n'
//	};
//	JET_DATA jet{
//	jet.JetImg = 0,
//	jet.JetId = 'j'
//	};
//	ONEUP_DATA one{
//	one.OneupImg = 0,
//	one.OneupId = 'o'
//	};
//	COIN_DATA coin{
//	coin.CoinImg = 0,
//	coin.CoinId = 'c'
//	};
//	IMAGEDATA title;
//	IMAGEDATA titlelogo;
//	IMAGEDATA back;
//	IMAGEDATA clear{
//		clear.Img = 0,
//		clear.Px = system.WindowWidth / 2 - 200,
//		clear.Py = system.WindowHeight / 2 - 150
//	};
//	IMAGEDATA failed{
//		failed.Img = 0,
//		failed.Px = system.WindowWidth / 2 - 200,
//		failed.Py = system.WindowHeight / 2 - 150
//	};
//	IMAGEDATA gameover{
//		gameover.Img = 0,
//		gameover.Px = system.WindowWidth / 2 - 200,
//		gameover.Py = system.WindowHeight / 2 - 150
//	};
//	IMAGEDATA dungeon;
//	IMAGEDATA ending;
//	IMAGEDATA feed;
//};

class CONTAINER {
public:
	////title
	//IMAGEDATA title;
	////titlelogo
	//IMAGEDATA titlelogo;
	////backGROUND
	//IMAGEDATA back;
	////clear
	//IMAGEDATA clear{
	//	clear.Img = 0,
	//	clear.Px = 1920 / 2 - 200,
	//	clear.Py = 1080 / 2 - 150
	//};
	////failed
	//IMAGEDATA failed{
	//	failed.Img,
	//	failed.Px = 1920 / 2 - 200,
	//	failed.Py = 1080 / 2 - 150
	//};
	////gameover
	//IMAGEDATA gameover{
	//	gameover.Img,
	//	gameover.Px = 1920 / 2 - 200,
	//	gameover.Py = 1080 / 2 - 150
	//};
	////clear
	//IMAGEDATA clear{
	//	clear.Img = 0,
	//	clear.Px = ad.system.WindowWidth / 2 - 200,
	//	clear.Py = ad.system.WindowHeight / 2 - 150
	//};
	////failed
	//IMAGEDATA failed{
	//	failed.Img,
	//	failed.Px = ad.system.WindowWidth / 2 - 200,
	//	failed.Py = ad.system.WindowHeight / 2 - 150
	//};
	////gameover
	//IMAGEDATA gameover{
	//	gameover.Img,
	//	gameover.Px = ad.system.WindowWidth / 2 - 200,
	//	gameover.Py = ad.system.WindowHeight / 2 - 150
	//};
	////dungeon
	//IMAGEDATA dungeon;
	////ending
	//IMAGEDATA ending;
	////const int endingframe = 10800;
	////feed
	//IMAGEDATA feed;

	////SYSTEM--------------------------------------------------------
	//const char* WindowTitle = "Street_Shoot";
	//const int WindowWidth = 1920;
	//const int WindowHeight = 1080;
	//
	//int PowerbarImg = 0;
	//const int PowerBarheight = 32;
	//const float OffsetPx = 30.0f;
	//const float OffsetPy = 30.0f;
	//const float RADIAN = 3.141592f / 180;
	//
	////PLAYER
	//int BodyImg = 0;
	//int LArmImg = 0;
	//int RArmImg = 0;
	//int PowerGaugeImg = 0;
	//float UpperArmsoffsetPx = 45;
	//float UpperArmsoffsetPy = 5;
	//
	//float DownerArmsoffsetPx = 35;
	//float DownerArmsoffsetPy = 5;
	//
	//const float PlayeroffsetPy = 7;
	//const float MaxPower = 17.0f;
	//
	//const int PlayersNum = 1;
	//
	//const char PlayerId = 'p';
	//const float Playeralloweddistance = 70.0f;
	//
	////BALL
	//int BallImg = 0;
	//const int BallsNum = 1;
	//const float InitialPx = -50;
	//const float InitialPy = -2000;
	//const float Gravity = 0.205f;
	//const int NotMoveCnt = 180;
	//const int ReCollisionCnt = 5;//再判定するまでのフレーム数
	//
	//const char BallId = 'b';
	//
	////DEFENDER
	//int DeffenderImg = 0;
	//const char DeffenderId = 'd';
	//
	////SPRING
	//int SpringImg = 0;
	//const char SpringId = 's';
	//
	////WIND
	//int WindImg = 0;
	//const float Windturn = 0.5f;
	//const int Windpercent = 10;
	////Wind Change Percent Interval 切り替え判定までのフレーム
	//const int WCPInterval = 300;
	//const char WindId = 'w';
	//
	////GOAL
	//int GoalImg = 0;
	//const char GoalId = 'g';
	//
	////STICKY_BLOCK
	//int StickeyImg = 0;
	//const char StickeyId = 'n';
	//
	////JET_PACK
	//int JetImg = 0;
	//const char JetId = 'j';
	//
	////1UP
	//int OneupImg = 0;
	//const char OneupId = 'o';
	//
	////COIN
	//int CoinImg = 0;
	//const char CoinId = 'c';

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
		initialize("Street_Shoot!", 1920, 1080, FULLSCREEN);
		FILE* fp = 0;
		fopen_s(&fp, "data/SYSTEM_DATA.bin", "rb");
		fread(&ad, sizeof(ALL_DATA), 1, fp);
		fclose(fp);

		//LOADIMAGE	
		//ギミックとキャラクター
		ad.player.BodyImg = loadImage("player2.png");
		ad.player.LArmImg = loadImage("player1.png");
		ad.player.RArmImg = loadImage("player4.png");
		ad.ball.BallImg = loadImage("basketball.png");
		ad.deffender.DeffenderImg = loadImage("difennda.png");
		ad.spring.SpringImg = loadImage("bane omake.png");
		ad.wind.WindImg = loadImage("kaze.png");
		ad.goal.GoalImg = loadImage("basketgoal.png");
		ad.coin.CoinImg = loadImage("medal.png");
		ad.stickey.StickeyImg = loadImage("adhesive.png");
		ad.jet.JetImg = loadImage("jetpack.png");
		ad.one.OneupImg = loadImage("basketball.png");

		blockImg = loadImage("tetu.png");

		//背景とロゴ
		ad.title.Img = loadImage("title.png");
		ad.titlelogo.Img = loadImage("Title_Logo.png");
		ad.back.Img = loadImage("backGround1.png");
		ad.dungeon.Img = loadImage("dungeon1.png");
		ad.clear.Img = loadImage("Stage_Clear.png");
		ad.failed.Img = loadImage("failed.png");
		ad.gameover.Img = loadImage("GAME_OVER.png");
		ad.ending.Img = loadImage("ending.png");

		//フェード
		ad.feed.Img = loadImage("effect_feed.png");
		//ad.title.Img = loadImage("title.png");
		//ad.titlelogo.Img = loadImage("Title_Logo.png");
		//ad.back.Img = loadImage("backGround1.png");
		//ad.dungeon.Img = loadImage("dungeon1.png");
		//ad.clear.Img = loadImage("Stage_Clear.png");
		//ad.failed.Img = loadImage("failed.png");
		//ad.gameover.Img = loadImage("GAME_OVER.png");
		//ad.ending.Img = loadImage("ending.png");

		////フェード
		//ad.feed.Img = loadImage("effect_feed.png");

		//システム系
		ad.system.PowerBarImg = loadImage("powerbar.png");
		arrowImg = loadImage("ya.png");
		ad.system.PowerGaugeImg = loadImage("Gauge_Bar_1.png");

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
//struct ALL_DATA {
//	SYSTEM_DATA system{
//	system.WindowTitle = 0,
//	system.WindowWidth = 0,
//	system.WindowHeight = 0,
//	system.PowerBarImg = 0,
//	system.PowerGaugeImg = 0,
//	system.PowerBarHeight = 0,
//	system.OffsetPx = 0,
//	system.OffsetPy = 0,
//	system.Gravity = 0,
//	system.RADIAN = 0
//	};
//	PLAYER_DATA player{
//	player.BodyImg = 0,
//	player.LArmImg = 0,
//	player.RArmImg = 0,
//	player.PowergaugeImg = 0,
//	player.UpperArmsOffsetPx = 0,
//	player.UpperArmsOffsetPy = 0,
//	player.DownerArmsOffsetPx = 0,
//	player.DownerArmsOffsetPy = 0,
//	player.PlayerOffsetPy = 0,
//	player.MaxPower = 0,
//	player.PlayersNum = 0,
//	player.PlayerAllowedDistance = 0,
//	player.PlayerId = 0
//	};
//	BALL_DATA ball{
//	ball.BallImg = 0,
//	ball.BallsNum = 0,
//	ball.InitialPx = 0,
//	ball.InitialPy = 0,
//	ball.NotMoveCnt = 0,
//	ball.ReCollisionCnt = 0,
//	ball.BallId = 0				 
//	};
//	DEFF_DATA deffender{
//	deffender.DeffenderImg = 0,
//	deffender.DeffenderId = 0
//	};
//	SPRING_DATA spring{
//	spring.SpringImg = 0,
//	spring.SpringId = 0
//	};
//	WIND_DATA wind{
//	wind.WindImg = 0,
//	wind.Windturn = 0,
//	wind.WindPercent = 0,
//	wind.WCPInterval = 0,
//	wind.WindId = 0
//	};
//	GOAL_DATA goal{
//	goal.GoalImg = 0,
//	goal.GoalId = 0
//	};
//	STICKEY_DATA stickey{
//	stickey.StickeyImg = 0,
//	stickey.StickeyId = 0
//	};
//	JET_DATA jet{
//	jet.JetImg = 0,
//	jet.JetId = 0
//	};
//	ONEUP_DATA one{
//	one.OneupImg = 0,
//	one.OneupId = 0
//	};
//	COIN_DATA coin{
//	coin.CoinImg = 0,
//	coin.CoinId = 0
//	};
//	IMAGEDATA title{ 0,0,0 };
//	IMAGEDATA titlelogo{ 0,0,0 };
//	IMAGEDATA back{ 0,0,0 };
//	IMAGEDATA clear{ 0,0,0 };
//
//
//	IMAGEDATA failed{ 0,0,0 };
//
//
//	IMAGEDATA gameover{ 0,0,0 };
//
//
//	IMAGEDATA dungeon{ 0,0,0 };
//	IMAGEDATA ending{ 0,0,0 };
//	IMAGEDATA feed{ 0,0,0 };
//};
