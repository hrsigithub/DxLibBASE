#include <DxLib.h>

#include "baseGame.h"

namespace DxLib {

	baseGame::baseGame() {
		//fpsTimer = GetNowHiPerformanceCount();
		//params = {};
	}

	void baseGame::FpsDraw(LONGLONG* p) {

		static int Fps = 0, FpsCnt = 0;
		auto now = GetNowHiPerformanceCount();

		FpsCnt++;
		
		if (now - *p > 1000000) { // 1秒後
			Fps = FpsCnt;
			FpsCnt = 0;
			*p = now;
		}

		DrawFormatString(0, 0, COLOR_WHITE, "FPS: %d", Fps);
	}

	void baseGame::GameLoop() {

		params = { 0.0f, 240.0f };

		while (!ProcessMessage()) {

			ClearDrawScreen();
	
			// オーバーライドする。
			MainGameLoop(params);

			// ScreenFlip();
		}
	}
}
