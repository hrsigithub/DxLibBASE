// DxLibWrapper.cpp

#define _USE_MATH_DEFINES

#include <DxLib.h>
#include <cmath>

#include "DxLibWrapper.h"

namespace DxLib {

	DxLibWrapper::DxLibWrapper() {
	}

	// ������
	bool DxLibWrapper::initialize() {

#ifndef _DEBUG
		// ���O�}��
		SetOutApplicationLogValidFlag(FALSE);
#endif

		int result = ChangeWindowMode(TRUE);		// �E�C���h���[�h�ŋN�� 640*480

		MyInitialize();
		
		if (DxLib_Init() == -1) return true;

		return false; // ����
	}

	void DxLibWrapper::MyInitialize() {

		SetMainWindowText("DxLib�e�X�g���ׁB");

		// ������������
		// DxLibWrapper::WaitVSyncFlag = TRUE;
		// DxLibWrapper::AlwaysRunFlag = TRUE;
	}
}