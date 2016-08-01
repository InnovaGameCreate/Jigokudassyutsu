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
		//�H��*1
		vec_enemy.push_back(new EnemyYurei(100, 100));
		break;
	case 2:
		//��S*2
		vec_enemy.push_back(new EnemyGaki(100, 100));
		vec_enemy.push_back(new EnemyGaki(200, 100));
		break;
	case 3:
		//������ǂ���*3
		vec_enemy.push_back(new EnemyDokuro(100, 100));
		vec_enemy.push_back(new EnemyDokuro(200, 100));
		vec_enemy.push_back(new EnemyDokuro(300, 100));
		break;
	case 4:
		//�V�g*3
		vec_enemy.push_back(new EnemyDatenshi(100, 100));
		vec_enemy.push_back(new EnemyDatenshi(200, 100));
		vec_enemy.push_back(new EnemyDatenshi(300, 100));
		break;
	case 5:
		//腖��剤
		vec_enemy.push_back(new EnemyEnma(100, 100));
		//�S*2
		vec_enemy.push_back(new EnemyOni(200, 100));
		vec_enemy.push_back(new EnemyOni(300, 100));
		break;
	default:
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "���̃X�e�[�W�͐ݒ肳��Ă��܂���");
		break;
	}
}

//�X�V
void EnemyController::Update(float player_x, int player_y) {
	for (auto itr = vec_enemy.begin(); itr != vec_enemy.end(); itr++) {
		(*itr)->Update(player_x, player_y);
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