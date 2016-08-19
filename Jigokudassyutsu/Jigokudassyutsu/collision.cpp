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
	//�����蔻��p�̉摜�ǂݍ���
	col_map_ = cv::imread("img/collision/" + std::to_string(kStageNum) + ".png", cv::IMREAD_UNCHANGED);
	//�G���[����
	if (col_map_.data == NULL) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�摜�̓ǂݍ��݂Ɏ��s");
		exit(1);
	}
	if (col_map_.channels() != 4)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�A���t�@�`�����l���t���̉摜�ł͂���܂���");
	if (col_map_.rows != kMapHeight || col_map_.cols != kMapWidth) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�摜�T�C�Y���s���ł�");
		exit(1);
	}
}

void CollisionRoad::Finalize() {
}

bool CollisionRoad::Update(float x, float y, float radius) {
	//���S�𒲍�
	if (IsColMapAlpha(x, y) == true)
		return true;
	//�����8�_�𒲍�
	for (double t = 0; t <= DX_PI*2.0; t += DX_PI / 4.0) {
		if (IsColMapAlpha(radius*sin(t) + x, radius*cos(t)) + y == true) {
			return true;
		}
	}
	return false;
}

void CollisionRoad::Draw()const {
}

inline bool CollisionRoad::IsColMapAlpha(int x, int y) {
	if (x<0 || x>kMapWidth || y<0 || y>kMapHeight) {
		return false;
	}
	if (col_map_.data[y * col_map_.step + x * col_map_.elemSize() + 3] == 0)
		return true;
	return false;
}