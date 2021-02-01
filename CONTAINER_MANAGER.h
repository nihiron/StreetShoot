#pragma once
#include "CONTAINER.h"

class CONTAINER_MANAGER {
public:
	static CONTAINER* getInstance();
	static CONTAINER* destroy();
	static void createInstance();
	//ファイルがない場合は作って読み込む。ある場合はそのまま読み込む
	static void createSystemData();
	//設定ファイルを読み込む
	static void readSystemData();

private:
	CONTAINER_MANAGER();
	static CONTAINER* C;
};
	////設定ファイルを読み込む
	//static void readSystemData();