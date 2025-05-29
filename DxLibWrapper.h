// DxLibWrapper.h
#pragma once



class DxLibWrapper {

#define COLOR_RED       GetColor(255, 0, 0)
#define COLOR_BLUE      GetColor(0, 0, 255)
#define COLOR_YELLOW	GetColor(255, 255, 0)
#define COLOR_PINK      GetColor(255, 0, 255)
#define COLOR_CYAN      GetColor(0, 255, 255)
#define COLOR_WHITE     GetColor(255, 255, 255)
#define COLOR_GRAY      GetColor(128, 128, 128)
#define COLOR_GREEN     GetColor(0, 255, 0)


public:
    enum class Curve { sin, cos };

    DxLibWrapper();

    bool initialize();

    void ClearDrawScreenWithWait();
    void AllDraw();

    void DrawPixel();
    void DrawLine();
    void DrawBox();
    void DrawCircle();
    void DrawTriangle();


    void sin_cosCurve(Curve);
    void circleCurve();


};
