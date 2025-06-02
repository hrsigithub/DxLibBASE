
#define _USE_MATH_DEFINES

#include <Dxlib.h>
#include <math.h>

#include "DxLibWrapper.h"

#include "Shape.h"
#include "mainGame.h"
#include "game1.h"

using namespace DxLib;

int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	Shape wr;
	
	if (wr.initialize()) return -1;

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

	mainGame game;
	game1 game1;

	//game1.GameLoop();

	DxLib_End();

	return 0;
}

