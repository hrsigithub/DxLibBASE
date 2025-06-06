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

        // �I�[�o�[���C�h�֎~
        virtual float getDeltaTime(LONGLONG*) final;

        // FPS
        virtual void FpsDraw(LONGLONG*) final;

        // �I�[�o�[���C�h�K�{
        virtual void MyInitialize();
        virtual void BeforeGameLoop() = 0;
        virtual void MainGameLoop() = 0;
    };
};


