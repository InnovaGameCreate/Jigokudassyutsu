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
	handle01_ = LoadGraph("img/over.jpg"); //画像の読み込み
	if (handle01_ == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "画像を読み込めませんでした"); //エラー処理
	}
}

//更新
void OverScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		scene_changer_->ChangeScene(kSceneStart);//シーンをメニューに変更
	}
}

//描画
void OverScene::Draw()const {
	DrawGraph(0, 0, handle01_, TRUE);  // 読みこんだグラフィックを画面左上に描画
	DrawStringToHandle(230, 220, "EScキーでリトライ", GetColor(0, 255, 255), font_handle1_);
}

//終了処理
void OverScene::Finalize() {
	DeleteGraph(handle01_);
	DeleteFontToHandle(font_handle1_);
}