#include "base_enemy.h"

//�R���X�g���N�^
BaseEnemy::BaseEnemy(std::string  img_pass) {
	Initialize();
	//�摜���[�h
	img_handle_ = LoadGraph(img_pass.c_str());
	if (img_handle_ == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�摜" + img_pass + "�̓ǂݍ��݂Ɏ��s���܂���");
	}
}

//�f�X�g���N�^
BaseEnemy::~BaseEnemy() {

}

//������
void BaseEnemy::Initialize() {
	x_ = y_ = 0.0f;
	speed_ = 0.0f;
	radius_ = 0.0f;
}

//�`��
void BaseEnemy::Draw()const {
	if (img_handle_ == -1)
		return;
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawGraphF(x_, y_, img_handle_, TRUE);
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

//�I������
void BaseEnemy::Finalize() {
	DeleteGraph(img_handle_);
}