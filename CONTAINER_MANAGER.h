#pragma once
#include "CONTAINER.h"

class CONTAINER_MANAGER {
public:
	static CONTAINER* getInstance();
	static CONTAINER* destroy();
	static void createInstance();
	//�t�@�C�����Ȃ��ꍇ�͍���ēǂݍ��ށB����ꍇ�͂��̂܂ܓǂݍ���
	static void createSystemData();
	//�ݒ�t�@�C����ǂݍ���
	static void readSystemData();

private:
	CONTAINER_MANAGER();
	static CONTAINER* C;
};
	////�ݒ�t�@�C����ǂݍ���
	//static void readSystemData();