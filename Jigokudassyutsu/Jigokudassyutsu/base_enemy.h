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
	virtual void Update(int player_x, int player_y,int cnt) = 0;//�X�V�͔h���N���X�Œ�`����
	bool IsCollision(float px, float py, float pr);//�v���C���[�ƐڐG���Ă����true��Ԃ�
	void Draw()const;
	void Finalize();
};

#endif