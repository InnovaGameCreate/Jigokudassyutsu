#include "enemy.h"

////////////////////////////////////   幽霊   ////////////////////////////////////
EnemyYurei::EnemyYurei(float x, float y) :BaseEnemy("img/enemy/yurei.png") {
	x_ = x;
	y_ = y;
	radius_ = 25;
	speed_ = 200;
}

void EnemyYurei::Update(int player_x, int player_y, int cnt) {
	x_ = speed_ * sinf((cnt / 4.0)*DX_PI_F / 180) + 200;
	y_ = speed_ * cosf((3.0*cnt / 4.0) * DX_PI_F / 180) + 200;
}

////////////////////////////////////   餓鬼   ////////////////////////////////////
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

////////////////////////////////////   がしゃどくろ   ////////////////////////////////////
EnemyDokuro::EnemyDokuro(float x, float y) :BaseEnemy("img/enemy/dokuro.png") {
	x_ = x;
	y_ = y;
	radius_ = 25;
	speed_ = 0.5;
	is_compute_frame = true;
}

void EnemyDokuro::Update(int player_x, int player_y, int cnt) {
	//乱数で更新
	if (is_compute_frame) {
		tmp_rand_x = util::GetRandom(0, kWindowWidth);
		tmp_rand_y = util::GetRandom(0, kWindowHeight);
		is_compute_frame = false;
	}
	//一定時間で更新フラグを立てる
	if (cnt % 300 == 0) {
		is_compute_frame = true;
	}

	//乱数座標に向けて移動
	if (x_ > tmp_rand_x)
		x_ -= speed_;
	else if (x_ < tmp_rand_x)
		x_ += speed_;
	else
		is_compute_frame = true;
	if (y_ > tmp_rand_y)
		y_ -= speed_;
	else if (y_ < tmp_rand_y)
		y_ += speed_;
	else
		is_compute_frame = true;
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