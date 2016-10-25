#include "DxLib.h"
#include "define.h"
#include "fps.h"
#include "scene_mgr.h"
#include "input.h"

//ゲーム起動時に行う初期化
namespace {
	void FirstInit() {
		//コンソール表示
#ifdef _DEBUG
#pragma warning( disable : 4996 ) // freopen の警告を出力しない
		::AllocConsole();               // コマンドプロンプトが表示される
		freopen("CON", "r", stdin);     // 標準入力の割り当て
		freopen("CON", "w", stdout);    // 標準出力の割り当て
		freopen("CON", "w", stderr);    // 標準エラー出力の割り当て
#endif // _DEBUG

		//DXライブラリ関係初期化
		ChangeWindowMode(TRUE);//ウィンドウモード
		SetGraphMode(kWindowWidth, kWindowHeight, 16);//ウィンドウの大きさ変更
		SetMainWindowText("地獄脱出");
		DxLib_Init();//DXライブラリ初期化
		SetDrawScreen(DX_SCREEN_BACK);//裏画面化

		//util関係初期化
		input::Init();
	}
}

//ループ中に必ず行う処理
namespace {
	int ProcessLoop() {
		if (ScreenFlip() != 0)return -1;//裏画面描画
		if (ProcessMessage() != 0)return -1;//プロセス処理
		if (ClearDrawScreen() != 0)return -1;//画面クリア処理
		input::Update();//入力更新
		return 0;
	}
}

//Testビルド以外の時のメイン関数
#ifndef _JIGOKU_TEST
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	FirstInit();		//ゲーム起動時に必要な初期化

	SceneMgr scene_mgr;	//画面遷移クラス生成
	Fps fps(60);		//fps管理クラス作成(fps=60)

	//初期化
	scene_mgr.Initialize();

	//メインループ
	while (ProcessLoop() == 0) {
		//画面遷移更新,描画
		scene_mgr.Update();
		scene_mgr.Draw();
		//fps
		fps.Update();
		fps.Wait();
		fps.Draw(10, 10);
	}

	//終了処理
	scene_mgr.Finalize();
	DxLib_End();//ＤＸライブラリ終了処理

	return 0;
}
#endif

#ifdef _JIGOKU_TEST
#include <gtest/gtest.h>

//テスト実行時と終了時の処理
class TestEnviroment :public ::testing::Environment {
	virtual void SetUp() {
		//DXライブラリ関係初期化
		ChangeWindowMode(TRUE);//ウィンドウモード
		DxLib_Init();//DXライブラリ初期化
	}

	virtual void TearDown() {
		DxLib_End();//ＤＸライブラリ終了処理
	}
};

//Testビルドの時のメイン関数
int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	::testing::AddGlobalTestEnvironment(new TestEnviroment);
	return RUN_ALL_TESTS();
}

#endif