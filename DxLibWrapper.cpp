// DxLibWrapper.cpp

#define _USE_MATH_DEFINES

#include <DxLib.h>
#include <math.h>

#include "DxLibWrapper.h"

DxLibWrapper::DxLibWrapper() {

}

// ������
bool DxLibWrapper::initialize() {

#ifndef _DEBUG
	// ���O�}��
	SetOutApplicationLogValidFlag(FALSE);
#endif

	int result = ChangeWindowMode(TRUE);		// �E�C���h���[�h�ŋN�� 640*480
	SetMainWindowText("DxLib�e�X�g���ׁB");

	// �O���t�B�b�N�E�B���h�E�֕ύX
	if (DxLib_Init() == -1) return true;

	return false; // ����
}

// ��ʃN���A
void DxLibWrapper::ClearDrawScreenWithWait() {
	WaitKey(); 
	ClearDrawScreen();
}

// �S�ĕ`��
void DxLibWrapper::AllDraw() {

	DrawPixel();
	ClearDrawScreenWithWait();

	DrawLine();
	ClearDrawScreenWithWait();
		
	DrawBox();
	DrawCircle();
	DrawTriangle();

	ClearDrawScreenWithWait();
}

// �_
void DxLibWrapper::DrawPixel() {

	int r = 255, g, b = 0;

	for (int y = 0; y < 256; y++, r--)
	{
		g = 255;
		for (int x = 0; x < 256; x++, g--, b++)
		{
			::DrawPixel(192 + x, 112 + y, GetColor(r, g, b));
		}
	}
}

//	��
void DxLibWrapper::DrawLine() {

	::DrawLine(0, 0, 640, 480, COLOR_RED);
	DrawLineAA(640, 0, 0, 480, COLOR_RED, 3);

	::DrawLine(220, 0, 220, 480, GetColor(0, 255, 0));
	DrawLineAA(420, 0, 420, 480, GetColor(0, 255, 0), 3);

	::DrawLine(0, 160, 640, 160, GetColor(0, 0, 255));
	DrawLineAA(0, 320, 640, 320, GetColor(0, 0, 255), 3);
}

// �l�p�`
void DxLibWrapper::DrawBox() {
	
	::DrawBox(55, 90, 155, 190, COLOR_YELLOW, TRUE);
	DrawBoxAA(55, 280, 155, 380, COLOR_YELLOW, TRUE);

}

// �~�A�ȉ~
void DxLibWrapper::DrawCircle() {

	::DrawCircle(255, 140, 50, COLOR_PINK, TRUE);
	DrawCircleAA(255, 330, 50, 32, COLOR_PINK, TRUE);

	::DrawOval(405, 140, 50, 30, COLOR_CYAN, TRUE);
	DrawOvalAA(405, 330, 50, 30, 32, COLOR_CYAN, TRUE);

}

// �O�p�`
void DxLibWrapper::DrawTriangle() {

	::DrawTriangle(555, 90, 505, 190, 605, 190, COLOR_WHITE, TRUE);
	DrawTriangleAA(555, 280, 505, 380, 605, 380, COLOR_WHITE, TRUE);

}

// �T�C���J�[�u
void DxLibWrapper::sin_cosCurve(Curve curve) {

	// ���`��
	::DrawLine(320, 110, 320, 370, COLOR_GRAY);
	::DrawLine(30, 240, 610, 240, COLOR_GRAY);

	unsigned int color = curve == Curve::cos ? COLOR_GREEN : COLOR_RED;

	for (int x = -290; x < 290; x++)
	{
		int y = curve == Curve::cos ? (int)(cos(M_PI * x / 180.0f) * 100) : 
										(int)(sin(M_PI * x / 180.0f) * 100);
	
		::DrawPixel(320 + x, 240 - y, color);
	}

	for (int x = -290; x < 290; x+= 10)
	{
		int y = curve == Curve::cos ? (int)(cos(M_PI * x / 180.0f) * 100) :
										(int)(sin(M_PI * x / 180.0f) * 100);
		::DrawCircle(320 + x, 240 - y, 3, color, TRUE);
	}


}

// �~�J�[�u
void DxLibWrapper::circleCurve() {

	// ���`��
	::DrawLine(320, 110, 320, 370, COLOR_GRAY);
	::DrawLine(30, 240, 610, 240, COLOR_GRAY);

	for (int r = -290; r < 290; r++)
	{
		int x = (int)(cos(M_PI * r / 180.0f) * 100);
		int y = (int)(sin(M_PI * r / 180.0f) * 100);

		::DrawPixel(320 + x, 240 - y, COLOR_BLUE);
	}

	for (int r = -290; r < 290; r += 10)
	{
		int x = (int)(cos(M_PI * r / 180.0f) * 100);
		int y = (int)(sin(M_PI * r / 180.0f) * 100);

		::DrawCircle(320 + x, 240 - y, 3, COLOR_BLUE, TRUE);
	}


}
