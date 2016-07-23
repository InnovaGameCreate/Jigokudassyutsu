#include "util.h"

namespace util {
	//ƒGƒ‰[o—Í
	void ErrorOutPut(const char file[], const char func[], int line,
		const char message[]) {
		fprintf(stderr, "<file:%s func:%s line:%d>\n", file, func, line);
		fprintf(stderr, "Error:%s\n\n", message);
	}

	void ErrorOutPut(const char file[], const char func[], int line, std::string message) {
		fprintf(stderr, "<file:%s func:%s line:%d>\n", file, func, line);
		fprintf(stderr, "Error:%s\n\n", message.c_str());
	}
}