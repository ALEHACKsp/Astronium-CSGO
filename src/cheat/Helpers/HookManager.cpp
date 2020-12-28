#include "HookManager.hpp"

#include "../Hooks/PollInputState.hpp"

#include "../Platform/Console.hpp"
#include "../Platform/Memory.hpp"

#include "../SDK/Interfaces/IInputSystem.hpp"

#include <cassert>
#include <cstring>

void HookManager::Init() {
	g_pConsole->Log(LogLevel_t::INFO, XOR("Initializing HookManager...\n"));

	oPollInputState = (PollInputState_t)HookFunction(g_pInputSystem, 13, &hkPollInputState);

	g_pConsole->Log(LogLevel_t::INFO, XOR("Initialized HookManager!\n"));
}

void HookManager::Shutdown() {
	g_pConsole->Log(LogLevel_t::INFO, XOR("Shutting down HookManager...\n"));

	HookFunction(g_pInputSystem, 13, oPollInputState);

	g_pConsole->Log(LogLevel_t::INFO, XOR("Shut down HookManager!n"));
}

void* HookManager::HookFunction(void* pClass, int nIndex, void* pHookFunction) {
	assert(pClass != nullptr);
	assert(nIndex >= 0);
	assert(pHookFunction != nullptr);

	void** pVTable = *(void***)pClass;
	void* pFunction = pVTable + nIndex;
	void* pOriginalFunction = pVTable[nIndex];
	
	unsigned long ulOldMemoryProtection = SetMemoryProtection(pFunction, sizeof(void*), false);
	memcpy(pFunction, &pHookFunction, sizeof(void*));
	SetMemoryProtection(pFunction, sizeof(void*), true, ulOldMemoryProtection);

	g_pConsole->Log(LogLevel_t::DEBUG, XOR("Hooked function 0x%p (0x%p[%i]): 0x%p -> 0x%p\n"), pFunction, pClass, nIndex, pOriginalFunction, pHookFunction);

	return pOriginalFunction;
}

HookManager* g_pHookManager = new HookManager();