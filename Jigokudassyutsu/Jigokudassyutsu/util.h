#ifndef JIGOKUDASSYUTSU_UTIL_UTIL_H_
#define JIGOKUDASSYUTSU_UTIL_UTIL_H_

#include <iostream>
#include <string>


namespace util {
	//�G���[�o��
	//util::ErrorOutPut(__FILE__, __func__, __LINE__, "�G���[���b�Z�[�W");�̌`�ŌĂяo���Ă�������
	void ErrorOutPut(const std::string file, const std::string func, int line, const std::string message);
}

#endif