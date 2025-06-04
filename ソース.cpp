
#define _USE_MATH_DEFINES

#include <Dxlib.h>

#include "DxLibWrapper.h"

#include "Shape.h"
#include "ball.h"
#include "ballRotation.h"


using namespace DxLib;

int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	//Shape wr;
//	ball ball;
	ballRotation ball;

	if (ball.initialize()) return -1;

	//printfDx("Hello World\n");

	//wr.AllDraw();

	//wr.vertical_horizontal_amplitude(baseShape::AmplitudeType::Vertical);
	//wr.vertical_horizontal_amplitude(baseShape::AmplitudeType::Horizontal);

	//WaitKey();

	//wr.circleCurve(baseShape::CircleType::Whirlpool);

	//wr.TriangleGasket();

	//wr.KochCurveOrSnowflake();
	//wr.KochCurveOrSnowflake(baseShape::KochType::Snowflake);

	//wr.HilbertCurve();
	//WaitKey();


	ball.GameLoop();

	DxLib_End();

	return 0;
}

