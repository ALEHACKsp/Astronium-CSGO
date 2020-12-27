#ifndef CONSOLE_HPP
#define CONSOLE_HPP

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
	void Init(const char* szTitle = "Astronium-Debug");
	void Shutdown();
};

extern Console* g_pConsole;

#endif