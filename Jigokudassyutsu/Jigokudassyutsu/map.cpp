#include "map.h"

//�R���X�g���N�^
Map::Map(int stage_num) :stage_num_(stage_num){
}

//�f�X�g���N�^
Map::~Map() {
}

//������
void Map::Initialize() {
}

//�X�V
void Map::Update() {
}

//�`��
void Map::Draw()const {
	DrawString(0, 60, "�}�b�v", GetColor(255, 255, 255));
}

//�I������
void Map::Finalize() {
}