#include "enemy.h"

//�R���X�g���N�^
Enemy::Enemy(int stage_num) :stage_num_(stage_num){
}

//�f�X�g���N�^
Enemy::~Enemy() {
}

//������
void Enemy::Initialize() {
}

//�X�V
void Enemy::Update() {
}

//�`��
void Enemy::Draw()const {
	DrawString(0, 100, "�G", GetColor(255, 255, 255));
}

//�I������
void Enemy::Finalize() {
}