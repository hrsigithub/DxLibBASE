#pragma once

#include "baseGame.h"

namespace DxLib {

	class ball : public baseGame {
	public:
		ball();

	protected:
		void BeforeGameLoop() override;
		void MainGameLoop() override;
		void MyInitialize() override final;

	private:
		static constexpr float Radius = 20.0f;
		static constexpr float SPEED = 640.0f / 2;

		float x = 0;
		float y = 0;
		float speed = 0;
	};
}
