#include "map.h"

//コンストラクタ
Map::Map(int stage_num) :stage_num_(stage_num){
}

//デストラクタ
Map::~Map() {
}

//初期化
void Map::Initialize() {
}

//更新
void Map::Update() {
}

//描画
void Map::Draw()const {
	DrawString(0, 60, "マップ", GetColor(255, 255, 255));
}

//終了処理
void Map::Finalize() {
}