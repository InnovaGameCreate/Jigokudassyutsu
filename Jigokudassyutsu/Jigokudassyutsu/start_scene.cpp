#include "start_scene.h"

//コンストラクタ
StartScene::StartScene(ISceneChanger* changer) : BaseScene(changer) {
}

//デストラクタ
StartScene::~StartScene() {
}

//初期化
void StartScene::Initialize() {
	font_handle1_ = CreateFontToHandle(NULL, 20, 6);
	handle01_ = LoadGraph("img/back/start.jpg"); //画像の読み込み
	if (handle01_ == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "画像を読み込めませんでした"); //エラー処理
	}
}

//更新
void StartScene::Update() {
	if (input::CheckPushAnyButton()) { //何かボタンが押されていたら
		scene_changer_->ChangeScene(kSceneGame1);//シーンをメニューに変更
	}
}

//描画
void StartScene::Draw()const {
	DrawGraph(0, 0, handle01_, TRUE);  // 読みこんだグラフィックを画面左上に描画
	DrawStringToHandle(230, 220, "何かキーを押してください", GetColor(255, 255, 255), font_handle1_);
}

//終了処理
void StartScene::Finalize() {
	DeleteGraph(handle01_);
	DeleteFontToHandle(font_handle1_);
}