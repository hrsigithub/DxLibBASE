#include <DxLib.h>
#include "ball.h"

namespace DxLib {

    ball::ball() {
    }

    void ball::MyInitialize() {

        SetMainWindowText("ballだべ。");

        // 垂直同期なし
        //DxLibWrapper::WaitVSyncFlag = TRUE;

        // 非アクティブでも動作停止
        //DxLibWrapper::AlwaysRunFlag = FALSE;
    }

    void ball::BeforeGameLoop() {
        x = RADIUS;
        y = 240;
        speed = SPEED;

        // 裏バッファへ
        SetDrawScreen(DX_SCREEN_BACK);
    }

    void ball::MainGameLoop() {
        float deltaTime = getDeltaTime(&deltaTimer);

        x += speed * deltaTime;

        if (x + RADIUS >= 640.0f) {
            x = 640.0f - RADIUS;
            speed = -SPEED;
        }
        else if (x - RADIUS < 0.0f) {
            x = RADIUS;
            speed = SPEED;
        }

        DrawCircleAA(x, y, RADIUS, 32, COLOR_YELLOW, TRUE);
        FpsDraw(&fpsTimer);

        ScreenFlip();
    }
}
