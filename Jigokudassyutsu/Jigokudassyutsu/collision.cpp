#include "collision.h"

CollisionRoad::CollisionRoad(int stage_num) :stage_num_(stage_num) {
}

CollisionRoad::~CollisionRoad() {
}

void CollisionRoad::Initialize() {
	col_map_ = cv::imread("img/collision/test_road.png", cv::IMREAD_UNCHANGED);
//#define COLLISION_OUTPUT//�d������̂ŃR�����g�A�E�g���Ă���
#ifdef COLLISION_OUTPUT
	std::ofstream ofs("testtest.txt");//testtest.txt���J��
	for (int y = 0; y < col_map_.rows; ++y) {//���s�N�Z����480
		for (int x = 0; x < col_map_.cols; ++x) {//�c�s�N�Z����640�@�@�@�@
			for (int c = 0; c < col_map_.channels(); ++c) {//�`�����l����(rgba��4��)
				ofs << (int)col_map_.data[y * col_map_.step + x * col_map_.elemSize() + c] << ' ';//testtest.txt��data��S�ďo��
			}
			ofs << std::endl;//���s
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