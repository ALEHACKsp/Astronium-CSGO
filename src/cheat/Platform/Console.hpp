#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "../Helpers/XorStr.hpp"

enum class LogLevel_t {
	NONE = 0,
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	LOG_LEVEL_SIZE
};

class Console {
public:
	void Init(const char* szTitle = XOR("Astronium-Debug"));
	void Shutdown();
	void Log(LogLevel_t nLogLevel, const char* szFormat, ...);
};

extern Console* g_pConsole;

#endif