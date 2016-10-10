#include "player.h"

//�R���X�g���N�^
Player::Player() :kPlayerRadius(3) {
}

//�f�X�g���N�^
Player::~Player() {
}

//������
void Player::Initialize() {
	player_img_ = LoadGraph("img/player/player.png");
	if (player_img_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�v���C���[�摜�ǂݍ��ݎ��s");
}

//�X�V
//����:�v���C���[���W���i�[���鐮���^
void Player::Update(int *x, int *y) {
	GetMousePoint(&x_, &y_);//�v���C���[���W��������
	*x = x_;
	*y = y_;
	ShowCursor(false);
}

//�`��
void Player::Draw()const {
	DrawRotaGraph(x_, y_, 1.0, 0.0, player_img_, TRUE);
}

//�I������
void Player::Finalize() {
	DeleteGraph(player_img_);
}