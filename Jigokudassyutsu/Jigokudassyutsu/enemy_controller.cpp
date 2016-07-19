#include "enemy_controller.h"

//コンストラクタ
EnemyController::EnemyController(int stage_num) :stage_num_(stage_num){
}

//デストラクタ
EnemyController::~EnemyController() {
}

//初期化
void EnemyController::Initialize() {
}

//更新
void EnemyController::Update() {
}

//描画
void EnemyController::Draw()const {
	DrawString(0, 100, "敵", GetColor(255, 255, 255));
}

//終了処理
void EnemyController::Finalize() {
}