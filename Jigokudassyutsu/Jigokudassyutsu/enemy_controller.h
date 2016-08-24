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
	int cnt_;
public:
	EnemyController(int stage_num,int map_widht,int map_height);
	~EnemyController();
	void Initialize() override;
	void Finalize() override;
	bool Update(float player_x, float player_y, float player_radius);
	void Update() {}//åpè≥ÇµÇΩUpdateÇÕâΩÇ‡ÇµÇ»Ç¢
	void Draw()const  override;

	const int kMapWidth, kMapHeight;
};

#endif