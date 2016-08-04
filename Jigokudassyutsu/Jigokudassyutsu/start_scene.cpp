#include "start_scene.h"

static int handle01;

//コンストラクタ
StartScene::StartScene(ISceneChanger* changer) : BaseScene(changer) {
}

//デストラクタ
StartScene::~StartScene() {
}

//初期化
void StartScene::Initialize() {
}

//更新
void StartScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_RETURN) == 1) { //Enterキーが押されていたら
		scene_changer_->ChangeScene(kSceneStageSelect);//シーンをメニューに変更
	}

	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		DxLib_End();                                   //ゲームを終了
	}
}

//描画
void StartScene::Draw()const {
	handle01 = LoadGraph("enemy.png"); //画像の読み込み
	DrawGraph(0, 0, handle01, TRUE);  // 読みこんだグラフィックを画面左上に描画

	DrawString(0, 0, "スタート画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Enterキーを押すとステージ選択画面に進みます。", GetColor(255, 255, 255));
	DrawString(0, 40, "Escキーを押すとゲームを終了します。", GetColor(255, 255, 255));
}

//終了処理
void StartScene::Finalize() {
}