#ifdef _WIN32

#include "../Memory.hpp"

#include <Windows.h>

#include <cassert>

unsigned long SetMemoryProtection(const void* pAddress, size_t nSize, bool bProtect, unsigned long uNewProtect) {
	assert(pAddress != nullptr);

	unsigned long uOldProtect;

	if (bProtect) {
		VirtualProtect(pAddress, nSize, uNewProtect, &uOldProtect);
	} else {
		VirtualProtect(pAddress, nSize, PAGE_EXECUTE_READWRITE, &uOldProtect);
	}
	
	return uOldProtect;
}

#endif