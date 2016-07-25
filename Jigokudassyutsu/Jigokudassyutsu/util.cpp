#include "util.h"

namespace util {
	//�G���[�o��
	void ErrorOutPut(const std::string file, const std::string func, int line, const std::string message) {
		std::cerr << "<file:" << file << '(' << line << ')' << " func:" << func << '>' << std::endl;
		std::cerr << "Error:" << message << std::endl;
	}
}