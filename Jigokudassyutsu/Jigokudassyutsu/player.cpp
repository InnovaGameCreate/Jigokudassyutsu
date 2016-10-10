#include "player.h"

//コンストラクタ
Player::Player() :kPlayerRadius(3) {
}

//デストラクタ
Player::~Player() {
}

//初期化
void Player::Initialize() {
	player_img_ = LoadGraph("img/player/player.png");
	if (player_img_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "プレイヤー画像読み込み失敗");
}

//更新
//引数:プレイヤー座標を格納する整数型
void Player::Update(int *x, int *y) {
	GetMousePoint(&x_, &y_);//プレイヤー座標を代入を代入
	*x = x_;
	*y = y_;
	ShowCursor(false);
}

//描画
void Player::Draw()const {
	DrawRotaGraph(x_, y_, 1.0, 0.0, player_img_, TRUE);
}

//終了処理
void Player::Finalize() {
	DeleteGraph(player_img_);
}