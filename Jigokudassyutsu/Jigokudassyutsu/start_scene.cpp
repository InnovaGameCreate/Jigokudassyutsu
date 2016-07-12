#include "start_scene.h"

StartScene::StartScene(ISceneChanger* changer) : BaseScene(changer) {
}

//初期化
void StartScene::Initialize() {

}

//更新
void StartScene::Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
		scene_changer_->ChangeScene(kSceneGame);//シーンをメニューに変更
	}
}

//描画
void StartScene::Draw() {
	BaseScene::Draw();//親クラスの描画メソッドを呼ぶ
	DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
}

//終了処理
void StartScene::Finalize() {

}