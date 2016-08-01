#include "enemy_controller.h"

//コンストラクタ
EnemyController::EnemyController(int stage_num) :stage_num_(stage_num){
}

//デストラクタ
EnemyController::~EnemyController() {
}

//初期化
void EnemyController::Initialize() {
	switch (stage_num_) {
	case 1:
		//幽霊*1
		vec_enemy.push_back(new EnemyYurei(100, 100));
		break;
	case 2:
		//餓鬼*2
		vec_enemy.push_back(new EnemyGaki(100, 100));
		vec_enemy.push_back(new EnemyGaki(200, 100));
		break;
	case 3:
		//がしゃどくろ*3
		vec_enemy.push_back(new EnemyDokuro(100, 100));
		vec_enemy.push_back(new EnemyDokuro(200, 100));
		vec_enemy.push_back(new EnemyDokuro(300, 100));
		break;
	case 4:
		//堕天使*3
		vec_enemy.push_back(new EnemyDatenshi(100, 100));
		vec_enemy.push_back(new EnemyDatenshi(200, 100));
		vec_enemy.push_back(new EnemyDatenshi(300, 100));
		break;
	case 5:
		//閻魔大王
		vec_enemy.push_back(new EnemyEnma(100, 100));
		//鬼*2
		vec_enemy.push_back(new EnemyOni(200, 100));
		vec_enemy.push_back(new EnemyOni(300, 100));
		break;
	default:
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "そのステージは設定されていません");
		break;
	}
}

//更新
void EnemyController::Update(float player_x, int player_y) {
	for (auto itr = vec_enemy.begin(); itr != vec_enemy.end(); itr++) {
		(*itr)->Update(player_x, player_y);
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
		(*itr)->Finalize();
		delete (*itr);
		itr = vec_enemy.erase(itr);
	}
}