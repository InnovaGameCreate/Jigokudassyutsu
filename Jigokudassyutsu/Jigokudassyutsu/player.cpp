#include "player.h"

//�R���X�g���N�^
Player::Player() {
}

//�f�X�g���N�^
Player::~Player() {
}

//������
void Player::Initialize() {
}

//�X�V
void Player::Update() {
}

//�`��
void Player::Draw()const {
	DrawString(0, 80, "�v���C���[", GetColor(255, 255, 255));
	
	HCURSOR hCursor;
	hCursor = LoadCursorFromFile("Mario.cur");
	SetCursor(hCursor);
}

//�I������
void Player::Finalize() {
}