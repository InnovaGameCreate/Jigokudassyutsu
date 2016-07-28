#include "player.h"

//コンストラクタ
Player::Player() {
}

//デストラクタ
Player::~Player() {
}

//初期化
void Player::Initialize() {
}

//更新
void Player::Update() {
}

//描画
void Player::Draw()const {
	DrawString(0, 80, "プレイヤー", GetColor(255, 255, 255));
	
	HCURSOR hCursor;
	hCursor = LoadCursorFromFile("Mario.cur");
	SetCursor(hCursor);
}

//終了処理
void Player::Finalize() {
}