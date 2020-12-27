#include <Windows.h>
#include <cstdio>

HMODULE g_hModule = NULL;

int main();

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
	if(dwReason == DLL_PROCESS_ATTACH) {
		g_hModule = hModule;
		DisableThreadLibraryCalls(hModule);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, 0, 0, 0);
	}

	return TRUE;
}

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

	FreeLibraryAndExitThread(g_hModule, 0);
}