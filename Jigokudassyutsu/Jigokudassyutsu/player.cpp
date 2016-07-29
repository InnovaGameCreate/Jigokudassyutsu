#include "player.h"

//コンストラクタ
Player::Player() {
}

//デストラクタ
Player::~Player() {
}

//初期化
void Player::Initialize() {
	h_cursor_ = LoadCursorFromFile("Mario.cur");
}

//更新
void Player::Update() {
	SetCursor(h_cursor_);
}

//描画
void Player::Draw()const {
	DrawString(0, 80, "プレイヤー", GetColor(255, 255, 255));
}

//終了処理
void Player::Finalize() {
}