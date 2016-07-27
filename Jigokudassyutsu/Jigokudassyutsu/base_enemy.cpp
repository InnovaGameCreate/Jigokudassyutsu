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

//デストラクタ
BaseEnemy::~BaseEnemy() {

}

//初期化
void BaseEnemy::Initialize() {
	x_ = y_ = 0.0f;
	speed_ = 0.0f;
	radius_ = 0.0f;
}

//描画
void BaseEnemy::Draw()const {
	if (img_handle_ == -1)
		return;
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawGraphF(x_, y_, img_handle_, TRUE);
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

//終了処理
void BaseEnemy::Finalize() {
	DeleteGraph(img_handle_);
}