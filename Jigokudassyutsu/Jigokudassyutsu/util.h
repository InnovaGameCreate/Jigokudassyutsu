#ifndef JIGOKUDASSYUTSU_UTIL_UTIL_H_
#define JIGOKUDASSYUTSU_UTIL_UTIL_H_

#include <stdio.h>


namespace util {
	//�G���[�o��
	//util::ErrorOutPut(__FILE__, __func__, __LINE__, "�G���[���b�Z�[�W");�̌`�ŌĂяo���Ă�������
	void ErrorOutPut(const char file[], const char func[], int line, const char message[]);
}

#endif