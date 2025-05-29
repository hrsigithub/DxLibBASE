
#define _USE_MATH_DEFINES

#include <Dxlib.h>
#include <math.h>

#include "DxLibWrapper.h"

#define RED_COLOR	GetColor(255, 0, 0)


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	DxLibWrapper wr;
	if (wr.initialize()) return -1;


	printfDx("Hello World\n");

	//wr.AllDraw();

	//wr.sin_cosCurve(Curve::sin);
	//wr.sin_cosCurve(DxLibWrapper::Curve::sin);
	//wr.sin_cosCurve(DxLibWrapper::Curve::cos);
	wr.circleCurve();
	WaitKey();



	DxLib_End();

	return 0;
}

