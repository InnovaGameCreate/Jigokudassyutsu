#include "DxLib.h"
#include "define.h"
#include "fps.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

#ifdef _DEBUG
#pragma warning( disable : 4996 ) // freopen の警告を出力しない
	::AllocConsole();               // コマンドプロンプトが表示される
	freopen("CON", "r", stdin);     // 標準入力の割り当て
	freopen("CON", "w", stdout);    // 標準出力の割り当て
	freopen("CON", "w", stderr);    // 標準エラー出力の割り当て
#endif // _DEBUG

	ChangeWindowMode(TRUE);//ウィンドウモード
	SetGraphMode(kWindowWidth, kWindowHeight, 16);//ウィンドウの大きさ変更
	SetMainWindowText("地獄脱出");
	DxLib_Init();//DXライブラリ初期化
	SetDrawScreen(DX_SCREEN_BACK);//裏画面化
	DrawPixel(320, 240, GetColor(255, 255, 255));// 点を打つ

	WaitKey();// キー入力待ち
	DxLib_End();//ＤＸライブラリ終了処理

	return 0;
}