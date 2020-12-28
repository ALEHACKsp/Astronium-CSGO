#include "Helpers/InterfaceManager.hpp"

#include "Platform/EntryPoint.hpp"
#include "Platform/Console.hpp"

#include <Windows.h>

int main() {
	g_pConsole->Init();
	g_pInterfaceManager->Init();

	while(!GetAsyncKeyState(VK_DELETE));

	g_pConsole->Shutdown();
	Unload(0);
}