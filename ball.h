#pragma once

#include "baseGame.h"

namespace DxLib {

	class ball : public baseGame {
	public:
		ball();

	protected:
		void BeforeGameLoop() override;
		void MainGameLoop() override;
		void MyInitialize() override;

		// static constexpr float SPEED = 640.0f / 2;
		static constexpr float SPEED = 140.0f / 2.0f;

		float x = 0;
		float y = 0;
		float speed = 0;

	private:
		static constexpr float RADIUS = 20.0f;

	};
}
