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
	if (next_scene_ != kSceneNone) {    //次のシーンがセットされていたら
		scene_->Finalize();//現在のシーンの終了処理を実行
		delete scene_;
		switch (next_scene_) {       //シーンによって処理を分岐
		case kSceneStart:        //次の画面がメニューなら
			scene_ = (BaseScene*) new StartScene(this);   //メニュー画面のインスタンスを生成する
			break;//以下略
		case kSceneGame:
			scene_ = (BaseScene*) new GameScene(this);
			break;
		}
		next_scene_ = kSceneNone;    //次のシーン情報をクリア
		scene_->Initialize();    //シーンを初期化
	}

	scene_->Update(); //シーンの更新
}

//描画
void SceneMgr::Draw() {
	scene_->Draw(); //シーンの描画
}

// 引数 nextScene にシーンを変更する
void SceneMgr::ChangeScene(Scene NextScene) {
	next_scene_ = NextScene;    //次のシーンをセットする
}
