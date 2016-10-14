#include "enemy.h"

////////////////////////////////////   —H—ì   ////////////////////////////////////
EnemyYurei::EnemyYurei(float x, float y) :BaseEnemy("img/enemy/yurei.png") {
	x_ = x;
	y_ = y;
	radius_ = 25;
	speed_ = 200;
}

void EnemyYurei::Update(int player_x, int player_y, int cnt) {
	x_ = speed_ * sinf((cnt/4.0)*DX_PI_F / 180) + 200;
	y_ = speed_ * cosf((3.0*cnt / 4.0) * DX_PI_F / 180) + 200;
}

////////////////////////////////////   ‰ì‹S   ////////////////////////////////////
EnemyGaki::EnemyGaki(float x, float y) :BaseEnemy("img/enemy/gaki.png") {
	x_ = x;
	y_ = y;
	radius_ = 25;
	speed_ = 1;
}

void EnemyGaki::Update(int player_x, int player_y, int cnt) {
	if (abs(player_x - x_) < 30 || abs(player_y - y_) < 30) {
		if (abs(player_x - x_) < 30) {
			if (player_y < y_) y_ -= 0.5;
			else y_ += 1;
		}
		if (abs(player_y - y_) < 30) {
			if (player_x < x_) x_ -= 0.5;
			else x_ += 1;
		}
	}
	else {
		x_ += sinf(cnt * DX_PI_F / 180) + sinf((cnt - 1) * DX_PI_F / 180);
		y_ += cosf(cnt * 3 * DX_PI_F / 180) + cosf((cnt - 1) * 3 * DX_PI_F / 180);
	}
}

////////////////////////////////////   ‚ª‚µ‚á‚Ç‚­‚ë   ////////////////////////////////////
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

////////////////////////////////////   ‘Â“Vg   ////////////////////////////////////
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

////////////////////////////////////   è…–‚‘å‰¤   ////////////////////////////////////
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

////////////////////////////////////   ‹S   ////////////////////////////////////
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