#include "Helpers/InterfaceManager.hpp"
#include "Helpers/HookManager.hpp"

#include "Platform/EntryPoint.hpp"
#include "Platform/Console.hpp"

#include "SDK/Interfaces/IInputSystem.hpp"

int main() {
	g_pConsole->Init();
	g_pInterfaceManager->Init();
	g_pHookManager->Init();

	lk = std::unique_lock<std::mutex>(m);
	cv.wait(lk);

	g_pHookManager->Shutdown();
	g_pConsole->Shutdown();
	Unload(0);
}