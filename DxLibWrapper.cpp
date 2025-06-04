// DxLibWrapper.cpp

#define _USE_MATH_DEFINES

#include <DxLib.h>
#include <math.h>

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

		SetWaitVSyncFlag(DxLibWrapper::WaitVSyncFlag);
		SetAlwaysRunFlag(DxLibWrapper::AlwaysRunFlag);
		
		// �O���t�B�b�N�E�B���h�E�֕ύX
		if (DxLib_Init() == -1) return true;

		return false; // ����
	}


	void DxLibWrapper::MyInitialize() {

		SetMainWindowText("DxLib�e�X�g���ׁB");

		// ���������Ȃ�
		DxLibWrapper::WaitVSyncFlag = FALSE;

		// ��A�N�e�B�u�ł�����
		DxLibWrapper::AlwaysRunFlag = TRUE;

	}

}