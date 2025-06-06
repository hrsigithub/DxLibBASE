#pragma once

#include "ball.h"

namespace DxBall {
	
	class ballRotation :
		public ball
	{
	public:
		ballRotation();

	protected:
		void MainGameLoop() override;

		float angle = 0, speedAngle = SPEED_ANGLE;
	private:
		static constexpr float SPEED_ANGLE = 360.0f / 2;
		static constexpr float RADIUS = 50.0f;
		float x, y;
	};
};