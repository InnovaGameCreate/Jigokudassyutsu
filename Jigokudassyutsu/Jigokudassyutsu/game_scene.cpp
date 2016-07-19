#include "game_scene.h"

//コンストラクタ
GameScene::GameScene(ISceneChanger* changer, int stage_num) :
	BaseScene(changer),		//シーンチェンジャー
	stage_num_(stage_num),	//ステージナンバー
	map(stage_num),			//マップクラス
	enemy(stage_num)		//敵クラス
{
}

//デストラクタ
GameScene::~GameScene() {
}

//初期化
void GameScene::Initialize() {
	map.Initialize();
	player.Initialize();
	enemy.Initialize();
}

//更新
void GameScene::Update() {
	map.Update();
	player.Update();
	enemy.Update();
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		scene_changer_->ChangeScene(kSceneStart);//シーンをメニューに変更
	}
}

//描画
void GameScene::Draw()const {
	map.Draw();
	player.Draw();
	enemy.Draw();
	DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとスタート画面に戻ります。", GetColor(255, 255, 255));
}

//終了処理
void GameScene::Finalize() {
	player.Finalize();
	map.Finalize();
	enemy.Finalize();
}