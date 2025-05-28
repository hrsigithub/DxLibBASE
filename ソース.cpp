
#include <Dxlib.h>

#define RED_COLOR	GetColor(255, 0, 0)

int init() {

#ifndef _DEBUG
	// ���O�}��
	SetOutApplicationLogValidFlag(FALSE);
#endif

	int result = ChangeWindowMode(TRUE);		// �E�C���h���[�h�ŋN�� 640*480
	SetMainWindowText("DxLib�e�X�g���ׁB");


	// �O���t�B�b�N�E�B���h�E�֕ύX
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

