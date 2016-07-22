#include "game_scene.h"

//コンストラクタ
GameScene::GameScene(ISceneChanger* changer, int stage_num) :
	BaseScene(changer),		//シーンチェンジャー
	stage_num_(stage_num),	//ステージナンバー
	map(stage_num),			//マップクラス
	enemy_controller(stage_num)		//敵クラス
{
}

//デストラクタ
GameScene::~GameScene() {
}

//初期化
void GameScene::Initialize() {
	map.Initialize();
	player.Initialize();
	enemy_controller.Initialize();
}

void GameScene::GoNextStage() {
	switch (stage_num_) {
	case 1:
		scene_changer_->ChangeScene(kSceneGame2);
		break;
	case 2:
		scene_changer_->ChangeScene(kSceneGame3);
		break;
	case 3:
		scene_changer_->ChangeScene(kSceneGame4);
		break;
	case 4:
		scene_changer_->ChangeScene(kSceneGame5);
		break;
	case 5:
		scene_changer_->ChangeScene(kSceneClear);
		break;
	default:
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "未設定のstage_num_です,スタート画面に移行します");
		scene_changer_->ChangeScene(kSceneStart);
		break;
	}
}

//更新
void GameScene::Update() {
	map.Update();
	player.Update();
	enemy_controller.Update();
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		GoNextStage();//次のステージに進む
	}
}

//描画
void GameScene::Draw()const {
	map.Draw();
	player.Draw();
	enemy_controller.Draw();
	char string[256];
	sprintf_s(string, "ゲーム画面(ステージ%d)です。", stage_num_);
	DrawString(0, 0, string, GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとスタート画面に戻ります。", GetColor(255, 255, 255));
}

//終了処理
void GameScene::Finalize() {
	player.Finalize();
	map.Finalize();
	enemy_controller.Finalize();
}