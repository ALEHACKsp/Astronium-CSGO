#ifdef _WIN32

#include "../Module.hpp"

#include <Windows.h>
#include <Psapi.h>

#include <cassert>

bool IsModuleLoaded(const char* szModuleName) {
	return (GetModuleHandle(szModuleName) != 0);
}

unsigned long GetModuleBaseAddress(const char* szModuleName) {
	assert(IsModuleLoaded(szModuleName));

	return (unsigned long)GetModuleHandle(szModuleName);
}

unsigned long GetModuleMemoryLength(const char* szModuleName) {
	/*assert(IsModuleLoaded(szModuleName));

	static HANDLE hCurrentProcess = GetCurrentProcess();

	MODULEINFO info;
	GetModuleInformation(hCurrentProcess, GetModuleHandle(szModuleName), &info, sizeof(MODULEINFO));

	return info.SizeOfImage;*/
	return 0;
}

unsigned long GetSymbolLocation(const char* szModuleName, const char* szSymbolName) {
	assert(IsModuleLoaded(szModuleName));

	return (unsigned long)GetProcAddress(GetModuleHandle(szModuleName), szSymbolName);
}

#endif