#pragma once

#include "baseGame.h"

namespace DxLib {

	class ball : public baseGame {
	public:
		ball();

	protected:
		void BeforeGameLoop() override;
		void MainGameLoop() override;

	private:
		static constexpr float Radius = 20.0f;
		static constexpr float SPEED = 640.0f / 2;

		float x;
		float y;
		float speed;
	};
}
