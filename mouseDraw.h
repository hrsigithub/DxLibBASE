#pragma once

#include <vector>
#include "baseGame.h"

namespace DxMouse {

	class mouseDraw :
		public baseGame
	{
	public:
		mouseDraw();

	protected:
		void MyInitialize() override;
		void BeforeGameLoop() override;
		void MainGameLoop() override;

	private:
		static constexpr int MaxColors = 6;
		static constexpr int RADIUS = 20;
		static bool isMouseLeftClick;

		typedef struct {
			int x, y;
		} POS;

		struct PALETTE {
			int R, G, B;
			POS POS;
		};

		std::vector<PALETTE> ColorTB;

		POS pre = { -1, -1 }, now = { 0, 0 };
		int selectColor = 0;

		void DrawPalette(int);
		void SelectColor(int&);
		int GetColor(int);

		void CheckDoubleClick();
	};
}

