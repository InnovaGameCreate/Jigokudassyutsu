#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);//ウィンドウモード
	DxLib_Init();
	DrawPixel(320, 240, GetColor(255, 255, 255));// 点を打つ
	WaitKey();// キー入力待ち
	DxLib_End();//ＤＸライブラリ終了処理
	return 0;
}