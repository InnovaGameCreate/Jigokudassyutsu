#include "game_scene.h"

//コンストラクタ
GameScene::GameScene(ISceneChanger* changer, int stage_num) :
	BaseScene(changer),		//シーンチェンジャー
	kStageNum(stage_num),	//ステージナンバー
	map_(stage_num),			//マップクラス
	enemy_controller_(stage_num, kWindowWidth, kWindowHeight),		//敵クラス
	col_road_(stage_num, kWindowWidth, kWindowHeight)	//道の当たり判定
{
}

//初期スタート位置
const int GameScene::kStartX[] = { 80,80,80,80,80 };
const int GameScene::kStartY[] = { 400,400,400,400,400 };

//デストラクタ
GameScene::~GameScene() {
}

//初期化
void GameScene::Initialize() {
	map_.Initialize();
	player_.Initialize();
	enemy_controller_.Initialize();
	col_road_.Initialize();

	start_img_ = LoadGraph("img/system/start.png");
	if (start_img_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "スタート画像が読み込めません");

	game_state_ = kStart;
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

	switch (game_state_) {
	case kStart://スタート前
		int mouse_x, mouse_y;
		GetMousePoint(&mouse_x, &mouse_y);
		if (util::CirclePointCollision(kStartX[kStageNum - 1], kStartY[kStageNum - 1], kStartRadius, mouse_x, mouse_y)) {
			SetCursor(LoadCursor(NULL, IDC_HAND));
			if (input::CheckMouseLeftKey() == 1)
				game_state_ = kPlay;
		}
		break;
	case kPlay://プレイ中
		int px, py;
		player_.Update(&px, &py);
		if (enemy_controller_.Update(px, py, player_.kPlayerRadius))
			std::cout << "敵と接触" << std::endl;
		if (col_road_.Update(px, py, player_.kPlayerRadius))
			std::cout << "範囲外" << std::endl;
		else
			std::cout << "範囲内" << std::endl;
		break;
	}
#ifdef _DEBUG
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		GoNextStage();//次のステージに進む
	}
#endif
}

//描画
void GameScene::Draw()const {
	map_.Draw();

	switch (game_state_) {
	case kStart://スタート前
		DrawRotaGraph(kStartX[kStageNum - 1], kStartY[kStageNum - 1], 1.0, 0.0, start_img_, TRUE);
		break;
	case kPlay://プレイ中
		player_.Draw();
		enemy_controller_.Draw();
		col_road_.Draw();
		break;
	}

#ifdef _DEBUG
	std::string str = "ゲーム画面(ステージ" + std::to_string(kStageNum) + ")です。";
	DrawString(0, 0, str.c_str(), GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すと次のステージに進みます。", GetColor(255, 255, 255));
#endif
}

//終了処理
void GameScene::Finalize() {
	DeleteGraph(start_img_);

	player_.Finalize();
	map_.Finalize();
	enemy_controller_.Finalize();
	col_road_.Finalize();
}