#include "player.h"

//�R���X�g���N�^
Player::Player() {
}

//�f�X�g���N�^
Player::~Player() {
}

//������
void Player::Initialize() {
	h_cursor_ = LoadCursorFromFile("Mario.cur");
}

//�X�V
void Player::Update() {
	SetCursor(h_cursor_);
}

//�`��
void Player::Draw()const {
	DrawString(0, 80, "�v���C���[", GetColor(255, 255, 255));
}

//�I������
void Player::Finalize() {
}