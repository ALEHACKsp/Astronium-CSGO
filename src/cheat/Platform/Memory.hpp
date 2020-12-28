#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cinttypes>

unsigned long SetMemoryProtection(void* pAddress, size_t nSize, bool bProtect, unsigned long uNewProtect = 0);

#endif