#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMYCONTROLLER_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMYCONTROLLER_H_

#include <vector>
#include "task.h"
#include "DxLib.h"
#include "enemy.h"

class EnemyController{
private:
	const int kStageNum;
	std::vector<BaseEnemy*> vec_enemy;	//“G
public:
	EnemyController(int stage_num,int map_widht,int map_height);
	~EnemyController();
	void Initialize();
	void Finalize();
	bool Update(float player_x, float player_y, float player_radius);
	void Draw()const;

	const int kMapWidth, kMapHeight;
};

#endif