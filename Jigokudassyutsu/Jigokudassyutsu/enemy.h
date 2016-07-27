#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMY_H_

#include <string>
#include "DxLib.h"
#include "base_enemy.h"

class EnemyYurei :public BaseEnemy {
public:
	EnemyYurei(float x,float y);
	~EnemyYurei();
	void Update(int player_x, int player_y) override;
};

#endif