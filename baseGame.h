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
        LONGLONG fpsTimer, deltaTimer;

        // オーバーライド禁止
        virtual float getDeltaTime(LONGLONG*) final;

        // FPS
        virtual void FpsDraw(LONGLONG*) final;

        // オーバーライド必須
        virtual void MyInitialize();
        virtual void BeforeGameLoop() = 0;
        virtual void MainGameLoop() = 0;
    };
};


