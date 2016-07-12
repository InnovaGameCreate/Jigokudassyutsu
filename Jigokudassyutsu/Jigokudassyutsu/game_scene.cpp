#include "game_scene.h"

GameScene::GameScene(ISceneChanger* changer) : BaseScene(changer) {
}

//初期化
void GameScene::Initialize() {

}

//更新
void GameScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		scene_changer_->ChangeScene(kSceneStart);//シーンをメニューに変更
	}
}

//描画
void GameScene::Draw() {
	DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとスタート画面に戻ります。", GetColor(255, 255, 255));
}

//終了処理
void GameScene::Finalize() {

}