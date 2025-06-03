#include <DxLib.h>
#include "ball.h"

namespace DxLib {

    ball::ball() {}

    void ball::BeforeGameLoop() {
        x = Radius;
        y = 240;
        speed = SPEED;

        // 裏バッファへ
        SetDrawScreen(DX_SCREEN_BACK);
    }

    void ball::MainGameLoop() {
        float deltaTime = getDeltaTime(&deltaTimer);

        x += speed * deltaTime;

        if (x + Radius >= 640.0f) {
            x = 640.0f - Radius;
            speed = -SPEED;
        }
        else if (x - Radius < 0.0f) {
            x = Radius;
            speed = SPEED;
        }

        DrawCircleAA(x, y, Radius, 32, COLOR_YELLOW, TRUE);
        FpsDraw(&fpsTimer);

        ScreenFlip();
    }
}
