#ifdef _WIN32

#include "../EntryPoint.hpp"

#include <Windows.h>

HMODULE g_hModule = NULL;

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
	if(dwReason == DLL_PROCESS_ATTACH) {
		g_hModule = hModule;
		DisableThreadLibraryCalls(hModule);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, 0, 0, 0);
	}

	return TRUE;
}

void Unload(int nExitCode) {
	FreeLibraryAndExitThread(g_hModule, nExitCode);
}

#endif