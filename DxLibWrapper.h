// DxLibWrapper.h
#pragma once



class DxLibWrapper {


#define COLOR_RED       GetColor(255, 0, 0)
#define COLOR_YELLOW	GetColor(255, 255, 0)
#define COLOR_PINK      GetColor(255, 0, 255)
#define COLOR_CYAN      GetColor(0, 255, 255)
#define COLOR_WHITE     GetColor(255, 255, 255)

public:
    DxLibWrapper();
    bool initialize();
    void DrawPixel();
    void DrawLine();
    void DrawBox();
    void DrawCircle();
    void DrawTriangle();
};
