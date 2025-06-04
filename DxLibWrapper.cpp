// DxLibWrapper.cpp

#define _USE_MATH_DEFINES

#include <DxLib.h>
#include <math.h>

#include "DxLibWrapper.h"

namespace DxLib {

	DxLibWrapper::DxLibWrapper() {
	}

	// 初期化
	bool DxLibWrapper::initialize() {

#ifndef _DEBUG
		// ログ抑制
		SetOutApplicationLogValidFlag(FALSE);
#endif

		int result = ChangeWindowMode(TRUE);		// ウインドモードで起動 640*480

		MyInitialize();

		//SetWaitVSyncFlag(DxLibWrapper::WaitVSyncFlag);
		//SetAlwaysRunFlag(DxLibWrapper::AlwaysRunFlag);
		
		// グラフィックウィンドウへ変更
		if (DxLib_Init() == -1) return true;

		return false; // 成功
	}

	void DxLibWrapper::MyInitialize() {

		SetMainWindowText("DxLibテストだべ。");

		// 垂直同期あり
		DxLibWrapper::WaitVSyncFlag = TRUE;

		
		DxLibWrapper::AlwaysRunFlag = TRUE;
	}
}