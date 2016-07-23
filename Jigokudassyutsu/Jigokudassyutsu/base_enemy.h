#ifndef JIGOKUDASSYUTSU_ENEMY_BASEENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_BASEENEMY_H_

#include "task.h"

class BaseEnemy :public Task {
private:
protected:
	int x, y;
public:
	BaseEnemy();
	~BaseEnemy();
	void Initialize() override;
	virtual void Update() override = 0;//更新は派生クラスで定義する
	void Draw()const override;
	void Finalize() override;
};

#endif