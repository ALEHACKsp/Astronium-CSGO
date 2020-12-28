#include "Platform/EntryPoint.hpp"
#include "Platform/Console.hpp"

#include <Windows.h>
#include <cstdio>

int main() {
	g_pConsole->Init();

	while(!GetAsyncKeyState(VK_DELETE));

	g_pConsole->Shutdown();
	Unload(0);
}