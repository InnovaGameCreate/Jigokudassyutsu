#include "enemy_controller.h"

//コンストラクタ
EnemyController::EnemyController(int stage_num) :stage_num_(stage_num){
}

//デストラクタ
EnemyController::~EnemyController() {
}

//初期化
void EnemyController::Initialize() {
	vec_enemy.push_back(new EnemyYurei(100, 100));
}

//更新
void EnemyController::Update() {
	for (auto itr = vec_enemy.begin(); itr != vec_enemy.end(); itr++) {
		(*itr)->Update(0, 0);
	}
}

//描画
void EnemyController::Draw()const {
	for (auto itr = vec_enemy.begin(); itr != vec_enemy.end(); itr++) {
		(*itr)->Draw();
	}
}

//終了処理
void EnemyController::Finalize() {
	//敵削除
	for (auto itr = vec_enemy.begin(); itr != vec_enemy.end();) {
		delete (*itr);
		itr = vec_enemy.erase(itr);
	}
}