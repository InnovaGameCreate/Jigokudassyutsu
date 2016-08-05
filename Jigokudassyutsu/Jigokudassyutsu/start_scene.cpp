#include "start_scene.h"

//コンストラクタ
StartScene::StartScene(ISceneChanger* changer) : BaseScene(changer) {
}

//デストラクタ
StartScene::~StartScene() {
}

//初期化
void StartScene::Initialize() {
	Cr = GetColor(255, 255, 255);
	FontHandle = CreateFontToHandle(NULL , 40, 3);
	handle01 = LoadGraph("enemy.png"); //画像の読み込み
	if (handle01 == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "画像を読み込めませんでした"); //エラー処理
	}
}

//更新
void StartScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_RETURN) == 1) { //Enterキーが押されていたら
		scene_changer_->ChangeScene(kSceneGame1);//シーンをメニューに変更
	}
}

//描画
void StartScene::Draw()const {
	DrawGraph(0, 0, handle01, TRUE);  // 読みこんだグラフィックを画面左上に描画
	DrawStringToHandle(250, 200, "地獄脱出", Cr, FontHandle);
}

//終了処理
void StartScene::Finalize() {
	DeleteGraph(handle01);
}