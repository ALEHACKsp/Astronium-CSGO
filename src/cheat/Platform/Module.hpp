#ifndef MODULE_HPP
#define MODULE_HPP

bool IsModuleLoaded(const char* szModuleName);

unsigned long GetModuleBaseAddress(const char* szModuleName);

unsigned long GetModuleMemoryLength(const char* szModuleName);

unsigned long GetSymbolLocation(const char* szModuleName, const char* szSymbolName);

#endif