#ifdef _WIN32

#include "../Console.hpp"

#include <Windows.h>

#include <cstdio>

void Console::Init(const char* szTitle) {
#ifndef _RELEASE
	AllocConsole();
	SetConsoleTitle(szTitle);

	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
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

Console* g_pConsole = new Console();

#endif