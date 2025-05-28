
#include <Dxlib.h>

//int main(void) 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
#ifndef _DEBUG
	// ログ抑制
	SetOutApplicationLogValidFlag(FALSE);
#endif

	int result = ChangeWindowMode(TRUE);		// ウインドモードで起動 640*480
	SetMainWindowText("DxLibテストだべ。");

	// グラフィックウィンドウへ変更
	if (DxLib_Init() == -1) return -1;

	printfDx("Hello World\n");
//	(void)getchar();
	WaitKey();


	DxLib_End();

	return 0;
}