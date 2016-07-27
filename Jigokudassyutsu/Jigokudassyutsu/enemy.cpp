#include "enemy.h"

/////////////////////////////   —H—ì   /////////////////////////////////////////
EnemyYurei::EnemyYurei(float x, float y) :BaseEnemy("img/enemy/yurei.png") {
	x_ = x;
	y_ = y;
	radius_ = 50;
	speed_ = 1;
}

EnemyYurei::~EnemyYurei() {
}

void EnemyYurei::Update(int player_x, int player_y) {
	x_ += speed_;
	y_ += speed_;
}