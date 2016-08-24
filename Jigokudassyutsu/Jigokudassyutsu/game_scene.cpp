#include "game_scene.h"

//コンストラクタ
GameScene::GameScene(ISceneChanger* changer, int stage_num) :
	BaseScene(changer),		//シーンチェンジャー
	kStageNum(stage_num),	//ステージナンバー
	map_(stage_num),			//マップクラス
	enemy_controller_(stage_num),		//敵クラス
	col_road_(stage_num, kWindowWidth, kWindowHeight)	//道の当たり判定
{
}

//デストラクタ
GameScene::~GameScene() {
}

//初期化
void GameScene::Initialize() {
	map_.Initialize();
	player_.Initialize();
	enemy_controller_.Initialize();
	col_road_.Initialize();
}

//次のステージに進みます
//最終ステージではクリア画面に進みます
void GameScene::GoNextStage() {
	switch (kStageNum) {
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
	map_.Update();
	int px, py;
	player_.Update(&px, &py);
	if (enemy_controller_.Update(px, py, player_.kPlayerRadius))
		std::cout << "敵と接触" << std::endl;
	if (col_road_.Update(px, py, player_.kPlayerRadius))
		std::cout << "範囲外" << std::endl;
	else
		std::cout << "範囲内" << std::endl;

	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		GoNextStage();//次のステージに進む
	}
}

//描画
void GameScene::Draw()const {
	map_.Draw();
	player_.Draw();
	enemy_controller_.Draw();
	col_road_.Draw();
	std::string str = "ゲーム画面(ステージ" + std::to_string(kStageNum) + ")です。";
	DrawString(0, 0, str.c_str(), GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すと次のステージに進みます。", GetColor(255, 255, 255));
}

//終了処理
void GameScene::Finalize() {
	player_.Finalize();
	map_.Finalize();
	enemy_controller_.Finalize();
	col_road_.Finalize();
}