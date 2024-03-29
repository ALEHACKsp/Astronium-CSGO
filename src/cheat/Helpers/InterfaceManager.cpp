#include "InterfaceManager.hpp"

#include "XorStr.hpp"

#include "../Platform/Console.hpp"
#include "../Platform/Module.hpp"

#include "../SDK/Interfaces/IInputSystem.hpp"

#include <cstring>
#include <unordered_map>

std::unordered_map<std::string, InterfaceReg*> m_pInterfaceRegs;

void InterfaceManager::Init() {
	g_pConsole->Log(LogLevel_t::INFO, XOR("Initializing InterfaceManager...\n"));

	g_pInputSystem = (IInputSystem*)GetInterface(XOR("inputsystem"), XOR("InputSystemVersion"));

	g_pConsole->Log(LogLevel_t::INFO, XOR("Initialized InterfaceManager!\n"));
}

void InterfaceManager::Dump(const char* szModuleName) {
	if(!m_pInterfaceRegs[szModuleName]) m_pInterfaceRegs[szModuleName] = GetInterfaceReg(szModuleName);

	for(InterfaceReg* pCurrent = m_pInterfaceRegs[szModuleName]; pCurrent; pCurrent = pCurrent->m_pNext) {
		g_pConsole->Log(LogLevel_t::NONE, XOR("%s: 0x%p\n"), pCurrent->m_pName, pCurrent->m_CreateFn());
	}
}

void* InterfaceManager::GetInterface(const char* szModuleName, const char* szInterfaceName) {
	if(!m_pInterfaceRegs[szModuleName]) m_pInterfaceRegs[szModuleName] = GetInterfaceReg(szModuleName);

	for(InterfaceReg* pCurrent = m_pInterfaceRegs[szModuleName]; pCurrent; pCurrent = pCurrent->m_pNext) {
		if(strncmp(pCurrent->m_pName, szInterfaceName, strlen(szInterfaceName)) == 0 && strlen(pCurrent->m_pName) - strlen(szInterfaceName) <= 3) {
			g_pConsole->Log(LogLevel_t::DEBUG, XOR("%s: 0x%p\n"), pCurrent->m_pName, pCurrent->m_CreateFn());
			return pCurrent->m_CreateFn();
		}
	}

	return nullptr;
}

InterfaceReg* InterfaceManager::GetInterfaceReg(const char* szModuleName) {
	unsigned long ulInterfaceRegs = GetSymbolLocation(szModuleName, XOR("s_pInterfaceRegs"));
	if(ulInterfaceRegs != 0) return *(InterfaceReg**)(ulInterfaceRegs);

	unsigned long ulCreateInterfaceAddress = GetSymbolLocation(szModuleName, XOR("CreateInterface"));
	unsigned long ulJumpInstructionAddress = ulCreateInterfaceAddress + 4;
	unsigned long ulJumpDisplacement = *(unsigned long*)(ulJumpInstructionAddress + 1);
	unsigned long ulCreateInterfaceInternalAddress = (ulJumpInstructionAddress + 5) + ulJumpDisplacement;
	unsigned long ulInterfaceRegPointer = *(unsigned int*)(ulCreateInterfaceInternalAddress + 6);

	return *(InterfaceReg**)(ulInterfaceRegPointer);
}

InterfaceManager* g_pInterfaceManager = new InterfaceManager();