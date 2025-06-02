
#define _USE_MATH_DEFINES

#include <DxLib.h>
#include <math.h>

#include "DxLibWrapper.h"
#include "Shape.h"


namespace DxLib {



	void Shape::TriangleGasket(int n) {

		Pos a{}, b{}, c{};

		a.x = 320.0f, a.y = 67.0f;
		b.x = 120.0f, b.y = 413.0f;
		c.x = 520.0f, c.y = 413.0f;

		for (int cnt = 0; cnt <= n; cnt++) {
			TriangleGasket(cnt, a, b, c);
			WaitKey();
		}
	}


	// 縦横振幅の波線
	void Shape::vertical_horizontal_amplitude(AmplitudeType amplitude, float angle) {

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

	// 円カーブ、渦巻き
	void Shape::circleCurve(CircleType circle) {

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
			for (int r = 0; r < 360 * 10; r += 5)
			{
				int x = (int)((r / 15.0f) * cos((M_PI * r) / 180.0f));
				int y = (int)((r / 15.0f) * sin((M_PI * r) / 180.0f));

				::DrawCircle(320 + x, 240 - y, 3, COLOR_CYAN, TRUE);
			}
		}
	}

	// ヒルベルト曲線 移動
	void Shape::HilbertCurveMove(HilbertCurveMoveType moveType, Pos* p) {

		switch (moveType)
		{
		case HilbertCurveMoveType::Right:
			HilbertCurveDrawLineAA(p->x, p->y, p->x + p->length, p->y);
			p->x += p->length;
			break;
		case HilbertCurveMoveType::Left:
			HilbertCurveDrawLineAA(p->x, p->y, p->x - p->length, p->y);
			p->x -= p->length;
			break;
		case HilbertCurveMoveType::Up:
			HilbertCurveDrawLineAA(p->x, p->y, p->x, p->y - p->length);
			p->y -= p->length;
			break;
		case HilbertCurveMoveType::Down:
			HilbertCurveDrawLineAA(p->x, p->y, p->x, p->y + p->length);
			p->y += p->length;
			break;
		default:
			break;
		}
	}


	// ヒルベルト曲線
	void Shape::HilbertCurve(int n) {

		Pos pos{};
		const int size = 480;
		const float startX = 80;

		for (int i = 1; i <= n; i++)
		{
			ClearDrawScreen();

			pos.length = (float)(size / pow(2, i));
			pos.x = startX + size - pos.length / 2.0f;
			pos.y = pos.length / 2.0f;

			HilbertCurveMove(HilbertCurveType::LeftDownRight, i, &pos);

			WaitKey();
		}
	}


	// コッホ曲線
	void Shape::KochCurve(int n, const Pos& a, const Pos& b) {

		if (n < 1) {
			DrawLineAA(a.x, a.y, b.x, b.y, COLOR_CYAN);
			return;
		}

		else {
			Pos c{}, d{}, e{};

			c.x = (2 * a.x + b.x) / 3;
			c.y = (2 * a.y + b.y) / 3;

			d.x = (a.x + 2 * b.x) / 3;
			d.y = (a.y + 2 * b.y) / 3;

			e.x = c.x + (d.x - c.x) * (float)cos(M_PI * 60.0 / 180.0) + (d.y - c.y) * (float)sin(M_PI * 60.0 / 180.0);
			e.y = c.y - (d.x - c.x) * (float)sin(M_PI * 60.0 / 180.0) + (d.y - c.y) * (float)cos(M_PI * 60.0 / 180.0);

			DrawTriangleAA(c.x, c.y, d.x, d.y, e.x, e.y, COLOR_CYAN, TRUE);

			KochCurve(n - 1, a, c);
			KochCurve(n - 1, c, e);
			KochCurve(n - 1, e, d);
			KochCurve(n - 1, d, b);
		}
	}


	// コッホ曲線、コッホ雪片
	void Shape::KochCurveOrSnowflake(KochType koch, int n) {
		Pos a{}, b{}, c{};

		a.x = 50.0f, a.y = 300.0f;
		b.x = 590.0f, b.y = 300.0f;

		if (koch == KochType::Snowflake) {
			a.x = 120.0f, a.y = 358.0f;
			b.x = 320.0f, b.y = 12.0f;
			c.x = 520.0f, c.y = 358.0f;

			for (int cnt = 0; cnt <= n; cnt++) {
				ClearDrawScreen();

				DrawBoxAA(105.0f, 0.0f, 535.0f, 640.0f, GetColor(0, 128, 255), TRUE);
				DrawTriangleAA(a.x, a.y, b.x, b.y, c.x, c.y, COLOR_CYAN, TRUE);

				KochCurve(cnt, a, b);
				KochCurve(cnt, b, c);
				KochCurve(cnt, c, a);

				WaitKey();
			}
		}
		else {
			for (int cnt = 0; cnt <= n; cnt++) {
				ClearDrawScreen();
				KochCurve(cnt, a, b);
				WaitKey();
			}
		}
	}

	void Shape::HilbertCurveDrawLineAA(float x1, float y1, float x2, float y2) {
		static const int STEP = 64;
		static const int MAX = 256 / STEP;
		static int r = MAX, g = MAX, b = MAX;
		static int rDir = -1, gDir = 1, bDir = -1;

		DrawLineAA(x1, y1, x2, y2, GetColor(r * STEP - 1, g * STEP - 1, b * STEP - 1));

		if ((r += rDir) >= MAX || r <= 0) {
			r = (r <= 0) ? 1 : MAX;
			rDir *= -1;
			if ((g += gDir) >= MAX || g <= 0) {
				g = (g <= 0) ? 1 : MAX;
				gDir *= -1;
			}

			if ((b += bDir) >= MAX || b <= 0) {
				b = (b <= 0) ? 1 : MAX;
				bDir *= -1;
			}
		}
	}




	// シェルピンスキー・ギャスケット
	void Shape::TriangleGasket(int n, const Pos& a, const Pos& b, const Pos& c) {

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



	// サイン、コサインカーブ
	void Shape::sin_cosCurve(WaveType wave) {

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

	void Shape::HilbertCurveMove(HilbertCurveType moveType, int n, Pos* p) {

		if (n > 0) {
			switch (moveType)
			{
			case HilbertCurveType::LeftDownRight:
				HilbertCurveMove(HilbertCurveType::DownLeftUp, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Left, p);
				HilbertCurveMove(HilbertCurveType::LeftDownRight, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Down, p);
				HilbertCurveMove(HilbertCurveType::LeftDownRight, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Right, p);
				HilbertCurveMove(HilbertCurveType::UpRightDown, n - 1, p);
				break;
			case HilbertCurveType::UpRightDown:
				HilbertCurveMove(HilbertCurveType::RightUpLeft, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Up, p);
				HilbertCurveMove(HilbertCurveType::UpRightDown, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Right, p);
				HilbertCurveMove(HilbertCurveType::UpRightDown, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Down, p);
				HilbertCurveMove(HilbertCurveType::LeftDownRight, n - 1, p);
				break;
			case HilbertCurveType::RightUpLeft:
				HilbertCurveMove(HilbertCurveType::UpRightDown, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Right, p);
				HilbertCurveMove(HilbertCurveType::RightUpLeft, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Up, p);
				HilbertCurveMove(HilbertCurveType::RightUpLeft, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Left, p);
				HilbertCurveMove(HilbertCurveType::DownLeftUp, n - 1, p);
				break;
			case HilbertCurveType::DownLeftUp:
				HilbertCurveMove(HilbertCurveType::LeftDownRight, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Down, p);
				HilbertCurveMove(HilbertCurveType::DownLeftUp, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Left, p);
				HilbertCurveMove(HilbertCurveType::DownLeftUp, n - 1, p);
				HilbertCurveMove(HilbertCurveMoveType::Up, p);
				HilbertCurveMove(HilbertCurveType::RightUpLeft, n - 1, p);
				break;
			default:
				break;
			}
		}
	}

}