#ifndef MEMORY_HPP
#define MEMORY_HPP

unsigned long SetMemoryProtection(void* pAddress, size_t nSize, bool bProtect, unsigned long uNewProtect);

#endif