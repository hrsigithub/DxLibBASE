#include <DxLib.h>
#include <cmath>

#include "mouseDraw.h"

using namespace DxLib;

bool DxMouse::mouseDraw::isMouseLeftClick = false;

namespace DxMouse {

    mouseDraw::mouseDraw()
        : ColorTB{
            {255,   0,   0, {150, 30}},
            {0,   255,   0, {200, 30}},
            {0,     0, 255, {250, 30}},
            {255,   0, 255, {300, 30}},
            {255, 255,   0, {350, 30}},
            {0,   255, 255, {400, 30}}
        }
    {
        // 何も書かなくても初期化されている！
    }

    void mouseDraw::MyInitialize() {
        SetMainWindowText("mouseDrawだべ。");
    }

    void mouseDraw::BeforeGameLoop() {
        // 裏バッファへ
        SetDrawScreen(DX_SCREEN_BACK);
    }

    void mouseDraw::MainGameLoop() {

        DrawPalette(selectColor);
        SelectColor(selectColor);
        CheckDoubleClick();

        // マウス左押下？
        if (GetMouseInput() & MOUSE_INPUT_LEFT) {
            GetMousePoint(&now.x, &now.y);

            if (pre.x >= 0)
                DrawLine(pre.x, pre.y, now.x, now.y, GetColor(selectColor), 2);
            pre = now;
        }
        else
            pre.x = pre.y = -1;

        ScreenFlip();
    }

    void  mouseDraw::DrawPalette(int index) {
        
        DrawCircle(50, 30, RADIUS + 1, COLOR_WHITE, FALSE, 2);
        DrawCircle(50, 30, RADIUS, GetColor(index), TRUE);

        for (int i = 0; i < ColorTB.size(); ++i) {
            DrawCircle(ColorTB[i].POS.x, ColorTB[i].POS.y,
                RADIUS, GetColor(i), TRUE);
        }
    }

    void mouseDraw::SelectColor(int& index) {
        int button, clickX, clickY, logType;

        isMouseLeftClick = false;
        if (!GetMouseInputLog2(&button, &clickX, &clickY, &logType, TRUE)) {
            if ((button & MOUSE_INPUT_LEFT) && logType == MOUSE_INPUT_LOG_UP) {
                isMouseLeftClick = true;

                for (int i = 0; i < ColorTB.size(); ++i) {
                    // 三平方の定理
                    double d = pow((clickX - ColorTB[i].POS.x), 2) + pow((clickY - ColorTB[i].POS.y), 2);
                    if (d <= pow(RADIUS, 2)) {
                        // 円の中
                        index = i;
                        break;
                    }
                }
            }
        }
    }

    int mouseDraw::GetColor(int index) {
        return ::GetColor(ColorTB[index].R, ColorTB[index].G, ColorTB[index].B);
    }

    // ダブルクリックで画面クリア
    void mouseDraw::CheckDoubleClick() {

        // ダブルクリック間隔取得
        const int DOUBLE_CLICK_INTERVAL = GetDoubleClickTime();
        static int lastClickTime = 0;
        int now = GetNowCount();

        if (lastClickTime > 0 && now - lastClickTime > DOUBLE_CLICK_INTERVAL)
            lastClickTime = 0;
        else if (isMouseLeftClick && !lastClickTime)
            lastClickTime = now;
        else if (isMouseLeftClick && now - lastClickTime <= DOUBLE_CLICK_INTERVAL) {
            ClearDrawScreen();
            lastClickTime = 0;
        }
    }
}
