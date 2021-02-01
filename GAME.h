#include "CONTAINER_MANAGER.h"
#include "MANAGER_CharaManager.h"
#include "IMG.h"
#include "CHARA.h"
#include "MAP.h"

class GAME {
public:
	GAME();
	~GAME();
	void proc();
	ALL_DATA  ad;

private:
	void saveData();
	void loadData();
	void title();
	void select();
	void play();
	void clear();
	void failed();
	void gameover();
	void ending();
	void infomation();
	void mapChange(int flag);

	IMG* img;

	enum GAME_STATE { GAME_STATE_TITLE,
		GAME_STATE_PLAY,
		GAME_STATE_CLEAR,
		GAME_STATE_FAILED,
		GAME_STATE_GAMEOVER,
		GAME_STATE_END,
		GAME_STATE_SELECT,
		GAME_STATE_INFO
	};
	GAME_STATE State = GAME_STATE_TITLE;
	int stageno = 0;
	int Isarcadeflag = 0;//���K���ǂ����B1���K�B0�{�����
	int zanki = 0;
	int wff = 0;//waiting for frames �ҋ@�t���[����
	int command = 0;//hidden command �^�C�g����ʂ� �uSABUROU�v �ƃQ�[�����[�h�ύX
	int stayFlag = 0;//�i�߂Ȃ��悤�ɂ���t���O�B0�i�߂Ȃ��B1�i�߂�

	int playTime = 0;//�v���C�J�n����N���A����܂ł̃^�C��
	
	int TitleBgm = 0;
	int PlayBgm = 0;
	int ClearBgm = 0;
	int GameoverBgm = 0;
	int FailedBgm = 0;

	int PlayerCouldStage = 0;

	//struct DATA {
	//	unsigned int MinPlayTime1 = 999999999;
	//	unsigned int MinPlayTime2 = 999999999;
	//	unsigned int MinPlayTime3 = 999999999;
	//	unsigned int MinPlayTime4 = 999999999;
	//	unsigned int MinPlayTime5 = 999999999;

	//	unsigned int MinPlayTimeS1 = 999999999;
	//	unsigned int MinPlayTimeS2 = 999999999;
	//	unsigned int MinPlayTimeS3 = 999999999;
	//	unsigned int MinPlayTimeS4 = 999999999;
	//	unsigned int MinPlayTimeS5 = 999999999;

	//	unsigned int TotalFailedNum = 0;
	//	unsigned int TotalGameoverNum = 0;
	//	unsigned int PlayerCouldStage = 0;//�v���C���[�����ǂ蒅����MAX�X�e�[�W		
	//};


	//DATA data;

	//�V���O���g�������̂��߂ɒǉ���������
	//MAP Map = MAP::getInstance();
};
