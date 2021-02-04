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
		ad.title.Img = loadImage("title.png");
		ad.titlelogo.Img = loadImage("Title_Logo.png");
		ad.back.Img = loadImage("backGround1.png");
		ad.dungeon.Img = loadImage("dungeon1.png");
		ad.clear.Img = loadImage("Stage_Clear.png");
		ad.failed.Img = loadImage("failed.png");
		ad.gameover.Img = loadImage("GAME_OVER.png");
		ad.ending.Img = loadImage("ending.png");
		//ad.title.Img = loadImageFromRes(TITLE);
		//ad.titlelogo.Img = loadImageFromRes(TITLE_LOGO);
		//ad.back.Img = loadImageFromRes(BACK);
		//ad.dungeon.Img = loadImageFromRes(DUNGEON);
		//ad.clear.Img = loadImageFromRes(CLEAR);
		//ad.failed.Img = loadImageFromRes(FAILED);
		//ad.gameover.Img = loadImageFromRes(GAMEOVER);
		//ad.ending.Img = loadImageFromRes("ENDING);


		//フェード
		ad.feed.Img = loadImage("effect_feed.png");
		//ad.feed.Img = loadImageFromRes(FEED);

		//システム系
		ad.system.PowerBarImg = loadImage("powerbar.png");
		arrowImg = loadImage("ya.png");
		ad.system.PowerGaugeImg = loadImage("Gauge_Bar_1.png");
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