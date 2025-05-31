// DxLibWrapper.cpp

#define _USE_MATH_DEFINES

#include <DxLib.h>
#include <math.h>

#include "DxLibWrapper.h"

namespace DxLib {

	DxLibWrapper::DxLibWrapper() {

	}

	// 初期化
	bool DxLibWrapper::initialize() {

#ifndef _DEBUG
		// ログ抑制
		SetOutApplicationLogValidFlag(FALSE);
#endif

		int result = ChangeWindowMode(TRUE);		// ウインドモードで起動 640*480
		SetMainWindowText("DxLibテストだべ。");

		// グラフィックウィンドウへ変更
		if (DxLib_Init() == -1) return true;

		return false; // 成功
	}

	// 画面クリア
	void DxLibWrapper::ClearDrawScreenWithWait() {
		WaitKey();
		ClearDrawScreen();
	}

	// 全て描画
	void DxLibWrapper::AllDraw() {

		DrawPixel();
		ClearDrawScreenWithWait();

		DrawLine();
		ClearDrawScreenWithWait();

		DrawBox();
		DrawCircle();
		DrawTriangle();

		ClearDrawScreenWithWait();
	}

	// 点
	void DxLibWrapper::DrawPixel() {

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

	//	線
	void DxLibWrapper::DrawLine() {

		::DrawLine(0, 0, 640, 480, COLOR_RED);
		DrawLineAA(640, 0, 0, 480, COLOR_RED, 3);

		::DrawLine(220, 0, 220, 480, GetColor(0, 255, 0));
		DrawLineAA(420, 0, 420, 480, GetColor(0, 255, 0), 3);

		::DrawLine(0, 160, 640, 160, GetColor(0, 0, 255));
		DrawLineAA(0, 320, 640, 320, GetColor(0, 0, 255), 3);
	}

	// 四角形
	void DxLibWrapper::DrawBox() {

		::DrawBox(55, 90, 155, 190, COLOR_YELLOW, TRUE);
		DrawBoxAA(55, 280, 155, 380, COLOR_YELLOW, TRUE);

	}

	// 円、楕円
	void DxLibWrapper::DrawCircle() {

		::DrawCircle(255, 140, 50, COLOR_PINK, TRUE);
		DrawCircleAA(255, 330, 50, 32, COLOR_PINK, TRUE);

		::DrawOval(405, 140, 50, 30, COLOR_CYAN, TRUE);
		DrawOvalAA(405, 330, 50, 30, 32, COLOR_CYAN, TRUE);

	}

	// 三角形
	void DxLibWrapper::DrawTriangle() {

		::DrawTriangle(555, 90, 505, 190, 605, 190, COLOR_WHITE, TRUE);
		DrawTriangleAA(555, 280, 505, 380, 605, 380, COLOR_WHITE, TRUE);

	}

	// 縦横振幅の波線
	void DxLibWrapper::vertical_horizontal_amplitude(AmplitudeType amplitude, float angle) {

		if (amplitude == AmplitudeType::Vertical) {
			for (int x = 0; x < 640; x += 2)
			{
				int y = (int)(80.0 * sin(M_PI * x * angle / 180.0f));

				::DrawCircle(x, 240 - y, 3, COLOR_YELLOW, TRUE);
			}
		}
		else {
			for (int y = 0; y < 480.0; y += 2)
			{
				int x = (int)(80.0 * sin(M_PI * y * angle / 180.0f));

				::DrawCircle(320 + x, y, 3, COLOR_PINK, TRUE);
			}
		}
	}

	// サイン、コサインカーブ
	void DxLibWrapper::sin_cosCurve(WaveType wave) {

		// 軸描画
		::DrawLine(320, 110, 320, 370, COLOR_GRAY);
		::DrawLine(30, 240, 610, 240, COLOR_GRAY);

		unsigned int color = wave == WaveType::Cos ? COLOR_GREEN : COLOR_RED;

		for (int x = -290; x < 290; x++)
		{
			int y = wave == WaveType::Cos ? (int)(cos(M_PI * x / 180.0f) * 100) :
				(int)(sin(M_PI * x / 180.0f) * 100);

			::DrawPixel(320 + x, 240 - y, color);
		}

		for (int x = -290; x < 290; x += 10)
		{
			int y = wave == WaveType::Cos ? (int)(cos(M_PI * x / 180.0f) * 100) :
				(int)(sin(M_PI * x / 180.0f) * 100);

			::DrawCircle(320 + x, 240 - y, 3, color, TRUE);
		}


	}

	// 円カーブ、渦巻き
	void DxLibWrapper::circleCurve(CircleType circle) {

		// 軸描画
		::DrawLine(320, 110, 320, 370, COLOR_GRAY);
		::DrawLine(30, 240, 610, 240, COLOR_GRAY);

		if (circle == CircleType::Circle) {
			for (int r = -290; r < 290; r++)
			{
				int x = (int)(cos(M_PI * r / 180.0f) * 100);
				int y = (int)(sin(M_PI * r / 180.0f) * 100);

				::DrawPixel(320 + x, 240 - y, COLOR_BLUE);
			}

			for (int r = -290; r < 290; r += 10)
			{
				int x = (int)(cos(M_PI * r / 180.0f) * 100);
				int y = (int)(sin(M_PI * r / 180.0f) * 100);

				::DrawCircle(320 + x, 240 - y, 3, COLOR_BLUE, TRUE);
			}

		}
		else {
			for (int r = 0; r < 360 * 10; r+= 5)
			{
				int x = (int)((r / 15.0f) * cos((M_PI * r) / 180.0f));
				int y = (int)((r / 15.0f) * sin((M_PI * r) / 180.0f));

				::DrawCircle(320 + x, 240 - y, 3, COLOR_CYAN, TRUE);
			}
		}
	}

	void DxLibWrapper::TriangleGasket(int n) {

		Pos a{}, b{}, c{};

		a.x = 320.0f, a.y = 67.0f;
		b.x = 120.0f, b.y = 413.0f;
		c.x = 520.0f, c.y = 413.0f;

		for (int cnt = 0; cnt <= n; cnt++) {
			TriangleGasket(cnt, a, b, c);
			WaitKey();
		}
	}

	// シェルピンスキー・ギャスケット
	void DxLibWrapper::TriangleGasket(int n, const Pos& a, const Pos& b, const Pos& c) {

		DrawTriangleAA(a.x, a.y, b.x, b.y, c.x, c.y, 
			GetColor(Color_tb[n].r, Color_tb[n].g, Color_tb[n].b), TRUE);

		//WaitTimer(200);

		if (n < 1) return;
		else {
			Pos d{}, e{}, f{};

			d.x = (a.x + b.x) / 2;
			d.y = (a.y + b.y) / 2;

			e.x = (b.x + c.x) / 2;
			e.y = (b.y + c.y) / 2;

			f.x = (a.x + c.x) / 2;
			f.y = (a.y + c.y) / 2;

			TriangleGasket(n - 1, a, d, f);
			TriangleGasket(n - 1, d, b, e);
			TriangleGasket(n - 1, f, e, c);
		}
	}

}