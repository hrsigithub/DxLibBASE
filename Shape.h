#pragma once

#include "DxLibWrapper.h"
#include "baseShape.h"

namespace DxShape {

    class Shape : public baseShape
    {
    public:

        void sin_cosCurve(WaveType = WaveType::Cos);
        void vertical_horizontal_amplitude(AmplitudeType, float angle = 4.0f);
        void circleCurve(CircleType = CircleType::Circle);

        // シェルピンスキー・ギャスケット
        void TriangleGasket(int n = 5);

        // コッホ曲線
        void KochCurveOrSnowflake(KochType = KochType::Curve, int n = 5);

        // ヒルベルト曲線
        void HilbertCurve(int n = 7);

    private:

        void TriangleGasket(int n, const Pos& a, const Pos& b, const Pos& c);

        void KochCurve(int n, const Pos& a, const Pos& b);

        // ヒルベルト曲線
        void HilbertCurveMove(HilbertCurveType, int n, Pos* p);
        void HilbertCurveMove(HilbertCurveMoveType, Pos* p);
        void HilbertCurveDrawLineAA(float, float, float, float);
    };
}
