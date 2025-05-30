
#define _USE_MATH_DEFINES

#include <Dxlib.h>
#include <math.h>

#include "DxLibWrapper.h"

using namespace DxLib;

int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	DxLibWrapper wr;
	if (wr.initialize()) return -1;

	printfDx("Hello World\n");

//	wr.AllDraw();

	//wr.vertical_horizontal_amplitude(DxLibWrapper::AmplitudeType::Vertical);
	//wr.vertical_horizontal_amplitude(DxLibWrapper::AmplitudeType::Horizontal);

	///WaitKey();

	wr.circleCurve(DxLibWrapper::CircleType::Whirlpool);

	WaitKey();


	DxLib_End();

	return 0;
}

