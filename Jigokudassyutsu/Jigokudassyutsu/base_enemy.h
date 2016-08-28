#ifndef JIGOKUDASSYUTSU_ENEMY_BASEENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_BASEENEMY_H_

#include <string>
#include "DxLib.h"
#include "task.h"
#include "util.h"

class BaseEnemy {
private:
	int img_handle_;//�G�摜�n���h��
	int cnt_;		//�o�����Ă���̃t���[����
protected:
	float x_, y_;
	float speed_;
	float radius_;

	void Initialize();//�R���X�g���N�^����Ăяo���̂�protected�ɒu��
public:
	//�R���X�g���N�^�A�f�X�g���N�^
	BaseEnemy(std::string img_pass);
	BaseEnemy(int img_handle);
	virtual ~BaseEnemy();
	void Finalize();
	//task
	void Count() { cnt_++; }//����Ăяo��
	virtual void Update(int player_x, int player_y, int cnt) = 0;//�ړ��v�Z�͔h���N���X�Œ�`
	void Draw()const;
	//���̑�
	int get_cnt_() { return cnt_; }//���݂̃t���[�����擾
	bool IsCollision(float px, float py, float pr);//�v���C���[�ƐڐG���Ă����true��Ԃ�
};

#endif