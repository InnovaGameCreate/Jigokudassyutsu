#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMY_H_

#include <string>
#include <math.h>
#include "util.h"
#include "DxLib.h"
#include "base_enemy.h"
#include "define.h"

//幽霊
class EnemyYurei :public BaseEnemy {
public:
	EnemyYurei(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//餓鬼
class EnemyGaki :public BaseEnemy {
public:
	EnemyGaki(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//がしゃどくろ
class EnemyDokuro :public BaseEnemy {
private:
	int tmp_rand_x, tmp_rand_y;//乱数による目標座標
	bool is_compute_frame;//計算フラグ
public:
	EnemyDokuro(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//堕天使
class EnemyDatenshi :public BaseEnemy {
public:
	EnemyDatenshi(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//閻魔大王
class EnemyEnma :public BaseEnemy {
public:
	EnemyEnma(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//鬼
class EnemyOni :public BaseEnemy {
public:
	EnemyOni(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};


#endif