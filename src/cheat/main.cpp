#include "Helpers/InterfaceManager.hpp"

#include "Platform/EntryPoint.hpp"
#include "Platform/Console.hpp"

#include "SDK/Interfaces/IInputSystem.hpp"

int main() {
	g_pConsole->Init();
	g_pInterfaceManager->Init();

	while(!g_pInputSystem->IsButtonDown(KEY_DELETE));

	g_pConsole->Shutdown();
	Unload(0);
}