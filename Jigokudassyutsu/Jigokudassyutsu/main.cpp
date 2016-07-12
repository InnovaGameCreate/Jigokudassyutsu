#include "DxLib.h"
#include "define.h"
#include "fps.h"
#include "scene_mgr.h"

//ゲーム起動時に行う初期化
namespace {
	void FirstInit() {
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
	}
}

//ループ中に必ず行う処理
namespace {
	int ProcessLoop() {
		if (ScreenFlip() != 0)return -1;//裏画面描画
		if (ProcessMessage() != 0)return -1;//プロセス処理
		if (ClearDrawScreen() != 0)return -1;//画面クリア処理
		return 0;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	SceneMgr scene_mgr;

	//初期化
	FirstInit();
	scene_mgr.Initialize();

	//メインループ
	while (ProcessLoop() == 0) {
		scene_mgr.Update();
		scene_mgr.Draw();
	}

	//終了処理
	scene_mgr.Finalize();
	DxLib_End();//ＤＸライブラリ終了処理

	return 0;
}