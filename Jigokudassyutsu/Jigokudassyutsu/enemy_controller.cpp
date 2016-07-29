#include "enemy_controller.h"

//�R���X�g���N�^
EnemyController::EnemyController(int stage_num) :stage_num_(stage_num){
}

//�f�X�g���N�^
EnemyController::~EnemyController() {
}

//������
void EnemyController::Initialize() {
	switch (stage_num_) {
	case 1:
		vec_enemy.push_back(new EnemyYurei(100, 100));//�H��
		break;
	default:
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "���̃X�e�[�W�͐ݒ肳��Ă��܂���");
		break;
	}
}

//�X�V
void EnemyController::Update() {
	for (auto itr = vec_enemy.begin(); itr != vec_enemy.end(); itr++) {
		(*itr)->Update(0, 0);
	}
}

//�`��
void EnemyController::Draw()const {
	for (auto itr = vec_enemy.begin(); itr != vec_enemy.end(); itr++) {
		(*itr)->Draw();
	}
}

//�I������
void EnemyController::Finalize() {
	//�G�폜
	for (auto itr = vec_enemy.begin(); itr != vec_enemy.end();) {
		(*itr)->Finalize();
		delete (*itr);
		itr = vec_enemy.erase(itr);
	}
}