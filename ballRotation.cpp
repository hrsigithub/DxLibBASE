#define _USE_MATH_DEFINES

#include <math.h>
#include <DxLib.h>

#include "ballRotation.h"

namespace DxLib {

    ballRotation::ballRotation() {

    }

    void ballRotation::MainGameLoop() {

        float deltaTime = getDeltaTime(&deltaTimer);

        x += speed * deltaTime;

        if (x + RADIUS >= 640.0f) {
            x = 640.0f - RADIUS;
            speed = -SPEED;
            speedAngle = -SPEED_ANGLE;
        }
        else if (x - RADIUS < 0.0f) {
            x = RADIUS;
            speed = SPEED;
            speedAngle = SPEED_ANGLE;
        }

        angle += speedAngle * deltaTime;
        if (angle > 360.0f)
            angle -= 360.0f;

        ClearDrawScreen();

        DrawCircleAA(x, y, RADIUS, 32, COLOR_YELLOW, FALSE);

        const int n = 10;
        for (int i = 0; i < n; i++)
        {
            float dx = (float)(RADIUS * cos(M_PI * (angle + i * 180.0 / n) / 180.0));
            float dy = (float)(RADIUS * sin(M_PI * (angle + i * 180.0 / n) / 180.0));
            DrawLineAA(x + dx, y + dy, x - dx, y - dy, COLOR_YELLOW);
        }

        FpsDraw(&fpsTimer);

        ScreenFlip();

    }
}
