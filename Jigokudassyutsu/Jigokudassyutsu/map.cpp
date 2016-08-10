#include "map.h"

//�R���X�g���N�^
Map::Map(int stage_num) :stage_num_(stage_num){
}

//�f�X�g���N�^
Map::~Map() {
}

//������
void Map::Initialize() {
	char image_path[48];
	sprintf_s(image_path, "back_image%d.jpg", stage_num_);
	map_image_ = LoadGraph(image_path);

	if (map_image_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�ǂݍ��߂܂���ł����B");
}

//�X�V
void Map::Update() {
}

//�`��
void Map::Draw()const {
	DrawString(0, 60, "�}�b�v", GetColor(255, 255, 255));
	DrawRotaGraph(320, 240, 1.0, 0, map_image_, FALSE);
}

//�I������
void Map::Finalize() {
	DeleteGraph(map_image_);
}