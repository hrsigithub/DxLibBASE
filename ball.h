#pragma once

#include "baseGame.h"

namespace DxLib {

    class ball : public baseGame {
    public:
        ball();

    protected:
        void MainGameLoop(Params& params) override;
    };

}
