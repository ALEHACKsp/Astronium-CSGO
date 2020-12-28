#ifdef _WIN32

#include "../Console.hpp"

#include <Windows.h>

#include <cassert>
#include <cstdio>

void Console::Init(const char* szTitle) {
#ifndef _RELEASE
	AllocConsole();
	SetConsoleTitle(szTitle);

	freopen(XOR("CONOUT$"), XOR("w"), stdout);
	freopen(XOR("CONIN$"), XOR("r"), stdin);
#endif
}

void Console::Shutdown() {
#ifndef _RELEASE
	fclose(stdout);
	fclose(stdin);

	FreeConsole();
	SetConsoleCtrlHandler(NULL, TRUE);
#endif
}

void Console::Log(LogLevel_t nLogLevel, const char* szFormat, ...) {
	assert((int)nLogLevel >= 0);
	assert(nLogLevel < LogLevel_t::LOG_LEVEL_SIZE);

	static const char* s_pLogLevelPrefixes[] = {
		"",
		"[DEBUG] ",
		"[INFO] ",
		"[WARNING] ",
		"[ERROR] "
	};

	const char* szLogLevelPrefix = s_pLogLevelPrefixes[(int)nLogLevel];
	printf(XOR("%s"), szLogLevelPrefix);

	va_list argList;
	va_start(argList, szFormat);

	vprintf(szFormat, argList);

	va_end(argList);
}

Console* g_pConsole = new Console();

#endif