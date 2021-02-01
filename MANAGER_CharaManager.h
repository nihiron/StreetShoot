#pragma once
#include "CHARA_MANAGER.h"

class MANAGER_CharaManager {
public:

	static CHARA_MANAGER* getInstance();
	static CHARA_MANAGER* destroy();

private:
	MANAGER_CharaManager() {}
	static CHARA_MANAGER* CharaManager;
};