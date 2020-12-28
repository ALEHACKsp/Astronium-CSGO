#ifndef INTERFACEMANAGER_HPP
#define INTERFACEMANAGER_HPP

#include "../SDK/Misc/Interface.hpp"

class InterfaceManager {
public:
	void Init();
private:
	void* GetInterface(const char* szModuleName, const char* szInterfaceName);
	InterfaceReg* GetInterfaceReg(const char* szModuleName);
};

extern InterfaceManager* g_pInterfaceManager;

#endif