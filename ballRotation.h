#pragma once

#include "ball.h"

namespace DxLib {

	class ballRotation :
		public ball
	{
	public:
		ballRotation();

	protected:
		void MainGameLoop() override final;

	private:
		static constexpr float SPEED_ANGLE = 360.0f / 2;
		static constexpr float RADIUS = 50.0f;

		float angle = 0, speedAngle = SPEED_ANGLE;
	};
};