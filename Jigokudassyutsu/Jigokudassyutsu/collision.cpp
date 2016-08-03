#include "collision.h"

CollisionRoad::CollisionRoad(int stage_num) :stage_num_(stage_num) {
}

CollisionRoad::~CollisionRoad() {
}

void CollisionRoad::Initialize() {
	col_map_ = cv::imread("img/collision/test_road.png", cv::IMREAD_UNCHANGED);
//#define COLLISION_OUTPUT//重すぎるのでコメントアウトしておく
#ifdef COLLISION_OUTPUT
	std::ofstream ofs("testtest.txt");//testtest.txtを開く
	for (int y = 0; y < col_map_.rows; ++y) {//横ピクセル数480
		for (int x = 0; x < col_map_.cols; ++x) {//縦ピクセル数640　　　　
			for (int c = 0; c < col_map_.channels(); ++c) {//チャンネル数(rgbaの4つ)
				ofs << (int)col_map_.data[y * col_map_.step + x * col_map_.elemSize() + c] << ' ';//testtest.txtにdataを全て出力
			}
			ofs << std::endl;//改行
		}
		ofs << std::endl;
		ofs << std::endl;
	}
#endif
}

void CollisionRoad::Finalize() {
}

bool CollisionRoad::Update(float x, float y, float radius) {
	return false;
}

void CollisionRoad::Draw()const {
}