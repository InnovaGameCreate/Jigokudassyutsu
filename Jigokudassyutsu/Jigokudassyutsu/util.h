#ifndef JIGOKUDASSYUTSU_UTIL_UTIL_H_
#define JIGOKUDASSYUTSU_UTIL_UTIL_H_

#include <stdio.h>


namespace util {
	//エラー出力
	void ErrorOutPut(const char file[], const char func[], int line, const char message[]);
}

#endif