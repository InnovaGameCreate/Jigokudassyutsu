#ifndef JIGOKUDASSYUTSU_PLAYER_PLAYER_H_
#define JIGOKUDASSYUTSU_PLAYER_PLAYER_H_

#include "task.h"
#include "DxLib.h"
#include "util.h"

class Player {
private:
	int player_img_;
	int x_;
	int y_;
public:
	Player();
	~Player();
	void Initialize();
	void Finalize();
	void Update(int *x, int *y);//xy�͌��݂̃v���C���[���S�ʒu���i�[���鐮���|�C���^
	void Draw()const;

	const int kPlayerRadius = 10;//�v���C���[�̔��a
};

#endif