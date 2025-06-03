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
		SetMainWindowText("DxLib�e�X�g���ׁB");

		// ���������Ȃ�
		SetWaitVSyncFlag(FALSE);

		// �O���t�B�b�N�E�B���h�E�֕ύX
		if (DxLib_Init() == -1) return true;

		return false; // ����
	}




}