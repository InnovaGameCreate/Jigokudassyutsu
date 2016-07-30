#ifndef JIGOKUDASSYUTSU_ENEMY_BASEENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_BASEENEMY_H_

#include <string>
#include "DxLib.h"
#include "task.h"
#include "util.h"

class BaseEnemy {
private:
	int img_handle_;
protected:
	float x_, y_;
	float speed_;
	float radius_;

	void Initialize();
public:
	BaseEnemy(std::string img_pass);
	BaseEnemy(int img_handle);
	virtual ~BaseEnemy();
	virtual void Update(int player_x, int player_y) = 0;//更新は派生クラスで定義する
	void Draw()const;
	void Finalize();
};

#endif