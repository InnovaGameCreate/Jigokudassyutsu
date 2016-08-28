#include "enemy_controller.h"

//�R���X�g���N�^
EnemyController::EnemyController(int stage_num, int map_widht, int map_height) :
	kStageNum(stage_num),
	kMapWidth(map_widht),
	kMapHeight(map_height)
{
}

//�f�X�g���N�^
EnemyController::~EnemyController() {
}

//������
void EnemyController::Initialize() {
	switch (kStageNum) {
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
bool EnemyController::Update(float player_x, float player_y, float player_radius) {
	bool is_collsion = false;
	for (auto itr = vec_enemy.begin(); itr != vec_enemy.end(); itr++) {
		(*itr)->Count();//�J�E���^
		(*itr)->Update(player_x, player_y, (*itr)->get_cnt_());//�X�V
		if ((*itr)->IsCollision(player_x, player_y, player_radius) == true)//�v���C���[�Ƃ̓����蔻��
			is_collsion = true;
	}
	return is_collsion;
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