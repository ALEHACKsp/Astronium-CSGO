#include "Platform/EntryPoint.hpp"

#include <Windows.h>
#include <cstdio>

int main() {
	AllocConsole();
	SetConsoleTitle("Astronium-Debug");

	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);

	printf("Hello World!\n");

	while(!GetAsyncKeyState(VK_DELETE));

	fclose(stdout);
	fclose(stdin);

	FreeConsole();
	SetConsoleCtrlHandler(NULL, TRUE);

	Unload(0);
}