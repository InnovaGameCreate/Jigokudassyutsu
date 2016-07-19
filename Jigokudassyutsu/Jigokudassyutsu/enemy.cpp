#include "enemy.h"

//コンストラクタ
Enemy::Enemy(int stage_num) :stage_num_(stage_num){
}

//デストラクタ
Enemy::~Enemy() {
}

//初期化
void Enemy::Initialize() {
}

//更新
void Enemy::Update() {
}

//描画
void Enemy::Draw()const {
	DrawString(0, 100, "敵", GetColor(255, 255, 255));
}

//終了処理
void Enemy::Finalize() {
}