#include "map.h"

//�R���X�g���N�^
Map::Map(int stage_num) :stage_num_(stage_num){
}

//�f�X�g���N�^
Map::~Map() {
}

//������
void Map::Initialize() {
	map_image = LoadGraph("back_image1.jpg");
}

//�X�V
void Map::Update() {
}

//�`��
void Map::Draw()const {
	DrawString(0, 60, "�}�b�v", GetColor(255, 255, 255));

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

//�I������
void Map::Finalize() {
	DeleteGraph(map_image);
}