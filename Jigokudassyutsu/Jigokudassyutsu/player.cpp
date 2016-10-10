#include "player.h"

//コンストラクタ
Player::Player() :kPlayerRadius(3) {
}

//デストラクタ
Player::~Player() {
}

//初期化
void Player::Initialize() {
	if (LoadDivGraph("img/player/player.png", kPlayerImgNum, kPlayerImgNum, 1, 32, 32, player_img_) == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "プレイヤー画像読み込み失敗");
	player_img_cnt_ = 0;
	cnt_ = 0;
}

//更新
//引数:プレイヤー座標を格納する整数型
void Player::Update(int *x, int *y) {
	//プレイヤー画像を進める
	cnt_++;
	if (cnt_ % 10 == 0)
		player_img_cnt_ = (player_img_cnt_ + 1) % kPlayerImgNum;
	//プレイヤー座標を代入を代入
	GetMousePoint(&x_, &y_);
	*x = x_;
	*y = y_;
	//カーソル無効
	ShowCursor(false);
}

//描画
void Player::Draw()const {
	DrawRotaGraph(x_, y_, 1.0, 0.0, player_img_[player_img_cnt_], TRUE);
}

//終了処理
void Player::Finalize() {
	for (int i = 0; i < kPlayerImgNum; i++)
		DeleteGraph(player_img_[i]);
}