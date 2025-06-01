#pragma once

#include "baseGame.h"

namespace DxLib {

    class mainGame :
        public baseGame
    {

    public:
    protected:
        void MainGameLoop(Params&) override;
    };


}
