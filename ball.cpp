#include <DxLib.h>
#include "ball.h"

namespace DxLib {

    ball::ball() {}

    void ball::MainGameLoop(Params& params) {

        params.x += 0.002f;

        DrawCircleAA(params.x, params.y, Radius, 32, COLOR_YELLOW, TRUE);

        FpsDraw(&fpsTimer);
    }
}
