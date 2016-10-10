#include "player.h"

//�R���X�g���N�^
Player::Player() :kPlayerRadius(3) {
}

//�f�X�g���N�^
Player::~Player() {
}

//������
void Player::Initialize() {
	if (LoadDivGraph("img/player/player.png", kPlayerImgNum, kPlayerImgNum, 1, 32, 32, player_img_) == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�v���C���[�摜�ǂݍ��ݎ��s");
	player_img_cnt_ = 0;
	cnt_ = 0;
}

//�X�V
//����:�v���C���[���W���i�[���鐮���^
void Player::Update(int *x, int *y) {
	//�v���C���[�摜��i�߂�
	cnt_++;
	if (cnt_ % 10 == 0)
		player_img_cnt_ = (player_img_cnt_ + 1) % kPlayerImgNum;
	//�v���C���[���W��������
	GetMousePoint(&x_, &y_);
	*x = x_;
	*y = y_;
	//�J�[�\������
	ShowCursor(false);
}

//�`��
void Player::Draw()const {
	DrawRotaGraph(x_, y_, 1.0, 0.0, player_img_[player_img_cnt_], TRUE);
}

//�I������
void Player::Finalize() {
	for (int i = 0; i < kPlayerImgNum; i++)
		DeleteGraph(player_img_[i]);
}