#include "enemy_controller.h"

//�R���X�g���N�^
EnemyController::EnemyController(int stage_num) :stage_num_(stage_num){
}

//�f�X�g���N�^
EnemyController::~EnemyController() {
}

//������
void EnemyController::Initialize() {
	vec_enemy.push_back(new EnemyYurei(100, 100));
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
		delete (*itr);
		itr = vec_enemy.erase(itr);
	}
}