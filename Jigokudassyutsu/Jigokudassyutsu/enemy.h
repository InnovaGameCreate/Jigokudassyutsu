#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMY_H_

#include <string>
#include <math.h>
#include "util.h"
#include "DxLib.h"
#include "base_enemy.h"
#include "define.h"

//�H��
class EnemyYurei :public BaseEnemy {
public:
	EnemyYurei(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//��S
class EnemyGaki :public BaseEnemy {
public:
	EnemyGaki(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//������ǂ���
class EnemyDokuro :public BaseEnemy {
private:
	int tmp_rand_x, tmp_rand_y;//�����ɂ��ڕW���W
	bool is_compute_frame;//�v�Z�t���O
public:
	EnemyDokuro(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//�V�g
class EnemyDatenshi :public BaseEnemy {
public:
	EnemyDatenshi(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//腖��剤
class EnemyEnma :public BaseEnemy {
public:
	EnemyEnma(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//�S
class EnemyOni :public BaseEnemy {
public:
	EnemyOni(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};


#endif