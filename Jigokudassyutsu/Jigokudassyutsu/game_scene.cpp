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

//スタート位置,半径
const int GameScene::kStartX[] = { 32,25,5,620,147 };
const int GameScene::kStartY[] = { 455,454,436,426,397 };
const int GameScene::kStartRadius[] = { 30,30,30,10,30 };
//ゴール位置,半径
const int GameScene::kGoalX[] = { 633,32,637,7,640 };
const int GameScene::kGoalY[] = { 324,13,37,440,0 };
const int GameScene::kGoalRadius[] = { 30,30,30,30,30 };

//デストラクタ
GameScene::~GameScene() {
}

//初期化
void GameScene::Initialize() {
	//各クラス初期化
	map_.Initialize();
	player_.Initialize();
	enemy_controller_.Initialize();
	col_road_.Initialize();
	//スタート部分とゴール部分の画像読み込み
	start_img_ = LoadGraph("img/system/start.png");
	if (start_img_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "スタート画像が読み込めません");
	goal_img_ = LoadGraph("img/system/goal.png");
	if (start_img_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "ゴール画像が読み込めません");
	//状態をスタートに設定
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
	//マップは常に更新
	map_.Update();
	//ゲームの状態によって分岐
	switch (game_state_) {
	case kStart://スタート前
		//マウス座標取得
		int mouse_x, mouse_y;
		GetMousePoint(&mouse_x, &mouse_y);
		//マウスがスタートボタン上にないならswitch文終了
		if (util::CirclePointCollision(kStartX[kStageNum - 1], kStartY[kStageNum - 1], kStartRadius[kStageNum - 1], mouse_x, mouse_y) == false)
			break;
		//ホバー時マウスの形を変える
		SetCursor(LoadCursor(NULL, IDC_HAND));
		//クリックで移行
		if (input::CheckMouseLeftKey() == 1) {
			game_state_ = kPlay;
			while (ShowCursor(false) >= 0);//カーソルを消す
		}
		break;
	case kPlay://プレイ中
		int px, py;
		//プレイヤー更新
		player_.Update(&px, &py);
		//敵更新 & 敵とのあたり判定
		if (enemy_controller_.Update(px, py, player_.kPlayerRadius))
#ifndef _DEBUG
			scene_changer_->ChangeScene(kSceneOver);
#else
			std::cout << "敵と接触" << std::endl;
#endif
		//道とのあたり判定
		if (col_road_.Update(px, py, player_.kPlayerRadius))
			scene_changer_->ChangeScene(kSceneOver);

		//ゴール到着時
		if (util::CirclePointCollision(kGoalX[kStageNum - 1], kGoalY[kStageNum - 1], kGoalRadius[kStageNum - 1], px, py))
			GoNextStage();	//次のステージに進む
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
	//マップは常に描画
	map_.Draw();
	//状態によって分岐
	switch (game_state_) {
	case kStart://スタート前
		DrawRotaGraph(kStartX[kStageNum - 1], kStartY[kStageNum - 1], 1.0, 0.0, start_img_, TRUE);//スタートボタン
		break;
	case kPlay://プレイ中
		DrawRotaGraph(kGoalX[kStageNum - 1], kGoalY[kStageNum - 1], 1.0, 0.0, goal_img_, TRUE);//ゴールボタン
		enemy_controller_.Draw();//敵
		player_.Draw();//自分
		col_road_.Draw();//道のあたり判定
		break;
	}
}

//終了処理
void GameScene::Finalize() {
	//画像を開放
	DeleteGraph(start_img_);
	DeleteGraph(goal_img_);
	//各クラスの終了処理
	player_.Finalize();
	map_.Finalize();
	enemy_controller_.Finalize();
	col_road_.Finalize();
	//カーソルを戻す
	while (ShowCursor(true) < 0);//カーソルカウントが0以上になるまでループさせる

}