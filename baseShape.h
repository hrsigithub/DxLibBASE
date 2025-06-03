#pragma once

#include "DxLibWrapper.h"

namespace DxLib {

    class baseShape :
        public DxLibWrapper
    {
    public:
        void ClearDrawScreenWithWait();
        void AllDraw();

        enum class WaveType { Sin, Cos };
        enum class AmplitudeType { Vertical, Horizontal };
        enum class CircleType { Circle, Whirlpool };
        enum class KochType { Curve, Snowflake };
        enum class HilbertCurveMoveType { Right, Up, Down, Left };
        enum class HilbertCurveType { LeftDownRight, UpRightDown, RightUpLeft, DownLeftUp };

    protected:

        struct Pos {
            float length;
            float x, y;
        };

        struct {
            int r, g, b;
        } Color_tb[6] = {
            {0,  128, 255 },
            {0,   64, 255 },
            {128, 64, 255 },
            {128,  0, 255 },
            {64,   0, 255 },
            {0,    0, 255 },
        };

        void DrawPixel();
        void DrawLine();
        void DrawBox();
        void DrawCircle();
        void DrawTriangle();
    };


}
