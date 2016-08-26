#include "clear_scene.h"

//コンストラクタ
ClearScene::ClearScene(ISceneChanger* changer) : BaseScene(changer) {
}

//デストラクタ
ClearScene::~ClearScene() {
}

//初期化
void ClearScene::Initialize() {
	clear_image_ = LoadGraph("img/back/clear.jpg");   //画像の読み込み
	if (clear_image_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "読み込めませんでした。");   //エラー処理

	font_handle_ = CreateFontToHandle("游明朝 Demibold", 50, 2);
}

//更新
void ClearScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		scene_changer_->ChangeScene(kSceneStart);//シーンをメニューに変更
	}
}

//描画
void ClearScene::Draw()const {
	DrawRotaGraph(320, 240, 1.0, 0, clear_image_, TRUE);   //画像の描画

	DrawString(0, 0, "クリア画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとスタート画面に戻ります。", GetColor(255, 255, 255));
	DrawStringToHandle(90, 150, "ゲームクリア！", GetColor(0, 0, 0), font_handle_);   //文字の描画
}

//終了処理
void ClearScene::Finalize() {
	DeleteGraph(clear_image_);
	DeleteFontToHandle(font_handle_);
}