#ifndef JIGOKUDASSYUTSU_UTIL_UTIL_H_
#define JIGOKUDASSYUTSU_UTIL_UTIL_H_

#include <stdio.h>
#include <string>


namespace util {
	//エラー出力
	//util::ErrorOutPut(__FILE__, __func__, __LINE__, "エラーメッセージ");の形で呼び出してください
	void ErrorOutPut(const char file[], const char func[], int line, const char message[]);

	//エラー出力(c++版)
	//util::ErrorOutPut(__FILE__, __func__, __LINE__, "エラーメッセージ");の形で呼び出してください
	void ErrorOutPut(const char file[], const char func[], int line, std::string message);
}

#endif