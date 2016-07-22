#include "clear_scene.h"

//コンストラクタ
ClearScene::ClearScene(ISceneChanger* changer) : BaseScene(changer) {
}

//デストラクタ
ClearScene::~ClearScene() {
}

//初期化
void ClearScene::Initialize() {
}

//更新
void ClearScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		scene_changer_->ChangeScene(kSceneStart);//シーンをメニューに変更
	}
}

//描画
void ClearScene::Draw()const {
	DrawString(0, 0, "クリア画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとスタート画面に戻ります。", GetColor(255, 255, 255));
}

//終了処理
void ClearScene::Finalize() {
}