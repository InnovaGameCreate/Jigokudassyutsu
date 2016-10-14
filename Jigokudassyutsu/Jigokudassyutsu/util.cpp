#include "util.h"

namespace {
	bool has_inited_srand = false;
}

namespace util {
	//エラー出力
	void ErrorOutPut(const std::string file, const std::string func, int line, const std::string message) {
		std::cerr << "<file:" << file << '(' << line << ')' << " func:" << func << '>' << std::endl;
		std::cerr << "Error:" << message << std::endl;
	}

	//当たり判定
	bool CircleCollision(double c1_x, double c1_y, double c1_r, double c2_x, double c2_y, double c2_r) {
		double hlength = c1_r + c2_r;
		double xlength = c1_x - c2_x;
		double ylength = c1_y - c2_y;
		if (hlength*hlength >= xlength*xlength + ylength*ylength)
			return true;
		else
			return false;
	}

	bool CirclePointCollision(double cx, double cy, double radius, double px, double py) {
		double d = (cx - px)*(cx - px) + (cy - py)*(cy - py);
		if (d <= radius*radius)
			return true;
		return false;
	}

	//乱数を取得する
	int GetRandom(int min, int max) {
		if (!has_inited_srand) {
			srand((unsigned int)time(NULL));
			has_inited_srand = true;
			rand(); //何故か最初だけ65固定になっていたのでここで一度呼び出しておく
		}
		return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
	}
}