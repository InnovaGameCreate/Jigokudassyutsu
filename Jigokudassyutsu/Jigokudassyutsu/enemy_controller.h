#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMYCONTROLLER_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMYCONTROLLER_H_

#include "task.h"
#include "DxLib.h"

class EnemyController :public Task {
private:
	const int stage_num_;
public:
	EnemyController(int stage_num);
	~EnemyController();
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw()const  override;
};

#endif