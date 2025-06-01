#include <DxLib.h>
#include "game1.h"

namespace DxLib {

    game1::game1() {}

    void game1::MainGameLoop(Params& params) {

        params.x += 0.002f;

        DrawCircleAA(params.x, params.y, Radius, 32, COLOR_YELLOW, TRUE);

        FpsDraw(&fpsTimer);
    }
}
