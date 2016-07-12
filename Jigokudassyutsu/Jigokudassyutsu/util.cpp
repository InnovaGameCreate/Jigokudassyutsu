#include "util.h"

namespace util {
	//エラー出力
	void ErrorOutPut(const char file[], const char func[], int line,
		const char message[]) {
		fprintf(stderr, "<file:%s func:%s line:%d>\n", file, func, line);
		fprintf(stderr, "Error:%s\n\n", message);
	}
}