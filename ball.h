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
		static constexpr float SPEED = 0.01f;

		float x;
		float y;
		float speed;
	};
}
