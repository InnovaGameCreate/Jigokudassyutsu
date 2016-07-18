#include "stage_select_scene.h"

//コンストラクタ
StageSelectScene::StageSelectScene(ISceneChanger* changer) : BaseScene(changer) {
}

//デストラクタ
StageSelectScene::~StageSelectScene() {
}

//初期化
void StageSelectScene::Initialize() {
}

//更新
void StageSelectScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		scene_changer_->ChangeScene(kSceneGame1);//シーンをメニューに変更
	}
}

//描画
void StageSelectScene::Draw() {
	DrawString(0, 0, "ステージ選択画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
}

//終了処理
void StageSelectScene::Finalize() {
}