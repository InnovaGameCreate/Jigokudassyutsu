#include "map.h"

//コンストラクタ
Map::Map(int stage_num) :stage_num_(stage_num){
}

//デストラクタ
Map::~Map() {
}

//初期化
void Map::Initialize() {
	map_image = LoadGraph("back_image1.jpg");
}

//更新
void Map::Update() {
}

//描画
void Map::Draw()const {
	DrawString(0, 60, "マップ", GetColor(255, 255, 255));

	if (stage_num_ == 1)
		DrawRotaGraph(320, 240, 1.0, 0, map_image, FALSE);
	else if (stage_num_ == 2)
		DrawRotaGraph(320, 240, 1.0, 0, map_image, FALSE);
	else if (stage_num_ == 3)
		DrawRotaGraph(320, 240, 1.0, 0, map_image, FALSE);
	else if (stage_num_ == 4)
		DrawRotaGraph(320, 240, 1.0, 0, map_image, FALSE);
	else if (stage_num_ == 5)
		DrawRotaGraph(320, 240, 1.0, 0, map_image, FALSE);
}

//終了処理
void Map::Finalize() {
	DeleteGraph(map_image);
}