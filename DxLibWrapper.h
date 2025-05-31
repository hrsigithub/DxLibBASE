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
        enum class KochType { Curve, Snowflake };


        DxLibWrapper();

        bool initialize();

        void ClearDrawScreenWithWait();
        void AllDraw();

        void sin_cosCurve(WaveType = WaveType::Cos);
        void vertical_horizontal_amplitude(AmplitudeType, float angle = 4.0f);  // ← デフォルト引数をここに書く
        void circleCurve(CircleType = CircleType::Circle);

        // シェルピンスキー・ギャスケット
        void TriangleGasket(int n = 5);

        // コッホ曲線
        void KochCurveOrSnowflake(KochType = KochType::Curve, int n = 5);

    private:

        struct Pos {
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

        void TriangleGasket(int n, const Pos& a, const Pos& b, const Pos& c);

        void KochCurve(int n, const Pos& a, const Pos& b);
    };
}