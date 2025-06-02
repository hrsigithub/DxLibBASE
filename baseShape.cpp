#include <DxLib.h>

#include "baseShape.h"

namespace DxLib {

	// ‰æ–ÊƒNƒŠƒA
	void baseShape::ClearDrawScreenWithWait() {
		WaitKey();
		ClearDrawScreen();
	}

	// ‘S‚Ä•`‰æ
	void baseShape::AllDraw() {

		DrawPixel();
		ClearDrawScreenWithWait();

		DrawLine();
		ClearDrawScreenWithWait();

		DrawBox();
		DrawCircle();
		DrawTriangle();

		ClearDrawScreenWithWait();
	}


	// “_
	void baseShape::DrawPixel() {

		int r = 255, g, b = 0;

		for (int y = 0; y < 256; y++, r--)
		{
			g = 255;
			for (int x = 0; x < 256; x++, g--, b++)
			{
				::DrawPixel(192 + x, 112 + y, GetColor(r, g, b));
			}
		}
	}
	//	ü
	void baseShape::DrawLine() {

		::DrawLine(0, 0, 640, 480, COLOR_RED);
		DrawLineAA(640, 0, 0, 480, COLOR_RED, 3);

		::DrawLine(220, 0, 220, 480, GetColor(0, 255, 0));
		DrawLineAA(420, 0, 420, 480, GetColor(0, 255, 0), 3);

		::DrawLine(0, 160, 640, 160, GetColor(0, 0, 255));
		DrawLineAA(0, 320, 640, 320, GetColor(0, 0, 255), 3);
	}

	// ŽlŠpŒ`
	void baseShape::DrawBox() {

		::DrawBox(55, 90, 155, 190, COLOR_YELLOW, TRUE);
		DrawBoxAA(55, 280, 155, 380, COLOR_YELLOW, TRUE);

	}

	// ‰~A‘È‰~
	void baseShape::DrawCircle() {

		::DrawCircle(255, 140, 50, COLOR_PINK, TRUE);
		DrawCircleAA(255, 330, 50, 32, COLOR_PINK, TRUE);

		::DrawOval(405, 140, 50, 30, COLOR_CYAN, TRUE);
		DrawOvalAA(405, 330, 50, 30, 32, COLOR_CYAN, TRUE);

	}

	// ŽOŠpŒ`
	void baseShape::DrawTriangle() {

		::DrawTriangle(555, 90, 505, 190, 605, 190, COLOR_WHITE, TRUE);
		DrawTriangleAA(555, 280, 505, 380, 605, 380, COLOR_WHITE, TRUE);
	}




}