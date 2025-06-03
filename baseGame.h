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
        LONGLONG fpsTimer;

        virtual void BeforeGameLoop() = 0;
        virtual void MainGameLoop() = 0;

        // FPS
        void FpsDraw(LONGLONG*);

    };
}

