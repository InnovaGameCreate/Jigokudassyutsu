#ifndef JIGOKUDASSYUTSU_COLLISION_COLLISION_H_
#define JIGOKUDASSYUTSU_COLLISION_COLLISION_H_

#include "DxLib.h"
#include "task.h"
#include "util.h"
#include <iostream>
#include <fstream>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

class CollisionRoad {
private:
	const int kStageNum;	//�X�e�[�W�i���o�[
	const int kMapWidth;	//�}�b�v�̉��s�N�Z����
	const int kMapHeight;	//�}�b�v�̏c�s�N�Z����
	cv::Mat col_map_;		//�����蔻��p�̉摜�̃f�[�^

	inline bool IsColMapAlpha(int x, int y);//x,y�̈ʒu�������蔻��摜�œ��ߕ����Ȃ�true��Ԃ�

public:
	CollisionRoad(int stage_num, int map_width, int map_height);
	~CollisionRoad();
	void Initialize();
	void Finalize();
	//������͂ݏo���Ă��鎞true��Ԃ�
	//�����̓v���C���[���W�Ɣ��a
	bool Update(float x, float y, float radius);
	void Draw()const;
};

#endif