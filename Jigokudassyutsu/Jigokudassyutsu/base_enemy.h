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
	~BaseEnemy();
	virtual void Update(int player_x, int player_y) = 0;//�X�V�͔h���N���X�Œ�`����
	void Draw()const;
	void Finalize();
};

#endif