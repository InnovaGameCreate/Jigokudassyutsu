#ifndef JIGOKUDASSYUTSU_PLAYER_PLAYER_H_
#define JIGOKUDASSYUTSU_PLAYER_PLAYER_H_

#include "task.h"
#include "DxLib.h"
#include "util.h"
#include "fps.h"

class Player {
private:
	static const int kPlayerImgNum = 4;
	int player_img_[kPlayerImgNum];
	int x_;
	int y_;
	int player_img_cnt_;
	int cnt_;
public:
	Player();
	~Player();
	void Initialize();
	void Finalize();
	void Update(int *x, int *y);//xy�͌��݂̃v���C���[���S�ʒu���i�[���鐮���|�C���^
	void Draw()const;

	const int kPlayerRadius;//�v���C���[�̔��a
};

#endif