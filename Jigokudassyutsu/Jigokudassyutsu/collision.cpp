#include "collision.h"

CollisionRoad::CollisionRoad(int stage_num, int map_width, int map_height) :
	kStageNum(stage_num),
	kMapWidth(map_width),
	kMapHeight(map_height)
{
}

CollisionRoad::~CollisionRoad() {
}

void CollisionRoad::Initialize() {
	//当たり判定用の画像読み込み
	col_map_ = cv::imread("img/collision/test_road2.png", cv::IMREAD_UNCHANGED);
	//エラー処理
	if (col_map_.data == NULL) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "画像の読み込みに失敗");
		exit(1);
	}
	if (col_map_.channels() != 4)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "アルファチャンネル付きの画像ではありません");
	if (col_map_.rows<0 || col_map_.rows>kMapHeight || col_map_.cols<0 || col_map_.cols>kMapWidth) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "画像サイズが不正です");
		col_map_width_ = 0;
		col_map_height_ = 0;
	}
	else {
		col_map_width_ = col_map_.cols;
		col_map_height_ = col_map_.rows;
	}
	//比率計算
	width_ratio_ = (double)col_map_width_ / kMapWidth;
	height_ratio_ = (double)col_map_height_ / kMapHeight;

	//以下後で削除
	//テスト画像
	test_handle_ = LoadGraph("img/collision/test_road.png");
}

void CollisionRoad::Finalize() {
}

bool CollisionRoad::Update(float x, float y, float radius) {
	int cx = x*width_ratio_;
	int cy = y*height_ratio_;
	if (IsColMapAlpha(cx, cy))
		return true;
	return false;
}

void CollisionRoad::Draw()const {
	DrawExtendGraph(0, 0, kMapWidth, kMapHeight, test_handle_, TRUE);
}

inline bool CollisionRoad::IsColMapAlpha(int x, int y) {
	if (x<0 || x>col_map_width_ || y<0 || y>col_map_height_) {
		return false;
	}
	if (col_map_.data[y * col_map_.step + x * col_map_.elemSize() + 3] == 0)
		return true;
	return false;
}