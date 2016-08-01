#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMYCONTROLLER_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMYCONTROLLER_H_

#include <vector>
#include "task.h"
#include "DxLib.h"
#include "enemy.h"

class EnemyController :public Task {
private:
	const int stage_num_;
	std::vector<BaseEnemy*> vec_enemy;	//ìG
public:
	EnemyController(int stage_num);
	~EnemyController();
	void Initialize() override;
	void Finalize() override;
	void Update(float player_x,int player_y);
	void Update() {}//åpè≥ÇµÇΩUpdateÇÕâΩÇ‡ÇµÇ»Ç¢
	void Draw()const  override;
};

#endif