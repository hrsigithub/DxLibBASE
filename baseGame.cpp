#include <DxLib.h>

#include "baseGame.h"

namespace DxLib {

	baseGame::baseGame() {
		fpsTimer = GetNowHiPerformanceCount();
	}

	void baseGame::FpsDraw(LONGLONG* p) {
#ifdef _DEBUG

		static int Fps = 0, FpsCnt = 0;
		auto now = GetNowHiPerformanceCount();

		FpsCnt++;
		
		if (now - *p > 1000000) { // 1ïbå„
			Fps = FpsCnt;
			FpsCnt = 0;
			*p = now;
		}

		DrawFormatString(0, 0, COLOR_WHITE, "FPS: %d", Fps);
#endif
	}

	void baseGame::GameLoop() {

		BeforeGameLoop();

		while (!ProcessMessage()) {
	
			ClearDrawScreen();
			MainGameLoop();

			// ScreenFlip();
		}
	}
}
