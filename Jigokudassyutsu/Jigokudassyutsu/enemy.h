#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMY_H_

#include <string>
#include <math.h>
#include "util.h"
#include "DxLib.h"
#include "base_enemy.h"
#include "define.h"

//—H—ì
class EnemyYurei :public BaseEnemy {
public:
	EnemyYurei(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//‰ì‹S
class EnemyGaki :public BaseEnemy {
public:
	EnemyGaki(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//‚ª‚µ‚á‚Ç‚­‚ë
class EnemyDokuro :public BaseEnemy {
private:
	int tmp_rand_x_, tmp_rand_y_;//—”‚É‚æ‚é–Ú•WÀ•W
	bool is_compute_frame_;//ŒvZƒtƒ‰ƒO
public:
	EnemyDokuro(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//‘Â“Vg
class EnemyDatenshi :public BaseEnemy {
private:
	float x_movement_;//xˆÚ“®—Ê
	float y_movement_;//yˆÚ“®—Ê
	int compute_frame_num_;//ŒvZƒtƒ‰ƒO
public:
	EnemyDatenshi(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//è…–‚‘å‰¤
class EnemyEnma :public BaseEnemy {
private:
	float speed_amount_of_change_;//”¼Œa•Ï‰»—Ê
public:
	EnemyEnma(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//‹S
class EnemyOni :public BaseEnemy {
private:
	float x_movement_;//xˆÚ“®—Ê
	float y_movement_;//yˆÚ“®—Ê
public:
	EnemyOni(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};


#endif