
#include <Dxlib.h>

//int main(void) 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
#ifndef _DEBUG
	// ���O�}��
	SetOutApplicationLogValidFlag(FALSE);
#endif

	int result = ChangeWindowMode(TRUE);		// �E�C���h���[�h�ŋN�� 640*480
	SetMainWindowText("DxLib�e�X�g���ׁB");

	// �O���t�B�b�N�E�B���h�E�֕ύX
	if (DxLib_Init() == -1) return -1;

	printfDx("Hello World\n");
//	(void)getchar();
	WaitKey();


	DxLib_End();

	return 0;
}