#ifndef JIGOKUDASSYUTSU_UTIL_UTIL_H_
#define JIGOKUDASSYUTSU_UTIL_UTIL_H_

#include <iostream>
#include <string>


namespace util {
	//�G���[�o��
	//util::ErrorOutPut(__FILE__, __func__, __LINE__, "�G���[���b�Z�[�W");�̌`�ŌĂяo���Ă�������
	void ErrorOutPut(const std::string file, const std::string func, int line, const std::string message);

	//�~�Ɖ~�̓����蔻��
	bool CircleCollision(double c1_x, double c1_y, double c1_r, double c2_x, double c2_y, double c2_r);
	//�~�ƓV�̂����蔻��
	bool CirclePointCollision(double cx, double cy, double radius, double px, double py);
}

#endif