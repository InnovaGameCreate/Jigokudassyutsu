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
	is_compute_frame_ = true;
}

void EnemyDokuro::Update(int player_x, int player_y, int cnt) {
	//乱数で更新
	if (is_compute_frame_) {
		tmp_rand_x_ = util::GetRandom(0, kWindowWidth);
		tmp_rand_y_ = util::GetRandom(0, kWindowHeight);
		is_compute_frame_ = false;
	}
	//一定時間で更新フラグを立てる
	if (cnt % 300 == 0) {
		is_compute_frame_ = true;
	}

	//乱数座標に向けて移動
	if (x_ > tmp_rand_x_)
		x_ -= speed_;
	else if (x_ < tmp_rand_x_)
		x_ += speed_;
	else
		is_compute_frame_ = true;
	if (y_ > tmp_rand_y_)
		y_ -= speed_;
	else if (y_ < tmp_rand_y_)
		y_ += speed_;
	else
		is_compute_frame_ = true;
}

////////////////////////////////////   堕天使   ////////////////////////////////////
EnemyDatenshi::EnemyDatenshi(float x, float y) :BaseEnemy("img/enemy/datenshi.png") {
	x_ = x;
	y_ = y;
	radius_ = 40;
	speed_ = 1;
	x_movement_ = speed_;
	y_movement_ = speed_;
	compute_frame_num_ = 210;
}

void EnemyDatenshi::Update(int player_x, int player_y, int cnt) {
	//円の計算
	x_ += 100 * (cos(cnt / 100.0) - cos((cnt - 1) / 100.0));
	y_ += 100 * (sin(cnt / 100.0) - sin((cnt - 1) / 100.0));
	//直線を足す
	if (cnt%compute_frame_num_ == 0) {
		x_movement_ = -x_movement_;
		y_movement_ = -y_movement_;
	}
	if (x_ >= kWindowWidth)
		x_movement_ = -speed_;
	else if (x_ <= 0)
		x_movement_ = speed_;
	if (y_ >= kWindowHeight)
		y_movement_ = -speed_;
	else if (y_ <= 0)
		y_movement_ = speed_;
	x_ += x_movement_;
	y_ += y_movement_;

}

////////////////////////////////////   閻魔大王   ////////////////////////////////////
EnemyEnma::EnemyEnma(float x, float y) :BaseEnemy("img/enemy/enma.png") {
	x_ = x;
	y_ = y;
	radius_ = 45;
	speed_ = 5;
	speed_amount_of_change_ = 0.2;
}

void EnemyEnma::Update(int player_x, int player_y, int cnt) {
	//円の計算
	x_ += speed_ * (cos(cnt / 100.0) - cos((cnt - 1) / 100.0));
	y_ += speed_ * (sin(cnt / 100.0) - sin((cnt - 1) / 100.0));
	//半径変化量計算
	if (speed_ < 8)
		speed_amount_of_change_ = 0.2;
	if (speed_>280)
		speed_amount_of_change_ = -0.2;
	//半径変化
	speed_ += speed_amount_of_change_;
}

////////////////////////////////////   鬼   ////////////////////////////////////
EnemyOni::EnemyOni(float x, float y) :BaseEnemy("img/enemy/oni.png") {
	x_ = x;
	y_ = y;
	radius_ = 40;
	speed_ = 1.2;
	//乱数で初期方向を決める
	x_movement_ = speed_;
	if (util::GetRandom(0, 1))
		x_movement_ *= -1;
	y_movement_ = speed_;
	if (util::GetRandom(0, 1))
		y_movement_ *= -1;
}

void EnemyOni::Update(int player_x, int player_y, int cnt) {
	if (x_ >= kWindowWidth)
		x_movement_ = -speed_;
	else if (x_ <= 0)
		x_movement_ = speed_;
	if (y_ >= kWindowHeight)
		y_movement_ = -speed_;
	else if (y_ <= 0)
		y_movement_ = speed_;
	x_ += x_movement_;
	y_ += y_movement_;
}