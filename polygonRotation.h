#pragma once
#include "ballRotation.h"

namespace DxBall {

class polygonRotation :
        public ballRotation
    {
    public:
        polygonRotation();

    protected:
        void MainGameLoop() override;

    private:
        static constexpr float RADIUS = 80.0f;
        static constexpr float INTERVAL = 1.5f;
        static constexpr int POLYGON_MIN = 3;
        static constexpr int POLYGON_MAX = 10;

        static constexpr float x = 320, y = 240;

        int n = POLYGON_MIN, dn = 1;
        float intervalTime = INTERVAL;
    };
};

