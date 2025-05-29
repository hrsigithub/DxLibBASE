
#include <Dxlib.h>
#include "DxLibWrapper.h"

#define RED_COLOR	GetColor(255, 0, 0)


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	DxLibWrapper wr;
	if (wr.initialize()) return -1;


	printfDx("Hello World\n");

	//wr.DrawPixel();
	//WaitKey(); ClearDrawScreen();

	wr.DrawLine();
	WaitKey(); ClearDrawScreen();

	wr.DrawBox();
	wr.DrawCircle();
	wr.DrawTriangle();
	WaitKey();




	DxLib_End();

	return 0;
}

