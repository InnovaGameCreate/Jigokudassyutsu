#include "collision.h"

CollisionRoad::CollisionRoad(int stage_num) :stage_num_(stage_num) {
}

CollisionRoad::~CollisionRoad() {
}

void CollisionRoad::Initialize() {
	col_map_ = cv::imread("img/collision/test_road.png", cv::IMREAD_UNCHANGED);
}

void CollisionRoad::Finalize() {
}

bool CollisionRoad::Update(float x, float y, float radius) {
	return false;
}

void CollisionRoad::Draw()const {
}