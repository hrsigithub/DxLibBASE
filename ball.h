#pragma once

#include "baseGame.h"

namespace DxBall {

	class ball : public baseGame {
	public:
		ball();

	protected:
		static constexpr float SPEED = 140.0f / 2.0f;

		void BeforeGameLoop() override;
		void MainGameLoop() override;
		void MyInitialize() override;

		float x = 0;
		float y = 0;
		float speed = 0;

	private:
		static constexpr float RADIUS = 20.0f;

	};
}
