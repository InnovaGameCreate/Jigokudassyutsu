#include "scene_mgr.h"

SceneMgr::SceneMgr() :
	next_scene_(kSceneNone) //次のシーン管理変数
{
	scene_ = (BaseScene*) new StartScene(this);
}

//初期化
void SceneMgr::Initialize() {
	scene_->Initialize();
}

//終了処理
void SceneMgr::Finalize() {
	scene_->Finalize();
}

//更新
void SceneMgr::Update() {
	if (next_scene_ != kSceneNone) {//次のシーンがセットされていたら
		scene_->Finalize();			//現在のシーンの終了処理を実行
		delete scene_;
		switch (next_scene_) {		//シーンによって処理を分岐
		case kSceneStart:			//次の画面がメニューなら
			scene_ = (BaseScene*) new StartScene(this);   //スタート画面のインスタンスを生成する
			break;//以下略
		case kSceneStageSelect:
			scene_ = (BaseScene*)new StageSelectScene(this);
			break;
		case kSceneGame1:
			scene_ = (BaseScene*) new GameScene(this, 1);
			break;
		case kSceneGame2:
			scene_ = (BaseScene*) new GameScene(this, 2);
			break;
		case kSceneGame3:
			scene_ = (BaseScene*) new GameScene(this, 3);
			break;
		case kSceneGame4:
			scene_ = (BaseScene*) new GameScene(this, 4);
			break;
		case kSceneGame5:
			scene_ = (BaseScene*) new GameScene(this, 5);
			break;
		default:
			util::ErrorOutPut(__FILE__, __func__, __LINE__, "不明なシーンです、スタート画面に移行します");
			scene_ = (BaseScene*) new StartScene(this);   //スタート画面のインスタンスを生成する
		}
		next_scene_ = kSceneNone;   //次のシーン情報をクリア
		scene_->Initialize();		//シーンを初期化
	}

	scene_->Update();	//シーンの更新
}

//描画
void SceneMgr::Draw() {
	scene_->Draw();		//シーンの描画
}

// 引数 nextScene にシーンを変更する
void SceneMgr::ChangeScene(Scene NextScene) {
	next_scene_ = NextScene;    //次のシーンをセットする
}