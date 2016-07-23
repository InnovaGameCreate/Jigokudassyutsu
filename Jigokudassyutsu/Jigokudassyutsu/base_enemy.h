#ifndef JIGOKUDASSYUTSU_ENEMY_BASEENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_BASEENEMY_H_

#include <string>
#include "DxLib.h"
#include "task.h"
#include "util.h"

class BaseEnemy :public Task {
private:
	int img_handle_;
protected:
	float x_, y_;
	float speed_;
public:
	BaseEnemy(std::string img_pass);
	~BaseEnemy();
	void Initialize() override;
	virtual void Update(int player_x, int player_y) = 0;//更新は派生クラスで定義する
	void Draw()const override;
	void Finalize() override;
};

#endif