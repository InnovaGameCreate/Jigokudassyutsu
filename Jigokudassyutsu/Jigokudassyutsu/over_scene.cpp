#include "over_scene.h"

//コンストラクタ
OverScene::OverScene(ISceneChanger* changer) : BaseScene(changer) {
}

//デストラクタ
OverScene::~OverScene() {
}

//初期化
void OverScene::Initialize() {
	font_handle1_ = CreateFontToHandle(NULL, 20, 6);
	handle01_ = LoadGraph("img/back/over.jpg"); //画像の読み込み
	if (handle01_ == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "画像を読み込めませんでした"); //エラー処理
	}
}

//更新
void OverScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //ESCキーが押されていたら
		scene_changer_->ChangeScene(kSceneStart);//シーンをスタート画面に変更
		return;
	}
	if (input::CheckPushAnyButton() == 1) { //何かキーが押されていたら
		scene_changer_->ChangeScene(kSceneGame1);//シーンをステージ1に変更
		return;
	}
}

//描画
void OverScene::Draw()const {
	DrawGraph(0, 0, handle01_, TRUE);  // 読みこんだグラフィックを画面左上に描画
	DrawStringToHandle(220, 370, "何かキーを押してリトライしてください", GetColor(0, 0, 0), font_handle1_);
	DrawStringToHandle(220, 410, "ESCキーでスタート画面に戻る", GetColor(0, 0, 0), font_handle1_);
}

//終了処理
void OverScene::Finalize() {
	DeleteGraph(handle01_);
	DeleteFontToHandle(font_handle1_);
}