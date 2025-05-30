// DxLibWrapper.h
#pragma once

namespace DxLib {

#define COLOR_RED       GetColor(255, 0, 0)
#define COLOR_BLUE      GetColor(0, 0, 255)
#define COLOR_YELLOW	GetColor(255, 255, 0)
#define COLOR_PINK      GetColor(255, 0, 255)
#define COLOR_CYAN      GetColor(0, 255, 255)
#define COLOR_WHITE     GetColor(255, 255, 255)
#define COLOR_GRAY      GetColor(128, 128, 128)
#define COLOR_GREEN     GetColor(0, 255, 0)

    class DxLibWrapper {

    public:
        enum class WaveType { Sin, Cos };
        enum class AmplitudeType { Vertical, Horizontal };
        enum class CircleType { Circle, Whirlpool };

        DxLibWrapper();

        bool initialize();

        void ClearDrawScreenWithWait();
        void AllDraw();

        void DrawPixel();
        void DrawLine();
        void DrawBox();
        void DrawCircle();
        void DrawTriangle();

        void sin_cosCurve(WaveType = WaveType::Cos);
        void vertical_horizontal_amplitude(AmplitudeType, float angle = 4.0f);  // ← デフォルト引数をここに書く
        void circleCurve(CircleType = CircleType::Circle);
    };
}