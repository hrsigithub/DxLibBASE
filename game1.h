#pragma once
#include "baseGame.h"

namespace DxLib {

    class game1 : public baseGame {
    public:
        game1();

    protected:
        void MainGameLoop(Params& params) override;
    };

}
