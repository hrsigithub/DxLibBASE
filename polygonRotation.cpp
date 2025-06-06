#define _USE_MATH_DEFINES

#include <math.h>
#include <DxLib.h>

#include "polygonRotation.h"

using namespace DxLib;

namespace DxBall {

    polygonRotation::polygonRotation() {
    }

    void polygonRotation::MainGameLoop() {

        float deltaTime = getDeltaTime(&deltaTimer);

        angle += speedAngle * deltaTime;

        if (angle >= 360.0f)    angle -= 360.0f;

        
        intervalTime -= deltaTime;
        if (intervalTime <= 0.0f) {
            intervalTime = INTERVAL;

            n += dn;
            if (n >= POLYGON_MAX || n <= POLYGON_MIN)
                dn *= -1;
        }
        
        
        ClearDrawScreen();

        for (int i = 0; i < n; i++)
        {
            float dx = (float)(RADIUS * cos(M_PI * (angle + i * 360.0 / n) / 180.0));
            float dy = (float)(RADIUS * sin(M_PI * (angle + i * 360.0 / n) / 180.0));

            float ex = (float)(RADIUS * cos(M_PI * (angle + (i + 1) * 360.0 / n) / 180.0));
            float ey = (float)(RADIUS * sin(M_PI * (angle + (i + 1) * 360.0 / n) / 180.0));

            int color = 255 - i * (255 - 64) / n;

            DrawTriangleAA(x - 40, y - 40, x + dx, y + dy, x + ex, y + ey, GetColor(color, color, 0), TRUE);
        }

        FpsDraw(&fpsTimer);

        ScreenFlip();
    }
}
