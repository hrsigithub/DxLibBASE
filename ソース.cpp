
#include <Dxlib.h>

#define RED_COLOR	GetColor(255, 0, 0)

int init() {

#ifndef _DEBUG
	// ログ抑制
	SetOutApplicationLogValidFlag(FALSE);
#endif

	int result = ChangeWindowMode(TRUE);		// ウインドモードで起動 640*480
	SetMainWindowText("DxLibテストだべ。");


	// グラフィックウィンドウへ変更
	if (DxLib_Init() == -1) return -1;

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	if (init() == -1) return -1;

	printfDx("Hello World\n");

	int r = 255, g, b = 0;

	for (int y = 0; y < 256; y++, r--)
	{
		g = 255;
		for (int x = 0; x < 256; x++, g--, b++)
		{
			DrawPixel(192 + x, 112 + y, GetColor(r, g, b));
		}
	}
	
	
	WaitKey();


	DxLib_End();

	return 0;
}

