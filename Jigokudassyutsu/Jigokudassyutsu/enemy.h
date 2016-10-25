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
	int tmp_rand_x_, tmp_rand_y_;//乱数による目標座標
	bool is_compute_frame_;//計算フラグ
public:
	EnemyDokuro(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//堕天使
class EnemyDatenshi :public BaseEnemy {
private:
	float x_movement_;//x移動量
	float y_movement_;//y移動量
	int compute_frame_num_;//計算フラグ
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
private:
	float x_movement_;//x移動量
	float y_movement_;//y移動量
public:
	EnemyOni(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};


#endif