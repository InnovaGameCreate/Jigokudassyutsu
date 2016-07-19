#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMY_H_

#include "task.h"
#include "DxLib.h"

class Enemy :public Task {
private:
	const int stage_num_;
public:
	Enemy(int stage_num);
	~Enemy();
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw()const  override;
};

#endif