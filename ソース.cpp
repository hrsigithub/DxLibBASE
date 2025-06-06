
#define _USE_MATH_DEFINES

#include <Dxlib.h>

#include "DxLibWrapper.h"

#include "Shape.h"
#include "ball.h"
#include "ballRotation.h"
#include "polygonRotation.h"
#include "mouseDraw.h"

using namespace DxLib;
using namespace DxBall;
using namespace DxMouse;

int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	//Shape shape;
    ball ball;
	ballRotation ballRotation;
	polygonRotation polygon;
	mouseDraw target;

	if (target.initialize()) return -1;


	//target.AllDraw();

	//target.vertical_horizontal_amplitude(baseShape::AmplitudeType::Vertical);
	//target.vertical_horizontal_amplitude(baseShape::AmplitudeType::Horizontal);

	//WaitKey();

	//target.circleCurve(baseShape::CircleType::Whirlpool);

	//target.TriangleGasket();

	//target.KochCurveOrSnowflake();
	//target.KochCurveOrSnowflake(baseShape::KochType::Snowflake);

	//target.HilbertCurve();
	//WaitKey();


	target.GameLoop();

	DxLib_End();

	return 0;
}

