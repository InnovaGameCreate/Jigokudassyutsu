#include "enemy_controller.h"

//�R���X�g���N�^
EnemyController::EnemyController(int stage_num) :stage_num_(stage_num){
}

//�f�X�g���N�^
EnemyController::~EnemyController() {
}

//������
void EnemyController::Initialize() {
}

//�X�V
void EnemyController::Update() {
}

//�`��
void EnemyController::Draw()const {
	DrawString(0, 100, "�G", GetColor(255, 255, 255));
}

//�I������
void EnemyController::Finalize() {
}