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

BaseEnemy::BaseEnemy(int img_handle) {
	Initialize();
	//�摜���[�h
	img_handle_ = img_handle;
	if (img_handle_ == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�摜�n���h���������ł�");
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
	cnt_ = 0;
}

//�v���C���[�Ƃ̓����蔻��
bool BaseEnemy::IsCollision(float px, float py, float pr) {
	if (util::CircleCollision(px, py, pr, x_, y_, radius_))
		return true;
	return false;
}

//�`��
void BaseEnemy::Draw()const {
	if (img_handle_ == -1)
		return;
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawRotaGraph(x_, y_, 1, 0, img_handle_, TRUE);
	SetDrawMode(DX_DRAWMODE_NEAREST);
#ifdef _DEBUG
	//�����蔻��̈��`��
	DrawCircle(x_, y_, radius_, GetColor(255, 0, 0), FALSE);
#endif
}

//�I������
void BaseEnemy::Finalize() {
	DeleteGraph(img_handle_);
}