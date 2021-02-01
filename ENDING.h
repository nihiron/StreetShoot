#include "IMG.h"
#include "CONTAINER_MANAGER.h"

class ENDING : public IMG {
public:
	ENDING() {
			CONTAINER* C = CONTAINER_MANAGER::getInstance();
		Img = C->endingImg;
		Px = C->endingPx;
		Py = C->endingPy;
	}
private:
};