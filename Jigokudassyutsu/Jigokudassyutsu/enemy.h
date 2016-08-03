#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMY_H_

#include <string>
#include "DxLib.h"
#include "base_enemy.h"

//�H��
class EnemyYurei :public BaseEnemy {
public:
	EnemyYurei(float x,float y);
	void Update(int player_x, int player_y) override;
};

//��S
class EnemyGaki :public BaseEnemy {
public:
	EnemyGaki(float x, float y);
	void Update(int player_x, int player_y) override;
};

//������ǂ���
class EnemyDokuro :public BaseEnemy {
public:
	EnemyDokuro(float x, float y);
	void Update(int player_x, int player_y) override;
};

//�V�g
class EnemyDatenshi :public BaseEnemy {
public:
	EnemyDatenshi(float x, float y);
	void Update(int player_x, int player_y) override;
};

//腖��剤
class EnemyEnma :public BaseEnemy {
public:
	EnemyEnma(float x, float y);
	void Update(int player_x, int player_y) override;
};

//�S
class EnemyOni :public BaseEnemy {
public:
	EnemyOni(float x, float y);
	void Update(int player_x, int player_y) override;
};


#endif