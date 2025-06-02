#pragma once

#include "Windows.h"
#include "DxLibWrapper.h"

namespace DxLib {

    class baseGame :
        public DxLibWrapper
    {

    public:
        baseGame();
        void GameLoop();

    protected:
        LONGLONG fpsTimer = GetNowHiPerformanceCount();

        static constexpr float Radius = 20.0f;

        struct Params {
            float x;
            float y;
        };
        Params params{};

        virtual void MainGameLoop(Params&) = 0;

        // FPS
        void FpsDraw(LONGLONG*);

    };
}

