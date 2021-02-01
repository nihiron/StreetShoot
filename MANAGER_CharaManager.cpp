#include "MANAGER_CharaManager.h"
CHARA_MANAGER* MANAGER_CharaManager::CharaManager = 0;

CHARA_MANAGER* MANAGER_CharaManager::getInstance() {
	if (!CharaManager) {
		CharaManager = new CHARA_MANAGER;
	}
	return CharaManager;
}

CHARA_MANAGER* MANAGER_CharaManager::destroy() {
	delete CharaManager;
	CharaManager = 0;
	return CharaManager;
}