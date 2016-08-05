#ifndef JIGOKUDASSYUTSU_UTIL_UTIL_H_
#define JIGOKUDASSYUTSU_UTIL_UTIL_H_

#include <iostream>
#include <string>


namespace util {
	//エラー出力
	//util::ErrorOutPut(__FILE__, __func__, __LINE__, "エラーメッセージ");の形で呼び出してください
	void ErrorOutPut(const std::string file, const std::string func, int line, const std::string message);
}

#endif