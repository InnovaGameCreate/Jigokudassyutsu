#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMYCONTROLLER_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMYCONTROLLER_H_

#include <vector>
#include "task.h"
#include "DxLib.h"
#include "enemy.h"

class EnemyController :public Task {
private:
	const int stage_num_;
	std::vector<BaseEnemy*> vec_enemy;	//“G
public:
	EnemyController(int stage_num);
	~EnemyController();
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw()const  override;
};

#endif