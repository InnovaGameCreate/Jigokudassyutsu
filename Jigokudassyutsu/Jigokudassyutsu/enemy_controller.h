#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMYCONTROLLER_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMYCONTROLLER_H_

#include <vector>
#include "task.h"
#include "DxLib.h"
#include "enemy.h"

class EnemyController :public Task {
private:
	const int kStageNum;
	std::vector<BaseEnemy*> vec_enemy;	//ìG
public:
	EnemyController(int stage_num);
	~EnemyController();
	void Initialize() override;
	void Finalize() override;
	bool Update(float player_x, float player_y, float player_size);
	void Update() {}//åpè≥ÇµÇΩUpdateÇÕâΩÇ‡ÇµÇ»Ç¢
	void Draw()const  override;
};

#endif