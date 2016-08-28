#include "base_enemy.h"

//コンストラクタ
BaseEnemy::BaseEnemy(std::string  img_pass) {
	Initialize();
	//画像ロード
	img_handle_ = LoadGraph(img_pass.c_str());
	if (img_handle_ == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "画像" + img_pass + "の読み込みに失敗しました");
	}
}

BaseEnemy::BaseEnemy(int img_handle) {
	Initialize();
	//画像ロード
	img_handle_ = img_handle;
	if (img_handle_ == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "画像ハンドルが無効です");
	}
}

//デストラクタ
BaseEnemy::~BaseEnemy() {
}

//初期化
void BaseEnemy::Initialize() {
	x_ = y_ = 0.0f;
	speed_ = 0.0f;
	radius_ = 0.0f;
	cnt_ = 0;
}

//プレイヤーとの当たり判定
bool BaseEnemy::IsCollision(float px, float py, float pr) {
	if (util::CircleCollision(px, py, pr, x_, y_, radius_))
		return true;
	return false;
}

//描画
void BaseEnemy::Draw()const {
	if (img_handle_ == -1)
		return;
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawRotaGraph(x_, y_, 1, 0, img_handle_, TRUE);
	SetDrawMode(DX_DRAWMODE_NEAREST);
#ifdef _DEBUG
	//当たり判定領域を描画
	DrawCircle(x_, y_, radius_, GetColor(255, 0, 0), FALSE);
#endif
}

//終了処理
void BaseEnemy::Finalize() {
	DeleteGraph(img_handle_);
}