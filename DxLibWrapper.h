// DxLibWrapper.h
#pragma once

namespace DxLib {

#define COLOR_RED       ::GetColor(255, 0, 0)
#define COLOR_BLUE      ::GetColor(0, 0, 255)
#define COLOR_YELLOW	::GetColor(255, 255, 0)
#define COLOR_PINK      ::GetColor(255, 0, 255)
#define COLOR_CYAN      ::GetColor(0, 255, 255)
#define COLOR_WHITE     ::GetColor(255, 255, 255)
#define COLOR_GRAY      ::GetColor(128, 128, 128)
#define COLOR_GREEN     ::GetColor(0, 255, 0)

    class DxLibWrapper {

    public:
        DxLibWrapper();
        bool initialize();

    protected:
        // êÇíºìØä˙ê›íË
        bool WaitVSyncFlag = FALSE;
        bool AlwaysRunFlag = FALSE;

        virtual void MyInitialize();
    };
}