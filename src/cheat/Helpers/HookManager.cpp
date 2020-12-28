#include "HookManager.hpp"

#include "../Platform/Memory.hpp"

#include "../SDK/Interfaces/IInputSystem.hpp"

#include <cassert>
#include <cstring>

void HookManager::Init() {
	
}

void HookManager::Shutdown() {

}

void* HookManager::HookFunction(void* pClass, int nIndex, void* pHookFunction) {
	assert(pClass != nullptr);
	assert(nIndex >= 0);
	assert(pHookFunction != nullptr);

	void** pVTable = *(void***)pClass;
	void* pFunction = pVTable + nIndex;
	void* pOriginalFunction = pVTable[nIndex];
	
	unsigned long ulOldMemoryProtection = SetMemoryProtection(pFunction, sizeof(void*), false);
	memcpy(pFunction, pHookFunction, sizeof(void*));
	SetMemoryProtection(pFunction, sizeof(void*), true, ulOldMemoryProtection);

	return pOriginalFunction;
}

HookManager* g_pHookManager = new HookManager();