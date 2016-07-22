#include "over_scene.h"

//コンストラクタ
OverScene::OverScene(ISceneChanger* changer) : BaseScene(changer) {
}

//デストラクタ
OverScene::~OverScene() {
}

//初期化
void OverScene::Initialize() {
}

//更新
void OverScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		scene_changer_->ChangeScene(kSceneStart);//シーンをメニューに変更
	}
}

//描画
void OverScene::Draw()const {
	DrawString(0, 0, "ゲームオーバー画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとスタート画面に進みます。", GetColor(255, 255, 255));
}

//終了処理
void OverScene::Finalize() {
}