#ifndef JIGOKUDASSYUTSU_UTIL_UTIL_H_
#define JIGOKUDASSYUTSU_UTIL_UTIL_H_

#include <iostream>
#include <string>


namespace util {
	//エラー出力
	//util::ErrorOutPut(__FILE__, __func__, __LINE__, "エラーメッセージ");の形で呼び出してください
	void ErrorOutPut(const std::string file, const std::string func, int line, const std::string message);

	//円と円の当たり判定
	bool CircleCollision(double c1_x, double c1_y, double c1_r, double c2_x, double c2_y, double c2_r);
	//円と天のあたり判定
	bool CirclePointCollision(double cx, double cy, double radius, double px, double py);
}

#endif