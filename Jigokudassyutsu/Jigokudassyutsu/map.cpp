#include "map.h"

//コンストラクタ
Map::Map(int stage_num) :kStageNum(stage_num){
}

//デストラクタ
Map::~Map() {
}

//初期化
void Map::Initialize() {
	char image_path[48];
	sprintf_s(image_path, "img/map/%d.jpg", kStageNum);
	map_image_ = LoadGraph(image_path);

	if (map_image_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "読み込めませんでした。");
}

//更新
void Map::Update() {
}

//描画
void Map::Draw()const {
	DrawString(0, 60, "マップ", GetColor(255, 255, 255));
	DrawRotaGraph(320, 240, 1.0, 0, map_image_, FALSE);
}

//終了処理
void Map::Finalize() {
	DeleteGraph(map_image_);
}