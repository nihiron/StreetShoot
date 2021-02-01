#include "CONTAINER_MANAGER.h"
#include <stdio.h>
CONTAINER* CONTAINER_MANAGER::C = 0;

CONTAINER_MANAGER::CONTAINER_MANAGER() {
}

CONTAINER* CONTAINER_MANAGER::getInstance() {
	if (C == 0) {
		createInstance();
	}
	return C;
}

CONTAINER* CONTAINER_MANAGER::destroy() {
	delete C;
	C = 0;
	return C;
}

void CONTAINER_MANAGER::createInstance() {
	C = new CONTAINER;
}

void CONTAINER_MANAGER::createSystemData() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	FILE* fp = 0;
	//fopen_s(&fp, "data/systemdata.bin", "wb");
	fopen_s(&fp, "data/SYSTEM_DATA.bin", "wb");
	//fwrite(&C->ad, sizeof(ALL_DATA), 58, fp);
	fwrite(&C->ad, sizeof(ALL_DATA), 1, fp);
	fclose(fp);
}

void CONTAINER_MANAGER::readSystemData() {
	CONTAINER* C = CONTAINER_MANAGER::getInstance();
	FILE* fp = 0;
	fopen_s(&fp, "data/SYSTEM_DATA.bin", "rb");
	fread(&C->ad, sizeof(ALL_DATA), 1, fp);
	//fread(&C->ad, sizeof(ALL_DATA), 1, fp);
	fclose(fp);
}
//システムデータを読み込もうとした跡