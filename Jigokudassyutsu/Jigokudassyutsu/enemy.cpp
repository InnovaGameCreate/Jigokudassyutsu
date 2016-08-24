#include "enemy.h"

////////////////////////////////////   幽霊   ////////////////////////////////////
EnemyYurei::EnemyYurei(float x, float y) :BaseEnemy("img/enemy/yurei.png") {
	x_ = x;
	y_ = y;
	radius_ = 50;
	speed_ = 1;
}

void EnemyYurei::Update(int player_x, int player_y, int cnt) {
	x_ += speed_;
	y_ += speed_;
}

////////////////////////////////////   餓鬼   ////////////////////////////////////
EnemyGaki::EnemyGaki(float x, float y) :BaseEnemy("img/enemy/gaki.png") {
	x_ = x;
	y_ = y;
	radius_ = 50;
	speed_ = 1;
}

void EnemyGaki::Update(int player_x, int player_y, int cnt) {
	x_ += speed_;
	y_ += speed_;
}

////////////////////////////////////   がしゃどくろ   ////////////////////////////////////
EnemyDokuro::EnemyDokuro(float x, float y) :BaseEnemy("img/enemy/dokuro.png") {
	x_ = x;
	y_ = y;
	radius_ = 50;
	speed_ = 1;
}

void EnemyDokuro::Update(int player_x, int player_y, int cnt) {
	x_ += speed_;
	y_ += speed_;
}

////////////////////////////////////   堕天使   ////////////////////////////////////
EnemyDatenshi::EnemyDatenshi(float x, float y) :BaseEnemy("img/enemy/datenshi.png") {
	x_ = x;
	y_ = y;
	radius_ = 60;
	speed_ = 1;
}

void EnemyDatenshi::Update(int player_x, int player_y, int cnt) {
	x_ += speed_;
	y_ += speed_;
}

////////////////////////////////////   閻魔大王   ////////////////////////////////////
EnemyEnma::EnemyEnma(float x, float y) :BaseEnemy("img/enemy/enma.png") {
	x_ = x;
	y_ = y;
	radius_ = 100;
	speed_ = 1;
}

void EnemyEnma::Update(int player_x, int player_y, int cnt) {
	x_ += speed_;
	y_ += speed_;
}

////////////////////////////////////   鬼   ////////////////////////////////////
EnemyOni::EnemyOni(float x, float y) :BaseEnemy("img/enemy/oni.png") {
	x_ = x;
	y_ = y;
	radius_ = 60;
	speed_ = 1;
}

void EnemyOni::Update(int player_x, int player_y, int cnt) {
	x_ += speed_;
	y_ += speed_;
}