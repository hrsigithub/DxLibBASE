#include <DxLib.h>
#include "mainGame.h"

namespace DxLib {

	void mainGame::MainGameLoop(Params& params) {
		
		params.x += 0.002f;

		DrawCircleAA(params.x, params.y, Radius, 32, COLOR_YELLOW, TRUE);
	}

}
